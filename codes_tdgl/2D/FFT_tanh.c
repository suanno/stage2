#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
//#include </opt/intel/composer_xe_2013_sp1.3.174/mkl/include/fftw/fftw3.h>
#include <fftw3.h>
#include <math.h>

#define pi  4*atan(1.0)
int main(int argc, char  *argv [ ]){
    int N;
    double dx, tmin;

    char* ptr;
    char* filename;
    FILE* fileinit;
    filename = "state.dat";

    /*Read N, dx*/
    fileinit = fopen(filename, "r");
    /*First line contains parameters*/
    fscanf(fileinit, "%d %lf %lf\n", &N, &tmin, &dx);

    double** h = malloc(N*sizeof(double*));
    int i = 0; int j = 0;
    for(i = 0; i < N; i++){
            h[i] = malloc(N * sizeof(double));
    }
    double** hfr = malloc(N*sizeof(double*));
    for(i = 0; i < N; i++)
            hfr[i] = malloc(N * sizeof(double));
    double** hfi = malloc(N*sizeof(double*));
    for(i = 0; i < N; i++)
            hfi[i] = malloc(N * sizeof(double));
    double** q2 = malloc(N*sizeof(double*));
    for(i = 0; i < N; i++)
            q2[i] = malloc(N * sizeof(double));


    printf("Loaded\nN=%d\ndx=%lf\n", N, dx);
    /*Load initial state*/
    double x, y, z;
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            fscanf(fileinit, "%lf %lf %lf\n", &x, &y, &z);
            h[i][j]=z;
        }
    }
    fclose(fileinit);   /*Only Now: you can eventually close the state file*/



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


    double* ffr = malloc(N*sizeof(double));
    double* qfr = malloc(N*sizeof(double)); 
    /*Build q-space lattice*/
    for (i=1; i<(N/2); i++){
        ffr[i]=i;
        ffr[N-i]=-i;
    }
        ffr[0]=0;
        ffr[N/2]=N/2;
    for (i=0; i<N; i++){
        qfr[i]=ffr[i]*2*pi/(N*dx);
    }
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            q2[i][j]= (qfr[i]*qfr[i]+qfr[j]*qfr[j]);
        }
    }


    /*Compute FFT*/
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

    /*Save the final state*/
    FILE* filefinalstate;
    filefinalstate = fopen("fftr.dat", "w");
    /*Save parameters in first row*/
    double qx, qy;
    fprintf(filefinalstate, "%d %lf %lf\n", N, tmin, dx);
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            qx = qfr[i];
            qy = qfr[j];
            z = hfr[i][j];
            fprintf(filefinalstate, "%.20f %.20f %.20f\n", qx, qy, z);
        }
    }
    fclose(filefinalstate);

    /*Save the final state*/
    filefinalstate = fopen("ffti.dat", "w");
    /*Save parameters in first row*/
    fprintf(filefinalstate, "%d %lf %lf\n", N, tmin, dx);
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            qx = qfr[i];
            qy = qfr[j];
            z = hfi[i][j];
            fprintf(filefinalstate, "%.20f %.20f %.20f\n", qx, qy, z);
        }
    }
    fclose(filefinalstate);

    /*Save Modulus vs q^2*/
    filefinalstate = fopen("fftmodulus.dat", "w");
    /*Save parameters in first row*/
    fprintf(filefinalstate, "%d %lf %lf\n", N, tmin, dx);
    for (i=0; i<N; i++){
        for (j=0; j<N; j++){
            x = q2[i][j];
            y = sqrt(hfr[i][j]*hfr[i][j] + hfi[i][j]*hfi[i][j]);
            fprintf(filefinalstate, "%.20f %.20f\n", x, y);
        }
    }
    fclose(filefinalstate);



}