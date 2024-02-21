#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <unistd.h>        // chdir
#include <sys/stat.h>      // mkdir


#define pi  4*atan(1.0)

int main(int argc, char* argv[]){

int N=1000;            /*Lattice sites*/
double dx = 0.1;        /*Lattice spacing*/
double L=N*dx;

double dt=0.008; // note: stable upto dt=0.001
double tmin=0;
double tmax=0;
double Deltat = tmax - tmin;

/*C(t) = Cave + Ampl*sin(2pi*t)*/
double Cave = 0;
double Ampl = 1;
double Thalf = -1;  // T/2; If Thalf < 0, then C(t) will be constantly +Cave

/*Read parameters from parameters.txt.
  Those are the used parameters, unless specified in the prompt
*/
FILE *fileparams;
fileparams = fopen("parameters.dat", "r");
fscanf(fileparams, "dx %lf\ndt %lf\nA %lf\nT %lf\nCave %lf", &dx, &dt, &Ampl, &Thalf, &Cave);
fclose(fileparams);

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
tmax = tmin + Deltat;

/*The scalar field is Phi(x,t) and we call it u(x,t)
- x dependance is in the array index
- for time dependance we save current time (t) value "u" and precedent time (t-1) value "up"
u = Phi(t)
up = Phi(t-1)
udt = dPhi/dt
*/
double* u = malloc(N*sizeof(double));       
double* udt = malloc(N*sizeof(double));
double* up = malloc((N + 2)*sizeof(double));

double* lapu = malloc(N*sizeof(double));

double* dF = malloc(N*sizeof(double));
double* uc = malloc(N*sizeof(double));
double* Lu = malloc(N*sizeof(double));

double z;
double decax;
double decau;
double decaoutC=0;
int i;

double d2coef=1.0/pow(dx,2);

int loop;
double ttime;

double area;
int nloop=Deltat/dt;

double* C = malloc(nloop*sizeof(double));
double* Ave = malloc(nloop*sizeof(double));

/*Recreate fileCout of values of C(t) and fileAve of Space Averages [Progressive
executions of the dynamics will APPEND info]*/
FILE *file;
file = fopen("fileCout.dat", "w");
fclose(file);
file = fopen("fileAveout.dat", "w");
fclose(file);

/*Define the values of C(t) at different times*/
for (loop=0;loop<nloop;loop++){
ttime = tmin + (loop+1)*dt;
//C(t_{k+1})
if(Thalf > 0){
  C[loop]= Cave + Ampl*sin(pi*ttime/Thalf);
  /*
	if (sin(pi*ttime/Thalf)>=0) 
		C[loop]=Ampl;
	else 
		C[loop]=-Ampl;
  */
	}
	else
		C[loop] = Cave;
}
/*
for (loop = 0; loop < nloop; loop++){
  C[loop] = 1;
}
*/

/*Read the initial state*/
FILE *filerandominit;
FILE *filetdglinit;
FILE *fileCout;
FILE *fileAveout;
int seed;

filerandominit = fopen("fileinit.dat", "r");
/*First line is the seed*/
fscanf(filerandominit, "%d %d\n", &seed, &N);
for (i=0; i<N; i++){
fscanf(filerandominit, "%lf\n", &z);
u[i]=z;
}

fclose(filerandominit);


/*--- Numerical solving TDGL eq ---*/

/*Time loop*/

/*printf("nloop = %d", nloop);*/
for(loop=0;loop<nloop;loop++) {

    ttime = (loop+1)*dt+tmin;

    for(i=0; i<N; i++) {
      up[i+1] = u[i];
      dF[i]=u[i]*u[i]*u[i]-C[loop]*u[i];
    }

    /*PBC boundaries*/
    up[0] = up[N];
    up[N+1] = up[1];

    /*Compute second order second derivative*/
    for(i=1; i<N+1; i++) {
      lapu[i-1]=d2coef*(up[i+1]+up[i-1]-2*up[i]);
    }

    /*Compute EXPLICIT Euler du/dt and then du (and so u(t+1))*/
    for(i=0;i<N;i++) {
      Lu[i] = lapu[i] - dF[i];
      udt[i] = u[i] + dt*Lu[i];
    }
    for(i=0;i<N;i++) {
      u[i] = udt[i];
    }
    
    /*Compute space average*/
    Ave[loop] = 0;
    for (i = 0; i<N; i++){
      Ave[loop] = Ave[loop] + u[i];
    }
    Ave[loop] = Ave[loop]/N;
}

/*Save values of C(t) in different times*/
fileCout = fopen("fileCout.dat", "a");
for (loop=0; loop<nloop; loop++){
ttime = tmin + (loop+1)*dt;
decaoutC = C[loop];
fprintf(fileCout, "%.5f %.20f\n", ttime, decaoutC);
}
fclose(fileCout);

/*Save values of Space average in different times*/
fileAveout = fopen("fileAveout.dat", "a");
for (loop=0; loop<nloop; loop++){
ttime = tmin + (loop+1)*dt;
decaoutC = Ave[loop];
fprintf(fileAveout, "%.5f %.20f\n", ttime, decaoutC);
}
fclose(fileAveout);

/*Save the final state*/
//filetdglinit = fopen("tdgl_init.dat", "w");
filetdglinit = fopen("tdgl_result.dat", "w");
/*Save parameters N, tmax, dx, dt, seed*/
tmax = tmax + tmin; // So we save the TOTAL time of the dynamics
fprintf(filetdglinit, "%d %.10lf %.10lf %.10lf %d %lf %lf %lf\n", N, tmax, dx, dt, seed, Ampl, Thalf, Cave);
for(i=0;i<N;i++) {
decax=i*dx;
decau=u[i];
fprintf(filetdglinit, "%.5f %.20f\n", decax, decau);
}
fclose(filetdglinit);

free(u);
free(up);
free(udt);
free(dF);
free(uc);
free(Lu);
free(lapu);
free(C);
free(Ave);

return 0;
}