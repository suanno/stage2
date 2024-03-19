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

int N=1000;
double u0;              /*Initial flat value*/
int seed;

seed = time(NULL);
srand(seed);

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
fprintf(fileinit, "%d %d\n", seed, N);
#pragma omp parallel for
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        fprintf(fileinit, "%.20f\n", u0);
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
