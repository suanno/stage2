//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>

#define pi  4*atan(1.0)

//pour générer des nombres aléatoires
float randU(float randmin, float randmax)
{
float randU1=0.;
randU1 = randmin*(1-rand()/(float)RAND_MAX)+randmax*rand()/(float)RAND_MAX;
return randU1;
}

int main(int argc, char  *argv [ ]){

int i;
int j;

double L, dx;
int N;
double deca;
double u0;
double hmoy = 0.0;

char *ptr;
int n_args = 2;         /*Number of required arguments*/
if (argc <= n_args){
    printf("Not enought input arguments");
    return 0;
}
L = strtod(argv[1], &ptr);
u0 = strtod(argv[2], &ptr);
if (argc > n_args + 1)
    hmoy = strtod(argv[n_args + 1], &ptr);

/* Read dx from params.txt */
FILE *fileparams;
fileparams = fopen("params.txt", "r");
fscanf(fileparams, "dx = %lf", &dx);
fclose(fileparams);

N = (int)(L/dx);
dx = (double)L/N;
printf("New dx = %lf\n", dx);


/* Prepare the state */
FILE *fileinit;
double x, y;
fileinit = fopen("state.dat", "w");
fprintf(fileinit, "%d %lf %lf\n", N, 0.0, dx);
//#pragma omp parallel for  /*I want the x,y to be SORTED in the state.dat file. So no parallel!*/
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        x = i*dx;
        y = j*dx;
        fprintf(fileinit, "%.5f %.5f %.20f\n", x, y, randU(hmoy - u0, hmoy + u0));
    }
}
fclose(fileinit);

}
