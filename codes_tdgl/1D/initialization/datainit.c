//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>

#define pi  4*atan(1.0)

//pour générer des nombres aléatoires
double randU(double randmin, double randmax)
{
double randU1=0.;
randU1 = randmin*(1-rand()/(double)RAND_MAX)+randmax*rand()/(double)RAND_MAX;
return randU1;
}

int main(int argc, char  *argv [ ]){
/*Generate N unif r.v. with average hmoy and amplitude eps*/


int i;

int N=1000;
double deca;
double eps = 0;
double hmoy = 0;
int seed;

char *ptr;
if (argc > 1)
	N = (int)strtod(argv[1], &ptr);
if (argc > 2)
  	eps = strtod(argv[2], &ptr);
if (argc > 3)
    hmoy = strtod(argv[3], &ptr);

/*Read parameters from parameters.txt.
  Those are the used parameters, unless specified in the prompt
*/
double dx, dt, Ampl, Thalf, Cave;
FILE *fileparams;
fileparams = fopen("parameters.dat", "r");
fscanf(fileparams, "dx %lf\ndt %lf\nA %lf\nT %lf\nCave %lf", &dx, &dt, &Ampl, &Thalf, &Cave);
fclose(fileparams);

/*Prepare the initial state*/
FILE *fileinit;
double* u = malloc(N*sizeof(double));

seed = time(NULL);
srand(seed);
fileinit = fopen("fileinit.dat", "w");
fprintf(fileinit, "%d %d\n", seed, N);
#pragma omp parallel for
for (i=0; i<N; i++){
    deca=randU(-eps, eps)+hmoy;
    u[i] = deca;
    fprintf(fileinit, "%.20f\n", u[i]);
}

fclose(fileinit);

/*Save the state in tdgl_results*/
FILE *filetdglinit;
double decax, decau, tmin;
tmin = 0;

filetdglinit = fopen("tdgl_result.dat", "w");
/*Save parameters N, tmax, dx, dt, seed*/
fprintf(filetdglinit, "%d %.10lf %.10lf %.10lf %d %lf %lf %lf\n", N, tmin, dx, dt, seed, Ampl, Thalf, Cave);
for(i=0;i<N;i++) {
decax=i*dx;
decau=u[i];
fprintf(filetdglinit, "%.5f %.20f\n", decax, decau);
}
fclose(filetdglinit);

/*Recreate fileCout of values of C(t) [Progressive
executions of the dynamics will APPEND info]*/
FILE *file;
file = fopen("fileCout.dat", "w");
fclose(file);
file = fopen("fileAveout.dat", "w");
fclose(file);
file = fopen("fileq2Aveout.dat", "w");
fclose(file);
file = fopen("fileumax.dat", "w");
fclose(file);


return 0;

}
