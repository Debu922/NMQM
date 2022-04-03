/*
Schrodinger Wave Equation Solver
1) FFTW
2) CuFFT + CuBLAS
*/
#include <iostream>
#include <iomanip>
#include <cufft.h>
#include <fftw3.h>
#include <math.h>
// #include "gnuplot-iostream.h"


#define NX 256
#define BATCH 10

// __global__ void saxpy_cuda(int n, float a, float *x, float *y)
// {
//   int i = blockIdx.x * blockDim.x + threadIdx.x;
//   if (i < n)
//     y[i] = a * x[i] + y[i];
// }

// void saxpy(int n, float a, float *x, float *y)
// {

// }

// class Param
// {
// public:
//   int dims;
//   _Float64 dt;
//   int64_t res;
//   int64_t timesteps;
//   _Float64 ds;
//   _Float64 dk;
//   _Float64 xmax;
//   _Float64 ymax;
//   _Float64 zmax;

//   Param(int dims_in,
//         _Float64 xmax_in,
//         _Float64 dt_in,
//         int64_t res_in,
//         int64_t timesteps,
//         _Float64 dims,
//         _Float64 dk)
//   {
//     dims = dims_in;
//     xmax = xmax_in
//   }
// };

void display(fftw_complex *x, int N){
  std::cout<<std::setprecision(2);
  for(int i = 0; i<N; i++){
    std::cout<<x[i++][0]<<" +\ti"<<x[i][1]<<"\t ";
    std::cout<<x[i++][0]<<"\t+i"<<x[i][1]<<"\t ";
    std::cout<<x[i++][0]<<"\t+i"<<x[i][1]<<"\t ";
    std::cout<<x[i][0]<<"\t+i"<<x[i][1]<<"\t ";
    std::cout<<std::endl;
  }
}

int main()
{
  // Paramaters


  // Set Intial Conditions
  

  return 0;
}
