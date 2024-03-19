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

int N;
double deca;
double u0;
double hmoy = 0.0;

char *ptr;
int n_args = 2;     /*Number of required arguments*/
if (argc <= n_args){
    printf("Not enought arguments");
    return 0;
}

N = (int)strtod(argv[1], &ptr);
u0 = strtod(argv[2], &ptr);

FILE *fileinit;
fileinit = fopen("fileinit.dat", "w");
#pragma omp parallel for
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        deca=u0*randU(-1, 1) + hmoy;
        fprintf(fileinit, "%.20f\n", deca);
    }
}
fclose(fileinit);

}
