//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>

#define pi  4*atan(1.0)

/* Generate a flat profile with added a sine wave
    of the specified wavelenght
    u(x) = u0 + eps*sin(2pi x/lamb)

    NOTE: You have to specify the dx
    when calling the file, and it
    MUST be the SAME of the evolution!
*/

int main(int argc, char  *argv [ ]){

int i;

double L = 1000;
double dx = 0.1;
int seed;

/* u(x) = u0 + eps*sin(2pi x/lamb) */
double u0 = 0;
double eps = 0;
double lamb = L;

seed = time(NULL);
srand(seed);

char *ptr;
if (argc > 1)
	L = strtod(argv[1], &ptr);
if (argc > 2)
	dx = strtod(argv[2], &ptr);
if (argc > 3)
  	u0 = strtod(argv[3], &ptr);
if (argc > 4)
    lamb = strtod(argv[4], &ptr);
else
    lamb = L;
if (argc > 5)
    eps = strtod(argv[5], &ptr);

int N = (int)(L/dx);
dx = L/((double)N);   /*Recalculate dx*/
printf("New dx = %lf\n", dx);

FILE *file;
double* u = malloc(N*sizeof(double));
double x;

/*Generate the profile*/
file = fopen("fileinit.dat", "w");
fprintf(file, "%d %d\n", seed, N);
#pragma omp parallel for
for (i=0; i<N; i++){
    x = i*dx;
    u[i] = u0 + -eps*sin(2*pi*x/lamb);  /*The minus make the sine like tanh instead of -tanh=tanh(-x)*/
    //printf("\nlambda = %lf; x = %lf", lambda, i*dx);
    fprintf(file, "%.20f\n", u[i]);
}
fclose(file);


/*Prepare the tdgl_result.dat file*/
/*Read evolution parameters from parameters.txt.
  Those are the used parameters, unless specified in the prompt
*/
double dt;
double Cave = 0;
double Ampl = 1;
double Thalf = -1;  // T/2; If Thalf < 0, then C(t) will be constantly +Cave
double not_dx = 0;

file = fopen("parameters.dat", "r");
fscanf(file, "dx %lf\ndt %lf\nA %lf\nT %lf\nCave %lf", &not_dx, &dt, &Ampl, &Thalf, &Cave);
fclose(file);

/*Save the initial state*/
//filetdglinit = fopen("tdgl_init.dat", "w");
file = fopen("tdgl_result.dat", "w");
/*Save parameters N, tmax, dx, dt, seed*/
double tmax = 0; // So we save the TOTAL time of the dynamics
fprintf(file, "%d %.10lf %.10lf %.10lf %d %lf %lf %lf\n", N, tmax, dx, dt, seed, Ampl, Thalf, Cave);
for(i=0;i<N;i++) {
    x = i*dx;
    fprintf(file, "%.5f %.20f\n", x, u[i]);
}
fclose(file);

/*Recreate fileCout of values of C(t) [Progressive
executions of the dynamics will APPEND info]*/
file = fopen("fileCout.dat", "w");
fclose(file);
file = fopen("fileAveout.dat", "w");
fclose(file);


return 0;

}
