//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <fftw3.h>

#define pi  4*atan(1.0)

/*  Generate a flat plot with added a small perturbation.
    The perturbation has the same magnitude eps for every mode q.
*/

//pour générer des nombres aléatoires
double randU(double randmin, double randmax)
{
double randU1=0.;
randU1 = randmin*(1-rand()/(double)RAND_MAX)+randmax*rand()/(double)RAND_MAX;
return randU1;
}

int main(int argc, char  *argv [ ]){

int i;

int N=1000;
double u0;              /*Initial flat value*/
int seed;
double hmoy = 0;
double eps = 0;
double phase = 0;

seed = time(NULL);
srand(seed);

char *ptr;
if (argc > 1)
	N = (int)strtod(argv[1], &ptr);
if (argc > 2)
  	u0 = strtod(argv[2], &ptr);
if (argc > 3)
    eps = strtod(argv[3], &ptr);

double* x = malloc(N*sizeof(double));
double* u = malloc(N*sizeof(double));
double* udt = malloc(N*sizeof(double));
double* ufr = malloc(N*sizeof(double));
double* ufi = malloc(N*sizeof(double));
double* ffr = malloc(N*sizeof(double));
double* qfr = malloc(N*sizeof(double));
double* d2coef = malloc(N*sizeof(double));
double* integ_coef = malloc(N*sizeof(double));

/* TUNG: create plan for FFT*/
fftw_complex *in, *out;
fftw_plan pf,pb;
   
in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
pf = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
pb = fftw_plan_dft_1d(N, in, out, FFTW_BACKWARD, FFTW_ESTIMATE);

/*Define q-space lattice*/
for (i=1; i<(N/2); i++){
ffr[i]=i;
ffr[N-i]=-i;
}
ffr[0]=0;
ffr[N/2]=N/2;	/*N MUST BE EVEN!!!*/
for (i=0; i<N; i++){
qfr[i]=ffr[i]*2*pi/N;
}

for (i=0; i<N; i++){
    u[i] = u0;
}
/*Compute FFT of u(x)->U(q)*/
for(i=0; i<N; i++) {
    in[i][0]=u[i];
	in[i][1]=0.0;
}
fftw_execute(pf); // repeat as needed
for(i=0; i<N; i++) {
    ufr[i]=out[i][0];
	ufi[i]=out[i][1];
}
/*Add perturbation to modes q!=0
    Unphase the modes, otherwise they will interfere bad*/
for(i=1; i<(N/2)-1; i++) {
    phase = randU(0, 2*pi);
    ufr[i] = ufr[i] + eps*N*cos(phase);
	ufi[i] = ufi[i] + eps*N*sin(phase);
    //printf("i = %d, real=%lf; imag=%lf; u=%lf\n", i, ufr[i], ufi[i], u[i]);
}
	/*INVERSE FFT*/
	for(i=0; i<N; i++) {
	in[i][0]=ufr[i];
	in[i][1]=ufi[i];
	}
	fftw_execute(pb); // repeat as needed
	for(i=0; i<N; i++) {
	udt[i]=out[i][0]/N;
	}

	for(i=0; i<N; i++) {
	u[i]=udt[i];
	}


FILE *fileinit;

fileinit = fopen("fileinit.dat", "w");
fprintf(fileinit, "%d %d\n", seed, N);
for (i=0; i<N; i++){
    fprintf(fileinit, "%.20f\n", u[i]);
}

fclose(fileinit);

/*Recreate fileCout of values of C(t) [Progressive
executions of the dynamics will APPEND info]*/
FILE *file;
file = fopen("fileCout.dat", "w");
fclose(file);
file = fopen("fileAveout.dat", "w");
fclose(file);


fftw_destroy_plan(pf);
fftw_destroy_plan(pb);
fftw_free(in);
fftw_free(out);
return 0;

}
