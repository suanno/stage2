#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//#include </opt/intel/composer_xe_2013_sp1.3.174/mkl/include/fftw/fftw3.h>
#include <fftw3.h>
#include <math.h>

#define pi  4*atan(1.0)
#define N 10
int main(int argc, char  *argv [ ]){

double temp;
/*Space Parameters: From previous simulation*/
int N_; double dx;
/*Time Parameters: From params.txt*/
double dt, tmin, tmax, tspan;      /*   tmin: Initial time(of the initial state)
                                        tmax: Final time (of the final state)
                                    */
int read_from_top = 0;              /*Read fileCin.dat from t = 0 instead of t = tmin*/
int loop_read = 0;                  /*If fileCin.dat is finished, it continues reading it from top*/


/*  Read Lattice (space) parameters from last simulation
    [They must be the same for consecutive simulations (for consistency) while dt can change] */
FILE *fileinit;
int seed;
fileinit = fopen("state.dat", "r");
/*First line contains parameters*/
fscanf(fileinit, "%d %lf %lf\n", &N_, &tmin, &dx);
//fclose(fileinit);                 /*NOT close, we will read the state!*/

/*  Read Time parameters (only dt) from params.txt*/
FILE *fileparams;
fileparams = fopen("params.txt", "r");
fscanf(fileparams, "dx = %lf\ndt = %lf", &temp, &dt);   /*Read only dt, use dx of the past simulation for Consistency*/
fclose(fileparams);

/* Get inputs from the terminal */
char* fileCinName;
char* ptr;
int min_args = 2;     /* Minimum Number of required arguments*/
if (argc <= min_args){
    printf("Not enought arguments");
    return 0;
}
tspan = (double)strtod(argv[1], &ptr);
fileCinName = argv[2];
if (argc > min_args + 1)
    read_from_top = (int)strtod(argv[3], &ptr);

/* Time parameters */
tmax = tmin + tspan;
double ttime=0;
int nloop = (tspan)/dt;
int loop;

/* Allocation */
int i;
double** x = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		x[i] = malloc(N * sizeof(double));
double** h = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		h[i] = malloc(N * sizeof(double));
double** hfr = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hfr[i] = malloc(N * sizeof(double));
double** hfi = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hfi[i] = malloc(N * sizeof(double));
double** hdt = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hdt[i] = malloc(N * sizeof(double));
double** hdtfr = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hdtfr[i] = malloc(N * sizeof(double));
double** hdtfi = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hdtfi[i] = malloc(N * sizeof(double));
double** coeffr = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		coeffr[i] = malloc(N * sizeof(double));
double** hc = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hc[i] = malloc(N * sizeof(double));
double** hcfr = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hcfr[i] = malloc(N * sizeof(double));
double** hcfi = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hcfi[i] = malloc(N * sizeof(double));

double** lapfrcoef = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		lapfrcoef[i] = malloc(N * sizeof(double));
double** q2 = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		q2[i] = malloc(N * sizeof(double));
double** integ_coef = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		integ_coef[i] = malloc(N * sizeof(double));

double* ffr = malloc(N*sizeof(double));
double* qfr = malloc(N*sizeof(double));
double L = N*dx; // data for (x,y) is [0, L]x[0, L]

double z;
double Hm2=1;
//int i;
int j;
int k;

double deca;
double decaoutq2mean=0.0;

double q2meannum=0.0;
double q2meandenom=0.0;

/*
int Nst=8;
double savetimes[8]={1,2,3,4,4000,6000,8000,10000};
*/

double time;
int loops= nloop;
double q2mean[loops];
static double q2meannumar[N][N];
static double q2meandenomar[N][N];

int q2loop=0;
double qtime=0.0;

/*Read C(t) from file*/
FILE* fileCin;
double* C = malloc(nloop*sizeof(double));
double decatime = -1;
double decainC;
fileCin = fopen(fileCinName, "r");
loop = 0;
while (decatime < tmax*(1-read_from_top) + tspan*read_from_top){
    /*If you reach the end of fileCin [if t_state > t_finalC]*/
    if(fscanf(fileCin, "%lf %lf \n", &decatime, &decainC) == EOF){
		fclose(fileCin);
		if (loop_read == 1){
        	fileCin = fopen(fileCinName, "r");
			fscanf(fileCin, "%lf %lf \n", &decatime, &decainC);
        }else{
            printf("fileCin.dat is too short! Think to enable the loop reading of fileCin.dat");
            return 0;
        }
	}
    if (decatime >= tmin*(1-read_from_top) + 0*read_from_top)
        C[loop]=decainC;
        loop = loop + 1;
}
fclose(fileCin);


/*Define observables to track in time*/
FILE *fileAveout;
double* Ave = malloc(loops*sizeof(double)); /*Average magnetization*/

/*-----------------------------------------------------------------------*/

FILE *filenonconserve2dh;
FILE *fileq2mean;

char filename[16];

/* Prepare FFT Routines */
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

/*Build q-space lattice*/
for (i=1; i<(N/2); i++){
ffr[i]=i;
ffr[N-i]=-i;
}
ffr[0]=0;
ffr[N/2]=N/2;
for (i=0; i<N; i++){
qfr[i]=ffr[i]*2*pi/N;
}

/*Load initial state*/
for (i=0; i<N; i++){
for (j=0; j<N; j++){
fscanf(fileinit, "%lf %lf %lf\n", &temp, &temp, &z);
h[i][j]=z;
/*printf("u[%d][%d] = %.2lf\n", i, j, h[i][j]);*/
}
}
fclose(fileinit);   /*Only Now: you can eventually close the state file*/

// coefficients for implicit scheme
for (i=0; i<N; i++){
for (j=0; j<N; j++){
q2[i][j]=(qfr[i]*qfr[i]+qfr[j]*qfr[j]);
lapfrcoef[i][j]=-(qfr[i]*qfr[i]+qfr[j]*qfr[j])/(dx*dx);
}
}

/* EVOLUTION CODE */
for(loop=0;loop<loops;loop++) {
    time = tmin + (loop+1)*dt;
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

