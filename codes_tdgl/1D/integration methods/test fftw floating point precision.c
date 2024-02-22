#include <stdio.h>
#include <stdlib.h>
#include <fftw3.h>
#include <math.h>

#define N 1024

int main() {
    /*The following code tests if the "fftw" FFT algorithm has
      double-precision accuracy.
      - It generates an array of N random double number and another array
      of the SAME numbers, BUT casted to float.
      - Then executes the FFTW algorithm on both the arrays (separately) and
      calculates the euclidean distance of the corrispondent (one in each of the two arrays) FFT coefficients.
      - It prints the maximum distance

      If the FFTW threated the input data with single-precision (as float numbers), then we
      would get a zero maximum distance.
      If the distance is not zero, it's not so.
      
      BUT it could be that it sees the input numbers as double, but then makes some float operation
      within the algorith.
      In this case the maximum distance won't be zero!
      
      */


    fftw_complex *in_double, *in_single, *out_double, *out_single;
    //float *in_single;
    fftw_plan p_double, p_single;
    int i;

    // Allocate memory for input and output arrays
    in_double = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    in_single = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out_double = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    out_single = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

    // Create FFTW plans
    p_double = fftw_plan_dft_1d(N, in_double, out_double, FFTW_FORWARD, FFTW_ESTIMATE);
    p_single = fftw_plan_dft_1d(N, in_single, out_single, FFTW_FORWARD, FFTW_ESTIMATE);
    
    // Generate random input data in double precision
    for (i = 0; i < N; ++i) {
        in_double[i][0] = (double) rand() / RAND_MAX; // Real part
        in_double[i][1] = (double) rand() / RAND_MAX; // Imaginary part
    }

    // Perform FFT with double precision
    fftw_execute(p_double);

    // Convert input data to single precision
    //in_single = (float*) malloc(sizeof(float) * 2 * N);
    for (i = 0; i < N; ++i) {
        in_single[i][0] = (float) in_double[i][0]; // Real part
        in_single[i][1] = (float) in_double[i][1]; // Imaginary part
    }

    // Perform FFT with single precision
    fftw_execute(p_single); // repeat as needed
    fftw_execute(p_double); // repeat as needed

    // Calculate maximum absolute difference
    double max_abs_diff = 0;
    for (i = 0; i < N; ++i) {
        double diff_real = fabs(out_double[i][0] - out_single[i][0]);
        double diff_imag = fabs(out_double[i][1] - out_single[i][1]);
        double abs_diff = sqrt(diff_real * diff_real + diff_imag * diff_imag);
        if (abs_diff > max_abs_diff) {
            max_abs_diff = abs_diff;
        }
    }

    printf("Maximum absolute difference between double precision FFT and single precision FFT: %f\n", max_abs_diff);

    // Free memory and destroy plans
    fftw_destroy_plan(p_double);
    fftw_destroy_plan(p_single);
    fftw_free(in_double);
    fftw_free(out_double);
    fftw_free(out_single);
    free(in_single);

    return 0;
}
