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
#include "string.h"


using namespace std::complex_literals;
using namespace std::chrono;

Param set_params(int argc, char** argv);

void simulation(int i, Param *param){

  // INIT PHASE
  auto start = high_resolution_clock::now();
  WFC wfc(param);
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);
  if (param->verbose)
    std::cout << i <<"\t"
      << duration.count() << "\t";

  // RUN SIMULATION
  start = high_resolution_clock::now();
  wfc.simulate(param->timesteps);
  stop = high_resolution_clock::now();

  duration = duration_cast<nanoseconds>(stop - start);
  if (param->verbose)
    std::cout << duration.count()<<std::endl;

}

int main(int argc, char** argv)
{
 
//  Simulation data output
for (int i = 1; i < argc; i++)
  std::cout<<argv[i]<<" ";
std::cout<<std::endl;
Param param = set_params(argc,argv);

for (int i = 0; i<param.iter; i++)
  simulation(i,&param);

std::cout<<std::endl;
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
  // Default params
  param.dims = 1;
  param.xmax = 20;
  param.res = 2 << 5;
  param.dt = 0.0001;
  param.timesteps = 100;
  param.im_time = false;

  param.psiX1Offset = 1.0;
  param.psiX2Offset = 1.0;
  param.psiX3Offset = 1.0;
  param.psiV1Offset = 1.0;
  param.psiV2Offset = 1.0;
  param.psiV3Offset = 1.0;

  int i = 1;
  // std::cout<<argc;
  while (i <= argc){
    if (strcmp(argv[i],"-iter")==0)
      param.iter = std::stoi(argv[i+1]);

    if (strcmp(argv[i] ,"-dims")==0)
      param.dims = std::stoi(argv[i+1]);

    if (strcmp(argv[i] ,"-xmax")==0)
      param.xmax = std::stod(argv[i+1]);
  
    if (strcmp(argv[i] ,"-res")==0)
      param.res = std::stoi(argv[i+1]);
    
    if (strcmp(argv[i] ,"-dims")==0)
      param.dims = std::stoi(argv[i+1]);

    if (strcmp(argv[i] ,"-dt")==0)
      param.dt = std::stod(argv[i+1]);

    if (strcmp(argv[i] ,"-timesteps")==0)
      param.timesteps = std::stoi(argv[i+1]);

    if (strcmp(argv[i] ,"-im_time")==0)
      param.im_time = std::stoi(argv[i+1]);

    if (strcmp(argv[i] ,"-psiX1Offset")==0)
      param.psiX1Offset = std::stod(argv[i+1]);

    if (strcmp(argv[i] ,"-psiX2Offset")==0)
      param.psiX2Offset = std::stod(argv[i+1]);

    if (strcmp(argv[i] ,"-psiX3Offset")==0)
      param.psiX3Offset = std::stod(argv[i+1]);

    if (strcmp(argv[i] ,"-psiV1Offset")==0)
      param.psiV1Offset = std::stod(argv[i+1]);

    if (strcmp(argv[i] ,"-psiV2Offset")==0)
      param.psiV2Offset = std::stod(argv[i+1]);

    if (strcmp(argv[i] ,"-psiV3Offset")==0)
      param.psiV3Offset = std::stod(argv[i+1]);
    
    if (strcmp(argv[i] ,"-verbose")==0)
      param.verbose=true;
    i+=2;
  }

  param.Nx = 2 * param.res;
  param. dx = param.xmax / param.res;
  param. dk = M_PI / param.xmax;

  param.init_param();

  return param;
}
