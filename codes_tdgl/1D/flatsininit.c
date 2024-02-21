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

int i;

int N=1000;
double u0;              /*Initial flat value*/
int seed;
double eps = 0;
double dx = 0.1;


seed = time(NULL);
srand(seed);

char *ptr;
if (argc > 1)
	N = (int)strtod(argv[1], &ptr);
if (argc > 2){
  	u0 = strtod(argv[2], &ptr);
    if (argc > 3){
        eps = strtod(argv[3], &ptr);
        if (argc > 4){
            dx = strtod(argv[4], &ptr);
        }
    }
}



FILE *fileinit;
double u;
double lambda = 20;

fileinit = fopen("fileinit.dat", "w");
fprintf(fileinit, "%d %d\n", seed, N);
#pragma omp parallel for
for (i=0; i<N; i++){
    u = u0 + eps*sin(2*pi*i*dx/lambda);
    //printf("\nlambda = %lf; x = %lf", lambda, i*dx);
    fprintf(fileinit, "%.20f\n", u);
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
