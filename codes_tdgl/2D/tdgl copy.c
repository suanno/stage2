#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//#include </opt/intel/composer_xe_2013_sp1.3.174/mkl/include/fftw/fftw3.h>
#include <fftw3.h>
#include <math.h>
#define N 10

#define pi  4*atan(1.0)
int main(){




double h[N][N];
double hfr[N][N];
double hfi[N][N];
double hdt[N][N];
double hdtfr[N][N];
double hdtfi[N][N];
double coeffr[N][N];
double hc[N][N]; // h^3
double hcfr[N][N];
double hcfi[N][N];
double q2[N][N]; // qx^2 + qy^2

double lapfrcoef[N][N];
double integ_coef[N][N];

//static double areaar[N][N];
//static double Aarr[N][N];
//static double Barr[N][N];
//static double Carr[N][N];

//double A;
//double B;
//double C;

double ffr[N];
double qfr[N];
double dx=0.1;
double L=N*dx; // data for x is 0 to L
double z;
double Hm2=1;
int i;
int j;
int k;

double deca;
double decaoutq2mean=0.0;

double q2meannum=0.0;
double q2meandenom=0.0;

int loop;
double dt=0.01; // note: stable upto dt=0.6
int Nst=8;
double savetimes[8]={1,2,3,4,4000,6000,8000,10000};
double time;
double tmin=0;
double tmax=10000;
int loops=(tmax-tmin)/dt;
double q2mean[loops];
static double q2meannumar[N][N];
static double q2meandenomar[N][N];

int q2loop=0;
double qtime=0.0;

double* C = malloc(loops*sizeof(double));
double Thalf = 0.5;
double Ampl = 1;
for (loop=0;loop<loops;loop++){
    time = tmin + (loop+1)*dt;
    if(Thalf > 0){
        C[loop]=sin(pi*time/Thalf);
        /*printf("\nC[t = %.2lf] = %.4lf", time, C[loop]);*/
        C[loop] = Ampl*C[loop];
    }else
        C[loop] = Ampl;
}
double* Ave = malloc(loops*sizeof(double));

/*
for (loop=0;loop<loops;loop++){
time = tmin + (loop + 1)*dt;		/*C[loop] = C(t+dt), so it's NOT C(t)
if(Thalf > 0){
	C[loop]=Ampl*sin(pi*time/Thalf);
	}
	else	/*Thalf < 0 means you want to keep C costant
		C[loop] = Ampl;
}
*/

FILE *fileinit;
FILE *filenonconserve2dh;
FILE *fileq2mean;
FILE *fileAveout;

char filename[16];

// initialize threads for fft
fftw_init_threads();

fftw_complex *in, *out;
fftw_plan pf, pb;
in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N*N);
out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N*N);
// create plans with threads
fftw_plan_with_nthreads(omp_get_max_threads());
// plan for forward transform
pf = fftw_plan_dft_2d(N,N,in,out,FFTW_FORWARD,FFTW_ESTIMATE);
// pf = fftw_plan_dft_r2c_2d(N,N,in,out,FFTW_ESTIMATE);
// plan for backward transform
pb = fftw_plan_dft_2d(N,N,in,out,FFTW_BACKWARD,FFTW_ESTIMATE);
// pb = fftw_plan_dft_c2r_2d(N,N,in,out,FFTW_ESTIMATE);
//TUNG: end of adding variables for fft

for (i=1; i<(N/2); i++){
ffr[i]=i;
ffr[N-i]=-i;
}
ffr[0]=0;
ffr[N/2]=N/2;
for (i=0; i<N; i++){
qfr[i]=ffr[i]*2*pi/N;
}


fileinit = fopen("fileinit.dat", "r");
for (i=0; i<N; i++){
for (j=0; j<N; j++){
fscanf(fileinit, "%lf\n", &z);
h[i][j]=z;
/*printf("u[%d][%d] = %.2lf\n", i, j, h[i][j]);*/
}
}


fclose(fileinit);

