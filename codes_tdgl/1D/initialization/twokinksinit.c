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

double doublekink(double x, double x1, double x2){
    return tanh(x-x1)-tanh(x-x2)-1;
}

int main(int argc, char  *argv [ ]){

int i;

int N=1000;
double u0;              /*Initial flat value*/
int seed;
double hmoy = 0;


seed = time(NULL);
srand(seed);

char *ptr;
if (argc > 1)
	N = (int)strtod(argv[1], &ptr);
if (argc > 2){
  	u0 = strtod(argv[2], &ptr);
} else{
    u0=randU(1, 1)+hmoy;
}

FILE *file;
double dx, dt, Ampl, Thalf, Cave;
file = fopen("parameters.dat", "r");
fscanf(file, "dx %lf\ndt %lf\nA %lf\nT %lf\nCave %lf", &dx, &dt, &Ampl, &Thalf, &Cave);
fclose(file);

double L = N*dx;


file = fopen("fileinit.dat", "w");
fprintf(file, "%d %d\n", seed, N);
double x;
for (i=0; i<N; i++){
    x = i*dx;
    fprintf(file, "%.20f\n", doublekink(x, L/3, L*2/3));
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
