# FFTW float or double precision?
There are two "plans"
- _fftwf\_plan\_dft\_1d_: that accepts float inputs
- _fftw\_plan\_dft\_1d_: that accepts double inputs

so we expect that by using the second function we have double precision.

### 'My' test "_test\_fftw.c_"
In _test\_fftw.c_ code we test wheter fftw threats the input data as float or double:
- It generates an array of N random double number and another array
      of the SAME numbers, BUT casted to float.
- Then executes the FFTW algorithm on both the arrays (separately) and
      calculates the euclidean distance of the corrispondent (one in each of the two arrays) FFT coefficients.
- It prints the maximum distance


If the FFTW threated the input data with single-precision (as float numbers), then we
      would get a zero maximum distance.
      If the distance is not zero, it's not so.
      
**BUT** it could be that it sees the input numbers as double, but then makes some float operation
      within the algorith.
      In this case the maximum distance won't be zero!