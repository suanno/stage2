# How to compile

    gcc tdgl.c -fopenmp -lfftw3 -lm -lfftw3_omp -O2 -o ./.bin/tdgl

# How to make a simulation

    ./.bin/tdgl <tspan> "fileCin.dat" <readFromTop> <loopRead>

- readFromTop (default: 0):
    
    If it is 1, then the reading of "fileCin.dat" does not start from the initial time of the state, but from the top of the .dat file (from the value of $C(t)$ at $t=0$).

- loopRead (default: 0):

    If it is 1, if "fileCin.dat" is too short respect to _tspan_, instead of getting an error, the code continues to read $C(t)$ values resuming from the top of the file. 
