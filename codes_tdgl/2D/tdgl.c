#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//#include </opt/intel/composer_xe_2013_sp1.3.174/mkl/include/fftw/fftw3.h>
#include <fftw3.h>
#include <math.h>

#define pi  4*atan(1.0)
int main(int argc, char  *argv [ ]){

double temp;
/*Space Parameters: From previous simulation*/
int N; double dx;
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
fscanf(fileinit, "%d %lf %lf\n", &N, &tmin, &dx);
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
int extra_args = 1;
if (argc > min_args + extra_args)
    read_from_top = (int)strtod(argv[min_args + extra_args], &ptr);
extra_args = extra_args + 1;
if (argc > min_args + extra_args)
    loop_read = (int)strtod(argv[min_args + extra_args], &ptr);
extra_args = extra_args + 1;

/* Time parameters */
tmax = tmin + tspan;
double ttime=0;
int nloop = (tspan)/dt;
int loop = 0;

/* Allocation */
int i;
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
double** hc = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hc[i] = malloc(N * sizeof(double));
double** hcfr = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hcfr[i] = malloc(N * sizeof(double));
double** hcfi = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		hcfi[i] = malloc(N * sizeof(double));

double** q2 = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		q2[i] = malloc(N * sizeof(double));
double** integ_coef = malloc(N*sizeof(double*));
for(i = 0; i < N; i++)
		integ_coef[i] = malloc(N * sizeof(double));

double* ffr = malloc(N*sizeof(double));
double* qfr = malloc(N*sizeof(double));
double L = N*dx; // data for (x,y) is [0, L]x[0, L]



double x, y, z;     /*For reading and printing the values of x,y,h*/
//int i;
int j;
int k;

double deca;

/*
int Nst=8;
double savetimes[8]={1,2,3,4,4000,6000,8000,10000};
*/

double time;


/*Read C(t) from file*/
FILE* fileCin;
double* C = malloc(nloop*sizeof(double));
double Cprev;   /*Last value of C in the previous simulation*/
double decatime = -1;
double decainC;
fileCin = fopen(fileCinName, "r");

/*CHECK IF dt is the SAME in params.txt and in fileCin.dat*/
fscanf(fileCin, "%lf %lf \n", &decatime, &decainC);
fscanf(fileCin, "%lf %lf \n", &decatime, &decainC);
if (fabs(dt - decatime) > dt/1000){
    printf("The time step dt is different in 'fileCin.dat' (%lf) and 'params.txt' (%lf))", decatime, dt);
    return 0;
}
fclose(fileCin);
fileCin = fopen(fileCinName, "r");

/*READ C(t) from file*/
/*CONVENTION: C[i]=C(t_i + dt)*/
/*Bring the pointer in the fileCin file to the right row*/
int ntmin = (int)(tmin/dt); /*How many values of C(t) in the file you have to Ignore*/
for (int i = 0; i <= ntmin*(1-read_from_top); i++){
    /*If you reach the end of fileCin [if t_state > t_finalC]*/
    if(fscanf(fileCin, "%lf %lf \n", &decatime, &decainC) == EOF){
		if (loop_read == 1){
            //fclose(fileCin);
        	//fileCin = fopen(fileCinName, "r");
			rewind(fileCin);
            fscanf(fileCin, "%lf %lf \n", &decatime, &decainC);
        }else{
            printf("fileCin.dat is too short! Think to enable the loop reading of fileCin.dat");
            return 0;
        }
	}
    Cprev = decainC;
    loop = loop + 1;
}
printf("Reading C(t) from file. From t = %lf\n", decatime);
/*Now read the values of C[i]=C(t_i+dt)*/
for (int i = ntmin*(1-read_from_top); i < ntmin*(1-read_from_top) + nloop; i++){
    /*If you reach the end of fileCin [if t_state > t_finalC]*/
    if(fscanf(fileCin, "%lf %lf \n", &decatime, &decainC) == EOF){
		if (loop_read == 1){
            //fclose(fileCin);
        	//fileCin = fopen(fileCinName, "r");
			rewind(fileCin);
            fscanf(fileCin, "%lf %lf \n", &decatime, &decainC);
        }else{
            printf("fileCin.dat is too short! Think to enable the loop reading of fileCin.dat");
            return 0;
        }
	}
    C[i-ntmin] = decainC;
    loop = loop + 1;
}
printf("Finish reading C(t) from file. Until t = %lf; tmax = %lf\n", decatime, tmax);
fclose(fileCin);


/*Define observables to track in time*/
FILE *fileAveout;
double* Ave = malloc(nloop*sizeof(double)); /*Average magnetization*/

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
        fscanf(fileinit, "%lf %lf %lf\n", &x, &y, &z);
        h[i][j]=z;
        /*printf("u[%d][%d] = %.2lf\n", i, j, h[i][j]);*/
    }
}
fclose(fileinit);   /*Only Now: you can eventually close the state file*/

