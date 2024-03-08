//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define pi  4*atan(1.0)

double singlekink(double x, double xc, double alpha, double beta){
    //printf("x = %lf, xc = %lf\n", x, xc);
    return beta*tanh((x-xc)*alpha);
}

int main(int argc, char  *argv [ ]){

int i;

int N = 100;
double alpha, beta, xc;
double x, dx;
int seed;
double hmoy = 0;


seed = time(NULL);
srand(seed);

char *ptr;
if (argc > 1)
	N = (int)strtod(argv[1], &ptr);
if (argc > 2){
  	alpha = strtod(argv[2], &ptr);
    if (argc > 3){
  	    beta = strtod(argv[3], &ptr);
    }
    else{
        beta = 1;
    }
}
else{
    alpha = 1;
}


dx = 0.1;
double L = (double)N*dx;
printf("L = %lf", L);

FILE *fileinit;

fileinit = fopen("fileinit.dat", "w");
fprintf(fileinit, "%d %d\n", seed, N);
#pragma omp parallel for
for (i=0; i<N; i++){
    x = i*dx;
    fprintf(fileinit, "%.20f\n", singlekink(x, L/2, alpha, beta));
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
