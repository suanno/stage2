/*
Finite difference numerical solver for the TDGL equation.
Change the interface with W and position of potential well Hm2 to control the excess area.
Author: Tung B. T. To.
Date: July 25 2016.
*/

// include header files
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#define N 2

#define pi  4*atan(1.0) // the constant pi

int main(){

double W=1;// interface width
double Hm2=1; // position of potential well (=0.7)

//int N=2500; // size of simulation grid
static double h[N][N]; // membrane height at current time t
static double hdt[N][N]; // membrane height at next time t+dt
static double hp[N+2][N+2]; // membrane height at current time t with periodic points

static double dx1h[N][N]; // dh/dx
static double dy1h[N][N]; // dh/dy
static double laph[N][N]; // laplacian of h

static double dU[N][N]; // dU/dh
static double hc[N][N]; // h^3
static double Lh[N][N]; // combination of terms to be used in the finite difference scheme
static double areaar[N][N]; // local area

double L=1000; // system length
double dx=L/N; // grid spacing along dx

// some temporary variables
double z;
double deca;
int i;
int j;

// coefficients for the derivatives
double d1coef=0.5/dx;
double d2coef=1.0/(dx*dx);

int loop; // refer to the current time loop
double dt=0.01; // note: stable upto dt=0.01
double time; // refer to the current time
double tmin=0; // starting time of the simulation, this should be consistent with the initial condition file
double tmax=10000; // ending time of the simulation
double area; // membrane excess area
int loops=(tmax-tmin)/dt; // total number of loops

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

// data files
FILE *fileinit; // initial condition
FILE *filenonconserve2d; // save current result data
FILE *fileAveout;    // save space averages at every time
FILE *filearea;

char filename[16]; // filename to save current result data

// read initial condition, this filename should be consistent with the variable tmin
fileinit = fopen("file0.dat", "r");
for (i=0; i<N; i++){
for (j=0; j<N; j++){
fscanf(fileinit, "%lf\n", &z);
h[i][j]=z;
}
}

fclose(fileinit);

//------------------------------------------

for(loop=0;loop<loops;loop++) {

time = (loop+1)*dt+tmin;

// calculating terms to be used in the finite difference scheme
#pragma omp parallel for
for(i=0; i<N; i++) {
for(j=0; j<N; j++) {
hp[i+1][j+1] = h[i][j];
dU[i][j]=h[i][j]*h[i][j]*h[i][j]-C[loop]*Hm2*h[i][j];
}
}

#pragma omp parallel for
for(j=0; j<N; j++) {
hp[0][j+1] = hp[N][j+1];
hp[N+1][j+1] = hp[1][j+1];
}

#pragma omp parallel for
for(i=0; i<N; i++) {
hp[i+1][0] = hp[i+1][N];
hp[i+1][N+1] = hp[i+1][1];
}

#pragma omp parallel for
for(i=1; i<N+1; i++) {
for(j=1; j<N+1; j++) {
dx1h[i-1][j-1]=d1coef*(hp[i+1][j]-hp[i-1][j]);
dy1h[i-1][j-1]=d1coef*(hp[i][j+1]-hp[i][j-1]);
laph[i-1][j-1]=d2coef*(hp[i+1][j]+hp[i-1][j]-2*hp[i][j]+hp[i][j+1]+hp[i][j-1]-2*hp[i][j]);
}
}

// finite difference scheme
#pragma omp parallel for
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
Lh[i][j] = W*W*laph[i][j]-dU[i][j];
hdt[i][j] = h[i][j]+dt*Lh[i][j];
}
}

// copy hdt to h
#pragma omp parallel for
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
h[i][j] = hdt[i][j];
}
}
/*Space average*/
Ave[loop] = 0;
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
    Ave[loop] = Ave[loop] + h[i][j];
}}
Ave[loop] = Ave[loop]/(N*N);

// calculate area
#pragma omp parallel for
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
areaar[i][j] = dx1h[i][j]*dx1h[i][j]+dy1h[i][j]*dy1h[i][j];
}
}
area=0.;

for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
area = area + areaar[i][j];
}
}
area = 0.5*area*dx*dx/(L*L);

// print result onto screen to check for accuracy
//if(fmod(time,1.) ==0) { // change the input x inside fmod(time,x) for the frequency to print results onto screen
//printf("%.5f\n", time);
//printf("%.20f\n", area);
//}

//if(loops%10)
//printf("%.5f\n", time);

// print results at a regular interval of loops or time
//if(fmod(time,1.) ==0) {
//sprintf( filename, "file%.0f.dat", time );
//filenonconserve2d = fopen("file1.dat", "w");
//for(i=0;i<N;i++) {
//for(j=0;j<N;j++) {
//deca=hdt[i][j];
//fprintf(filenonconserve2d, "%.20f\n", deca);
//}
//}
//fclose(filenonconserve2d);
//}

}

filenonconserve2d = fopen("file1.dat", "w");
for(i=0;i<N;i++) {
for(j=0;j<N;j++) {
deca=hdt[i][j];
fprintf(filenonconserve2d, "%.20f\n", deca);
}
}
fclose(filenonconserve2d);

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

return 0;
}

