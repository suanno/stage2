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
double u0;              /*Plateau value is +-u0*/
double r0;              /*Radius of the circular front*/

char *ptr;
int n_args = 3;         /*Number of required arguments*/
if (argc <= n_args){
    printf("Not enought input arguments\n");
    return 0;
}
L = strtod(argv[1], &ptr);
u0 = strtod(argv[2], &ptr);
r0 = strtod(argv[3], &ptr);
if (r0 >= L/2){
    printf("WARNING: Radius of the circle is larger than L/2!!!\n");
}

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
double x, y, r;
fileinit = fopen("state.dat", "w");
fprintf(fileinit, "%d %lf %lf\n", N, 0.0, dx);
//#pragma omp parallel for  /*I want the x,y to be SORTED in the state.dat file. So no parallel!*/
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        x = i*dx;
        y = j*dx;
        /*Formula for a circular front*/
        r = sqrt((x-L/2)*(x-L/2)+(y-L/2)*(y-L/2));
        fprintf(fileinit, "%.5f %.5f %.20f\n", x, y, -u0*tanh((r-r0)/sqrt(2)));
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
