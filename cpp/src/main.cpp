/*
Schrodinger Wave Equation Solver
DependencesFFTW
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
  // INIT SIMULATION

  // Start Clock
  auto start = high_resolution_clock::now();

  // Init Parameters and WFC
  Param param = set_params(argc, argv);
  WFC wfc(&param);

  // Stop Clock
  auto stop = high_resolution_clock::now();

  // Output init time
  auto duration = duration_cast<milliseconds>(stop - start);
  std::cout << "Time taken to init simulation: "
      << duration.count() << " ms" << std::endl;

  // RUN SIMULATION
  // Start time
  start = high_resolution_clock::now();

  // Simulate
  wfc.simulate(param.timesteps);

  // Stop time
  stop = high_resolution_clock::now();

  // Output simulation time
  duration = duration_cast<milliseconds>(stop - start);
 
    std::cout << "Time taken to evolve "<<param.timesteps<< " timesteps:  "
         << duration.count() << " ms" << std::endl;

  return 0;
}

/**
 * @brief Set the params object
 * 
 * @param argc 
 * @param argv 
 * @return Param 
 */
Param set_params(int argc, char** argv){

  Param param;
  param.dims = 3;
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
