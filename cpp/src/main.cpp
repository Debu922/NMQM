/*
Schrodinger Wave Equation Solver
1) FFTW
*/
#include <iostream>
#include <iomanip>
#include <complex.h>
#include <chrono>
#include "param.h"
#include "wfc.h"


using namespace std::complex_literals;
using namespace std::chrono;

Param set_params(int argc, char** argv);

int main(int argc, char** argv)
{
  // Init simulation
  auto start = high_resolution_clock::now();
  Param param = set_params(argc, argv);
  WFC wfc(&param);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  std::cout << "Time taken to init simulation: "
      << duration.count() << " ms" << std::endl;

  start = high_resolution_clock::now();
  wfc.simulate(param.timesteps);
  stop = high_resolution_clock::now();
  // Set Intial Conditions

  duration = duration_cast<milliseconds>(stop - start);
 
    std::cout << "Time taken to evolve "<<param.timesteps<< " timesteps:  "
         << duration.count() << " ms" << std::endl;

  return 0;
}

Param set_params(int argc, char** argv){

  Param param;
  param.dims = 2;
  param.xmax = 20;
  param.res = 2 << 5;
  param.Nx = 2 * param.res;
  param.dt = 0.0001;
  param.timesteps = 10000;
  param.im_time = false;
  param. dx = param.xmax / param.res;
  param. dk = M_PI / param.xmax;
  param. vel = 0.0;

  param.psiX1Offset = 1.0;
  param.psiX2Offset = 1.0;
  param.psiX3Offset = 1.0;
  param.psiV1Offset = 1.0;
  param.psiV2Offset = 1.0;
  param.psiV3Offset = 1.0;

  param.init_param();

  return param;
}
