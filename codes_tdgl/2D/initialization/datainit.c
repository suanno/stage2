//#include <iostream.h>
//#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include<math.h>
#include<stdlib.h>
#include<omp.h>

#define pi  4*atan(1.0)
#define num_obs 4

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

double L, dx, dt; int N;    /*Lattice parameters*/
double u0;                  /*Roughness of the initial state (centered in u=0)*/
char* simul_name;           /*Name of the folder of savings*/
double hmoy = 0.0;          /*Center of the initial state (default u = 0)*/


/* Read CMD parameters */
char *ptr;
int n_args = 3;         /*Number of required arguments*/
                        /*L, u0, simulation name*/
if (argc <= n_args){
    printf("Not enought input arguments");
    return 0;
}
L = strtod(argv[1], &ptr);
u0 = strtod(argv[2], &ptr);
simul_name = argv[3];
/*
if (argc > n_args + 1)
    hmoy = strtod(argv[n_args + 1], &ptr);
*/

/* Read parameters from params.txt */
FILE *fileparams;
fileparams = fopen("params.txt", "r");
fscanf(fileparams, "dx = %lf\ndt = %lf", &dx, &dt);
fclose(fileparams);

N = (int)(L/dx);
dx = (double)L/N;
printf("New dx = %lf\n", dx);

/* Prepare the save folder */
FILE* filestate;
FILE* fileinit;
double x, y;
char* save_dir = malloc(strlen(".saves")+1+strlen(simul_name));
strcpy(save_dir, ".saves/"); /* copy name into the new var */
strcat(save_dir, simul_name); /* add the extension */
mkdir(save_dir, 0700);
/* Prepare the initial state */
char* state_dir = malloc(strlen(save_dir)+1+strlen("state.dat"));
strcpy(state_dir, save_dir);
strcat(state_dir, "/state.dat");
filestate = fopen(state_dir, "w");
/*Backup the initial state (init.dat)*/
strcpy(state_dir, save_dir);
strcat(state_dir, "/init.dat");
fileinit = fopen(state_dir, "w");
fprintf(fileinit, "%d %lf %lf\n", N, 0.0, dx);
fprintf(filestate, "%d %lf %lf\n", N, 0.0, dx);
//#pragma omp parallel for  /*I want the x,y to be SORTED in the state.dat file. So no parallel!*/
for (i=0; i<N; i++){
    for (j=0; j<N; j++){
        x = i*dx;
        y = j*dx;
        fprintf(fileinit, "%.5f %.5f %.20f\n", x, y, randU(hmoy - u0, hmoy + u0));
        fprintf(filestate, "%.5f %.5f %.20f\n", x, y, randU(hmoy - u0, hmoy + u0));
    }
}
printf("State prepared at: %s\n", state_dir);
free(state_dir);
fclose(fileinit);
fclose(filestate);
/* Copy parameters file */
char* params_dir = malloc(strlen(".saves")+1+strlen(simul_name)+1+strlen("params.txt"));
strcpy(params_dir, save_dir);
strcat(params_dir, "/params.txt");
fileinit = fopen(params_dir, "w");
fprintf(fileinit, "dx = %lf\ndt = %lf", dx, dt);
free(params_dir);

/* Prepare observable folders */
char observables[num_obs][20] = {"/fileQ2.dat", "/fileGrad2.dat", "/fileCout.dat", "/fileAveout.dat"};
for (int i = 0; i < num_obs; i++){
    char* obs_dir = malloc(strlen(save_dir)+1+strlen(observables[i]));
    strcpy(obs_dir, save_dir);
    strcat(obs_dir, observables[i]);
    fileinit = fopen(obs_dir, "w");
    fclose(fileinit);
    free(obs_dir);
}
free(save_dir);


/*
fileinit = fopen("fileGrad2.dat", "w");
fclose(fileinit);
fileinit = fopen("fileCout.dat", "w");
fclose(fileinit);
fileinit = fopen("fileAveout.dat", "w");
fclose(fileinit);
fileinit = fopen("stateFFT.dat", "w");
fclose(fileinit);
*/

}