// coefficients for implicit scheme
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        q2[i][j]=- (qfr[i]*qfr[i]+qfr[j]*qfr[j])/(dx*dx);
    }
}

/* EVOLUTION CODE */
printf("Number time steps going to simulate = %d\n", nloop);
for(loop=0;loop<nloop;loop++) {
    time = tmin + (loop+1)*dt;
    /*
    printf("\n\nTime: %.2lf\n", time-dt);
    printf("h[%d][%d]*dt = %.2lf\n", i, j, h[i][j]);
    */
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            integ_coef[i][j]=1-dt*C[loop]/2-dt*q2[i][j]/2;
        }
    }

    /*FFT of h(x,y)->H(qx,qy)*/
    #pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            in[i*N+j][0] = h[i][j];
            in[i*N+j][1] = 0.0;
        }
    }
    fftw_execute(pf);
    #pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            hfr[i][j] = out[i*N+j][0];
            hfi[i][j] = out[i*N+j][1];
        }
    }

    /*FFT of h3(x,y)->H3(qx,qy)*/
    #pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            hc[i][j] = h[i][j]*h[i][j]*h[i][j];
            in[i*N+j][0] = hc[i][j];
            in[i*N+j][1] = 0.0;
        }
    }
    fftw_execute(pf);
    #pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            hcfr[i][j] = out[i*N+j][0];
            hcfi[i][j] = out[i*N+j][1];
        }
    }

    /*C[loop] = C(t+dt) but we need even C(t)=Cprev for Cranck-Nicolson*/
	if (tmin == 0)
		Cprev = C[0];   /*There is no precedent value, so we tool C(t)=C(t+dt) for the FISRT STEP (t=0)*/
    else if (loop > 0)
		Cprev = C[loop-1];
    /*If loop = 0 and tmin > 0, the value of Cprev is already set to the last of the last simulation*/

    /* Crank-Nicolson */
    //#pragma omp parallel for //seulement pour les grands systèmes
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            hdtfr[i][j]=(hfr[i][j]*(1+dt*Cprev/2+dt*q2[i][j]/2)-dt*hcfr[i][j])/integ_coef[i][j];
            hdtfi[i][j]=(hfi[i][j]*(1+dt*Cprev/2+dt*q2[i][j]/2)-dt*hcfi[i][j])/integ_coef[i][j];
        }
    }

    /*INVERSE FFT*/
    #pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            in[i*N+j][0] = hdtfr[i][j];
            in[i*N+j][1] = hdtfi[i][j];
        }
    }
    fftw_execute(pb);
    #pragma omp parallel for //seulement pour les grands systèmes
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            hdt[i][j] = out[i*N+j][0]/(N*N);
        }
    }

    /* Measure Observables (instantaneous value) */
    Ave[loop] = 0;
    //#pragma omp parallel for //seulement pour les grands systèmes
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

/*Save the final state*/
FILE* filefinalstate;
filefinalstate = fopen("state.dat", "w");
/*Save parameters N, tmax, dx, dt, seed, Ampl, Thalf*/
fprintf(filefinalstate, "%d %lf %lf\n", N, tmax, dx);
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        x = i*dx;
        y = j*dx;
        z = h[i][j];
        fprintf(filefinalstate, "%.20f %.20f %.20f\n", x, y, z);
    }
}
fclose(filefinalstate);

/*Save the values taken by C(t) in time.
  They are appendend, so you save its values from t=0
*/
FILE* fileCout;
double decaout;
fileCout = fopen("fileCout.dat", "a");
for (loop=0; loop<nloop; loop++){
    ttime = tmin + (loop+1)*dt;
    decaout = C[loop];
    /*printf("C[%d] = %lf\n", loop, C[loop]);*/
    fprintf(fileCout, "%.5f %.20f\n", ttime, decaout);
}
fclose(fileCout);

/*Save values of Space average in different times*/
fileAveout = fopen("fileAveout.dat", "a");
for (loop=0; loop<nloop; loop++){
    time = tmin + (loop+1)*dt;
    decaout = Ave[loop];
    fprintf(fileAveout, "%.5f %.20f\n", time, decaout);
}
fclose(fileAveout);



//------------------------------------------

fftw_destroy_plan(pf);
fftw_destroy_plan(pb);
fftw_free(in);
fftw_free(out);
// clean up threads
fftw_cleanup_threads();

free(C);
free(h);
free(hc);
free(hfr);
free(hfi);
free(hcfr);
free(hcfi);
free(hdt);
free(hdtfr);
free(hdtfi);
free(q2);
free(qfr);
free(ffr);
free(integ_coef);


return 0;
}

