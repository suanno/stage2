// Solve the TDGL equation WITHOUT laplacian term
// Using implicit Euler scheme
// We can see the evidence of the (two:positive and negative) fixed point different from zero
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

#define vector_size 10000
#define pi 4*atan(1.0)

int main(int argc, char  *argv [ ]){

/*Parameters: They are read from previous simulation .dat file*/

double dt=0.008;
double tmin=0;	//tmin is the tmax of previous evolution
double Deltat = 100000;
double tmax = tmin + Deltat;

/*C(t) = Ampl*sin(pi*t/(T/2))*/
double Ampl = 1;
double Thalf = 0.5;  // with this choice C will be constantly +1

double u = 1;
double uc = u*u*u;
double ue;
double nu;

int use_explicit = 0;

double ttime;
int nloop=(Deltat)/dt;
int loop;
double* C = malloc(nloop*sizeof(double));
double Cprev;

FILE* fileAveout;

/*Define value of C(t) in time.
	C(t) = Ampl*sin(pi*t/(T/2))
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
	C[loop]=Ampl*sin(pi*ttime/Thalf);
	}
	else	/*Thalf < 0 means you want to keep C costant*/
		C[loop] = Ampl;
}


/* EVOLUTION CODE */
fileAveout = fopen("fileAveout.dat", "w");
for (loop=0; loop < nloop; loop++){
	ttime = tmin + (loop+1)*dt;	/*We calculate u(t+dt) in this loop, so the first time we calculate u(tmin + dt)*/

	/*C[loop] = C(t+dt) but we need even C(t)=Cprev*/
	if (loop == 0)
		Cprev = 0;
	else
		Cprev = C[loop-1];
	/*Crak-Nicolson*/
	uc = u*u*u;
    nu = (u*(1+Cprev*dt/2)-uc*dt)/(1-C[loop]*dt/2);
	u = nu;
	fprintf(fileAveout, "%.5f %.20f\n", ttime, u);
}

printf("\nu(%.2lf) = %lf", ttime, u);

return 0;
}

