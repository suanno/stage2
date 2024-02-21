// Solve the TDGL equation
// Forward integration using implicit Euler scheme
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define pi 4*atan(1.0)

int main(int argc, char  *argv [ ]){

/*Parameters: They are read from previous simulation .dat file*/

int N=1000;
double dx=0.1;

double dt=0.01;
double tmin=1;	//tmin is the tmax of previous evolution
double Deltat = 10;
double tmax = tmin + Deltat;

/*C(t) = Cave + Ampl*sin(2pi*t)*/
double Cave = 0;
double Ampl = 1;
double Thalf = -1;  // T/2 If T < 0 it means C(t) = Cave costant

/* Read parameters from last simulation */
FILE *fileinit;
int seed;
fileinit = fopen("tdgl_result.dat", "r");
/*First line is for parameters and seed
  tdgl adopts THE SAME parameters (N,dx, dt) that were used in the
  previous evolution with tdglfd or tdgl, unless specified in the command prompt.
*/
fscanf(fileinit, "%d %lf %lf %lf %d %lf %lf %lf\n", &N, &tmin, &dx, &dt, &seed, &Ampl, &Thalf, &Cave);
fclose(fileinit);

/* Get inputs from the terminal */
char *ptr;
//printf("argv1 = %lf", atof(argv[1]));
if (argc > 1)
	Deltat = strtod(argv[1], &ptr);
if (argc > 2){
  	Ampl = strtod(argv[2], &ptr);
}
if (argc > 3){
  	/*Period of the sine*/
  	Thalf = strtod(argv[3], &ptr)/2;
}
if (argc > 4){
  	/*Offset of C(t)*/
  	Cave = strtod(argv[4], &ptr);
}
if (argc > 5){
  	/*Period of the sine*/
  	dt = strtod(argv[5], &ptr);
}

/*The evolutions are consecutive, so the initial time (and state)
 are the finals of the previous evolution
*/
tmax = tmin + Deltat;
double ttime=0;
int nloop=(Deltat)/dt;
int loop;

double* x = malloc(N*sizeof(double));
double* u = malloc(N*sizeof(double));
double* ufr = malloc(N*sizeof(double));
double* ufi = malloc(N*sizeof(double));
double* udt = malloc(N*sizeof(double));
double* udtfr = malloc(N*sizeof(double));
double* udtfi = malloc(N*sizeof(double));

double* NL = malloc(N*sizeof(double));
double* NLfr = malloc(N*sizeof(double));
double* NLfi = malloc(N*sizeof(double));

int i;
double decainx=0;
double decainu=0;
double decaoutx=0;
double decaoutu=0;
double decaoutC=0;
double decaoutAve=0;
double decainC=0;
double decatime=0;

double* ffr = malloc(N*sizeof(double));
double* qfr = malloc(N*sizeof(double));
double* d2coef = malloc(N*sizeof(double));
double* integ_coef = malloc(N*sizeof(double));

FILE *stateeqn_result;
FILE *fileCout;				/*C(t+dt) values*/
FILE *fileAveout;			/*Space average of u(t) values*/
//FILE *fileCin;

double* C = malloc(nloop*sizeof(double));				/*C(t+dt) values*/
double Cprev;											/*Temp variable to store C(t) [because C[loop] is C(t+dt) NOT C(t)]*/
double* uAve = malloc(nloop*sizeof(double));			/*Space average of u(t) values*/

/*Read C(t) from file*/
/*
fileCin = fopen("fileC.dat", "r");
for (loop=0; loop<nloop; loop++){
	fscanf(fileCin, "%lf %lf \n", &decatime, &decainC);
	C[loop]=decainC;
}
fclose(fileCin);
*/

/*Define value of C(t) in time.
	C(t) = Cave + Ampl*sin(pi*t/(T/2))
	NOTE: Time "t" starts at the beginning of the FIRST of
	the serie of consecutive evolutions, and NOT at the beginning
	of the current simulation.
	So the C value at the beginning of the current simulation
	is NOT Ampl*sin(0) = 0 .
	BUT defining C(t) like this, we have the property that C(t)
	is varying SMOOTHLY during the WHOLE (total serie of consecutive evolutions) experiment.
*/
/*NOTE: As to calculate u(t+dt) we need C(t+dt), we adopt the following convention
	C[loop] = C(dt*loop + dt)
	So C[0] = C(0 + dt) and so on
*/
for (loop=0;loop<nloop;loop++){
ttime = tmin + (loop + 1)*dt;		/*C[loop] = C(t+dt), so it's NOT C(t)*/
if(Thalf > 0){
	C[loop]=Cave + Ampl*sin(pi*ttime/Thalf);
	}
	else							/*Thalf < 0 means you want to keep C = Cave + Ampl costant*/
		C[loop] = Cave;
}

ttime=0;
loop=0;

char filename[16];

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

/*LOAD INITIAL STATE*/

FILE *fileinit2;
fileinit2 = fopen("tdgl_result.dat", "r");
/*First line is for parameters and seed*/
fscanf(fileinit2, "%d %lf %lf %lf %d %lf %lf %lf\n", &N, &tmin, &dx, &dt, &seed, &Ampl, &Thalf, &Cave);
/*Now read the initial (smooth) state*/
for (i=0; i<N; i++){
fscanf(fileinit2, "%lf %lf\n", &decainx, &decainu);
x[i]=decainx;
u[i]=decainu;
printf("\n\n%lf\n", decainx);
}
fclose(fileinit2);

//------------------------------------

// coefficients for spectral derivatives (-q^2) array (with already the minus sign!)
for (i=0; i<N; i++){
d2coef[i]=-(qfr[i]/dx)*(qfr[i]/dx);
}

/* EVOLUTION CODE */
for (loop=0; loop < nloop; loop++){
	ttime = tmin + (loop+1)*dt;	/*We calculate u(t+dt) in this loop, 
	so the first time we calculate (and save in the .dat) u(tmin + dt), NOT u(t)*/

	/*Denominator of Crank-Nicolson*/
	for (i=0; i<N; i++){
	integ_coef[i]=1-dt*C[loop]/2-dt*d2coef[i]/2; 	//Note that d2coeff = -q^2 (already contains a minus sign)
											 		//And that C[loop] is C(t+dt), NOT C(t)
													//And the 1/2 is for Crank-Nicolson
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

	// ********** begin of main algorithm **********

	/*Compute FFT of u(x)^3 (u^3 is called NL: Non Linear term)*/
	for (i=0; i<N; i++){
	NL[i]=u[i]*u[i]*u[i];
	}

	for(i=0; i<N; i++) {
	in[i][0]=NL[i];
	in[i][1]=0.0;
	}
	fftw_execute(pf); // repeat as needed
	for(i=0; i<N; i++) {
	NLfr[i]=out[i][0];
	NLfi[i]=out[i][1];
	}

	/*C[loop] = C(t+dt) but we need even C(t)=Cprev*/
	if (loop == 0)
		Cprev = 0;
	else
		Cprev = C[loop-1];
	
	/*Crank-Nicolson*/
	for (i=0; i<N; i++){
		udtfr[i]=(ufr[i]*(1+dt*Cprev/2+dt*d2coef[i]/2)-dt*NLfr[i])/integ_coef[i];
		udtfi[i]=(ufi[i]*(1+dt*Cprev/2+dt*d2coef[i]/2)-dt*NLfi[i])/integ_coef[i];	
	}

	// ********** end of main algorithm **********

	/*INVERSE FFT*/
	for(i=0; i<N; i++) {
	in[i][0]=udtfr[i];
	in[i][1]=udtfi[i];
	}
	fftw_execute(pb); // repeat as needed
	for(i=0; i<N; i++) {
	udt[i]=out[i][0]/N;
	}

	for(i=0; i<N; i++) {
	u[i]=udt[i];
	}

	/*Compute space average*/
	uAve[loop] = 0;
	for (i = 0; i<N; i++){
		uAve[loop] = uAve[loop] + u[i];
	}
	uAve[loop] = uAve[loop]/N;
}

/*Save the final state*/
stateeqn_result = fopen("tdgl_result.dat", "w");
/*Save parameters N, tmax, dx, dt, seed, Ampl, Thalf*/
fprintf(stateeqn_result, "%d %.10lf %.10lf %.10lf %d %lf %lf %lf\n", N, tmax, dx, dt, seed, Ampl, Thalf, Cave);
for (i=0; i<N; i++){
decaoutx=x[i];
decaoutu=u[i];
fprintf(stateeqn_result, "%.10f %.20f\n", decaoutx, decaoutu);
}
fclose(stateeqn_result);

/*Save the values taken by C(t) in time.
  They are appendend, so you save its values from t=0
*/
fileCout = fopen("fileCout.dat", "a");
for (loop=0; loop<nloop; loop++){
ttime = tmin + (loop+1)*dt;
decaoutC = C[loop];
/*printf("C[%d] = %lf\n", loop, C[loop]);*/
fprintf(fileCout, "%.5f %.20f\n", ttime, decaoutC);
}
fclose(fileCout);

/*Save the SPACE average of u(x,t) at each time.
  They are appendend, so you save its values from t=0
*/
fileAveout = fopen("fileAveout.dat", "a");
for (loop=0; loop<nloop; loop++){
ttime = tmin + (loop+1)*dt;
decaoutAve = uAve[loop];
fprintf(fileAveout, "%.5f %.20f\n", ttime, decaoutAve);
}
fclose(fileAveout);

fftw_destroy_plan(pf);
fftw_destroy_plan(pb);
fftw_free(in);
fftw_free(out);

free(x);
free(u);
free(ufr);
free(ufi);
free(udt);
free(udtfr);
free(udtfi);
free(NL);
free(NLfr);
free(NLfi);
free(C);
free(uAve);
free(ffr);
free(qfr);
free(d2coef);
free(integ_coef);

	return 0;
}

