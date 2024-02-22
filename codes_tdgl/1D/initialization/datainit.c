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

FILE *fileinit;

seed = time(NULL);
srand(seed);
fileinit = fopen("fileinit.dat", "w");
fprintf(fileinit, "%d %d\n", seed, N);
#pragma omp parallel for
for (i=0; i<N; i++){
    deca=randU(-eps, eps)+hmoy;
    fprintf(fileinit, "%.20f\n", deca);
}

fclose(fileinit);

/*Recreate fileCout of values of C(t) [Progressive
executions of the dynamics will APPEND info]*/
FILE *file;
file = fopen("fileCout.dat", "w");
fclose(file);
file = fopen("fileAveout.dat", "w");
fclose(file);


return 0;

}
