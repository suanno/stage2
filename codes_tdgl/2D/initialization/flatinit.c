//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>
#include <time.h>

#define pi  4*atan(1.0)

int main(int argc, char  *argv [ ]){

int i,j;

double L, dx;
int N;
double u0;              /*Initial flat value*/

char *ptr;
int n_args = 2;         /*Number of required arguments*/
if (argc <= n_args){
    printf("Not enought input arguments");
    return 0;
}
L = strtod(argv[1], &ptr);
u0 = strtod(argv[2], &ptr);

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
        fprintf(fileinit, "%.5f %.5f %.20f\n", x, y, u0);
    }
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
