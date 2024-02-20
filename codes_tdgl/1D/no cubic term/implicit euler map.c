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
double Deltat = 1000;
double tmax = tmin + Deltat;

/*C(t) = Ampl*sin(pi*t/(T/2))*/
double Ampl = 1;
double Thalf = 0.5;  // with this choice C will be constantly +1

double u = 1;
double ue;
double nu;

double ttime;
int nloop=(Deltat)/dt;
int loop;
double C[nloop];
double Ave[nloop];

FILE* fileAveout;
/*Clear temporary save file fileAveout.dat */
fileAveout = fopen("fileAveout.dat", "w");
fclose(fileAveout);

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
	C[loop]=-0.01 + Ampl*sin(pi*ttime/Thalf);
	}
	else	/*Thalf < 0 means you want to keep C costant*/
		C[loop] = Ampl;
}


/* EVOLUTION CODE */
for (loop=0; loop < nloop; loop++){
	ttime = tmin + (loop+1)*dt;	/*We calculate u(t+dt) in this loop, so the first time we calculate u(tmin + dt)*/

	/*Calculate new time u*/
    nu = (u)/(1-C[loop]*dt);
	u = nu;
	Ave[loop] = u;
	//printf("\nu(%.2lf) = %lf", ttime, u);
}

/*Save values of Space average in different times*/
double decaoutC;
fileAveout = fopen("fileAveout.dat", "a");
double time;
for (loop=0; loop<nloop; loop++){
	time = tmin + (loop+1)*dt;
	decaoutC = Ave[loop];
	fprintf(fileAveout, "%.5f %.20f\n", time, decaoutC);
}
fclose(fileAveout);

printf("\n\nu(%.2lf) = %lf", ttime, u);

return 0;
}

