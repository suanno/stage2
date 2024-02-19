/*
Numerical solver for the TDGL equation.
This program uses the first order exponential time differencing (ETD1) numerical scheme described in Cox and Mathew.
Use the initial condition generated from finite difference method.
Author: Tung B. T. To.
Date: July 25 2016.
*/

// include header files
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>
#include "fftw3.h" // NOTE: place the file "fftw3.h" in the same directory with this program

#define N 4
#define pi  4*atan(1.0) // the constant pi
int main(){

double L=200; // data for x is 0 to L
// well of adhesion potential
/*double Hm2=0.49; // hm=0.7*/
static double h[N][N]; // membrane height at current time t
static double hfr[N][N]; // Re(fft(h))
static double hfi[N][N]; // Im(fft(h))
static double hdt[N][N]; // membrane height at next time t+dt
static double hdtfr[N][N];
static double hdtfi[N][N];
static double hc[N][N]; // h^3
static double hcfr[N][N];
static double hcfi[N][N];
static double q2[N][N]; // qx^2 + qy^2

static double dU[N][N]; // dU/dh
static double dUfr[N][N];
static double dUfi[N][N];

// some coefficients to be used for the calculations in the Fourier space
static double lapfrcoef[N][N];
static double explapfrcoef[N][N];
static double expdvlap[N][N];

// local excess area
static double areaar[N][N];

double ffr[N]; // frequency
double qfr[N]; // angular frequency
double dx=L/N; // dx, typically we choose dx=0.4

// some temporary variables to be used in the simulation
double z;
double deca;
int i;
int j;
int k;

double area; // membrane excess area
double havrg; // average height

int loop; // refer to the current time loop
double dt=0.01;
int Nst=8; // total number of times to save result data
double savetimes[8]={15,30,60,120,240,480,960,1920}; // times to save result data
double time; // refer to the current time
double tmin=0; // starting time of the simulation, this should be consistent with the initial condition file
double tmax=10000; // ending time of the simulation
int loops=(tmax-tmin)/dt; // total number of loops
printf("Loops: %d",loops);

// data files
FILE *fileinit; // initial condition
FILE *filenonconserve2dh; // save current result data
FILE *fileareadat;
FILE *filehavrgdat;
FILE* fileAveout;

char filename[16]; // filename to save current result data

double* C = malloc(loops*sizeof(double));
double Thalf = 0.5;
double Ampl = 1;
for (loop=0;loop<loops;loop++){
    time = tmin + (loop)*dt;    /*In ETD we use C(t) NOT C(t+dt)*/
    if(Thalf > 0){
        C[loop]=sin(pi*time/Thalf);
        /*printf("\nC[t = %.2lf] = %.4lf", time, C[loop]);*/
        C[loop] = Ampl*C[loop];
    }else
        C[loop] = Ampl;
}
double* Ave = malloc(loops*sizeof(double));


// initialize threads and variables for fft
fftw_init_threads();

fftw_complex *in, *out;
fftw_plan pf, pb;
in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N*N);
out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N*N);
// create plans with threads
fftw_plan_with_nthreads(omp_get_max_threads());
// plan for forward transform
pf = fftw_plan_dft_2d(N,N,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
// plan for backward transform
pb = fftw_plan_dft_2d(N,N,in,out,FFTW_BACKWARD,FFTW_ESTIMATE);

// frequency and angular frequency
for (i=1; i<(N/2); i++){
ffr[i]=i;
ffr[N-i]=-i;
}
ffr[0]=0;
ffr[N/2]=N/2;
for (i=0; i<N; i++){
qfr[i]=ffr[i]*2*pi/N;
}

// read initial condition, this filename should be consistent with the variable tmin
fileinit = fopen("file0.dat", "r"); // change filename
for (i=0; i<N; i++){
for (j=0; j<N; j++){
fscanf(fileinit, "%lf\n", &z);
h[i][j]=z;
}
}

fclose(fileinit);

// coefficients for ETD1 scheme
for (i=0; i<N; i++){
for (j=0; j<N; j++){
q2[i][j]=(qfr[i]*qfr[i]+qfr[j]*qfr[j]);
lapfrcoef[i][j]=-(qfr[i]*qfr[i]+qfr[j]*qfr[j])/(dx*dx);
explapfrcoef[i][j]=exp(dt*lapfrcoef[i][j]);
expdvlap[i][j]=(explapfrcoef[i][j]-1)/(lapfrcoef[i][j]);
}
}

//------------------------------------------


for(loop=0;loop<loops;loop++) {
    /*printf("Loop: %d", loop);*/
    time = (loop+1)*dt+tmin;

    #pragma omp parallel for
    for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
    hc[i][j] = h[i][j]*h[i][j]*h[i][j];
    dU[i][j] = -C[loop]*h[i][j]+hc[i][j];
    }
    }

    // fft h to hfr, hfi
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = h[i][j];
    in[i*N+j][1] = 0.0;
    }
    }
    // backward transform
    fftw_execute(pf);
    // copy output vector
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    hfr[i][j] = out[i*N+j][0];
    hfi[i][j] = out[i*N+j][1];
    }
    }

    // fft hc to hcfr, hcfi
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = hc[i][j];
    in[i*N+j][1] = 0.0;
    }
    }
    // backward transform
    fftw_execute(pf);
    // copy output vector
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    hcfr[i][j] = out[i*N+j][0];
    hcfi[i][j] = out[i*N+j][1];
    }
    }

    // fft dU to dUfr, dUfi
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = dU[i][j];
    in[i*N+j][1] = 0.0;
    }
    }
    // backward transform
    fftw_execute(pf);
    // copy output vector
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    dUfr[i][j] = out[i*N+j][0];
    dUfi[i][j] = out[i*N+j][1];
    }
    }

    // ETD1 scheme
    #pragma omp parallel for
    for (i=0; i<N; i++){
    for (j=0; j<N; j++){
    if(lapfrcoef[i][j] != 0.0) {
    hdtfr[i][j] = explapfrcoef[i][j]*hfr[i][j]-expdvlap[i][j]*dUfr[i][j];

    hdtfi[i][j] = explapfrcoef[i][j]*hfi[i][j]-expdvlap[i][j]*dUfi[i][j];
    }
    else {
    hdtfr[i][j] = hfr[i][j] + (-dUfr[i][j])*dt;
    hdtfi[i][j] = hfi[i][j] + (-dUfi[i][j])*dt;
    }
    }
    }

    // fft backward to get membrane profile at the next time step
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = hdtfr[i][j];
    in[i*N+j][1] = hdtfi[i][j];
    }
    }
    // backward transform
    fftw_execute(pb);
    // copy output vector
    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    hdt[i][j] = out[i*N+j][0]/(N*N);
    }
    }

    #pragma omp parallel for
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    h[i][j] = hdt[i][j];
    }
    }

    // print result onto screen to check for accuracy
    if(fmod(time,15.) ==0) { // change the input x inside fmod(time,x) for the frequency to print results onto screen
    printf("%.1f\n", time);
    }

    /*Save values of Space average in different times*/

    Ave[loop] = 0;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            h[i][j] = hdt[i][j];
            Ave[loop] = Ave[loop] + h[i][j];
            //printf("u[%d][%d] = %.2lf\n", i, j, h[i][j]);
        }
    }
    Ave[loop] = Ave[loop]/(N*N);
}

double decaoutC;
fileAveout = fopen("fileAveout.dat", "w");
for (loop=0; loop<loops; loop++){
time = tmin + (loop+1)*dt;
decaoutC = Ave[loop];
fprintf(fileAveout, "%.5f %.20f\n", time, decaoutC);
}
fclose(fileAveout);

//------------------------------------------

// clear memory
fftw_destroy_plan(pf);
fftw_destroy_plan(pb);
fftw_free(in);
fftw_free(out);
// clean up threads
fftw_cleanup_threads();
return 0;
}