// coefficients for implicit scheme
for (i=0; i<N; i++){
for (j=0; j<N; j++){
q2[i][j]=(qfr[i]*qfr[i]+qfr[j]*qfr[j]);
lapfrcoef[i][j]=-(qfr[i]*qfr[i]+qfr[j]*qfr[j])/(dx*dx);
}
}

//------------------------------------------

for(loop=0;loop<loops;loop++) {

    time = (loop+1)*dt+tmin;
    /*
    printf("\n\nTime: %.2lf\n", time-dt);
    printf("h[%d][%d]*dt = %.2lf\n", i, j, h[i][j]);
    */
    for (i=0; i<N; i++){
    for (j=0; j<N; j++){
    integ_coef[i][j]=1-dt*C[loop]-dt*lapfrcoef[i][j];
    }
    }

    // inside big loops
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0; i<N; i++) {
    for(j=0; j<N; j++) {
    hc[i][j] = h[i][j]*h[i][j]*h[i][j];
    }
    }

    // h to hfr, hfi
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = h[i][j];
    in[i*N+j][1] = 0.0;
    }
    }
    // backward transform
    fftw_execute(pf);
    // copy output vector
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    hfr[i][j] = out[i*N+j][0];
    hfi[i][j] = out[i*N+j][1];
    }
    }

    // hc to hcfr, hcfi
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = hc[i][j];
    in[i*N+j][1] = 0.0;
    }
    }
    // backward transform
    fftw_execute(pf);
    // copy output vector
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    hcfr[i][j] = out[i*N+j][0];
    hcfi[i][j] = out[i*N+j][1];
    }
    }

    // implicit scheme
    //#pragma omp parallel for //seulement pour les grands systèmes
    for (i=0; i<N; i++){
    for (j=0; j<N; j++){
    //if(lapfrcoef[i][j] != 0.0) {
    hdtfr[i][j] = (hfr[i][j]-dt*hcfr[i][j])/integ_coef[i][j];
    hdtfi[i][j] = (hfi[i][j]-dt*hcfi[i][j])/integ_coef[i][j];
    //}
    }
    }

    // initialize input vector in for backward transform
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    in[i*N+j][0] = hdtfr[i][j];
    in[i*N+j][1] = hdtfi[i][j];
    }
    }
    // backward transform
    fftw_execute(pb);
    // copy output vector
    //#pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    hdt[i][j] = out[i*N+j][0]/(N*N);
    }
    }

    //#pragma omp parallel for //seulement pour les grands systèmes
    Ave[loop] = 0;
    for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
    h[i][j] = hdt[i][j];
    Ave[loop] = Ave[loop] + h[i][j];
    //printf("u[%d][%d] = %.2lf\n", i, j, h[i][j]);
    }
    }
    Ave[loop] = Ave[loop]/(N*N);
    //if(fmod(time,15.) ==0) {
    //printf("%.1f\n", time);
    //}

    //if(fmod(time,3000.) ==0) {
    //sprintf( filename, "file%.0f.dat", time );  
    //filenonconserve2dh = fopen(filename, "w");
    //filenonconserve2dh = fopen("nonconserve2dh.dat", "w");
    //for(i=0;i<N;i++) {
    //for(j=0;j<N;j++) {
    //deca=hdt[i][j];
    //fprintf(filenonconserve2dh, "%.20f\n", deca);
    //}
    //}
    //fclose(filenonconserve2dh);
    //}

}
/*Save values of Space average in different times*/
double decaoutC;
fileAveout = fopen("fileAveout.dat", "a");
for (loop=0; loop<loops; loop++){
time = tmin + (loop+1)*dt;
decaoutC = Ave[loop];
fprintf(fileAveout, "%.5f %.20f\n", time, decaoutC);
}
fclose(fileAveout);

//------------------------------------------

fftw_destroy_plan(pf);
fftw_destroy_plan(pb);
fftw_free(in);
fftw_free(out);
// clean up threads
fftw_cleanup_threads();
return 0;
}

