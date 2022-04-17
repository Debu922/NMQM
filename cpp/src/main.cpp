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
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <unistd.h>
 
using namespace std;


Param set_params(int argc, char** argv);

void simulation(int i, Param *param){
  // time_t start, end;
  // INIT PHASE
  // time(&start);
  auto start = std::chrono::steady_clock::now();
  WFC wfc(param);
  // time(&end);
  auto finish = std::chrono::steady_clock::now();


  // double duration = double(end - start);
  auto duration = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();

  if (param->verbose)
    std::cout << i <<"\t"
      << duration << "\t";

  // RUN SIMULATION
start = std::chrono::steady_clock::now();  
wfc.simulate(param->timesteps);
finish = std::chrono::steady_clock::now();

duration = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();  if (param->verbose)
    std::cout << duration<<std::endl;

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
  param. dims = 1;
  param. xmax = 5;
  param. res = 2 << 10;
  param. Nx = 2 *param. res;
  param. dt = 0.0001;
  param. timesteps = 10000;
  param. im_time = false;
  param.dx = 2 * param.xmax /param. res;
  param.dk = M_PI / param.xmax;

  param.psiX1Offset = 0.0;
  param.psiX2Offset = 0.0;
  param.psiX3Offset = 0.0;
  
  param.psiV1Offset = 1.0;
  param.psiV2Offset = 1.0;
  param.psiV3Offset = 1.0;

  param. verbose = false;
  param. iter = 1;
  
  int i = 1;
  // std::cout<<argc;
  while (i <= argc){
    if (strcmp(argv[i],"-iter")==0)
      param.iter = atoi(argv[i+1]);

    if (strcmp(argv[i] ,"-dims")==0)
      param.dims = atoi(argv[i+1]);

    if (strcmp(argv[i] ,"-xmax")==0)
      param.xmax = atof(argv[i+1]);
  
    if (strcmp(argv[i] ,"-res")==0)
      param.res = atoi(argv[i+1]);
    
    if (strcmp(argv[i] ,"-dims")==0)
      param.dims = atoi(argv[i+1]);

    if (strcmp(argv[i] ,"-dt")==0)
      param.dt = atof(argv[i+1]);

    if (strcmp(argv[i] ,"-timesteps")==0)
      param.timesteps = atoi(argv[i+1]);

    if (strcmp(argv[i] ,"-im_time")==0)
      param.im_time = atoi(argv[i+1]);

    if (strcmp(argv[i] ,"-psiX1Offset")==0)
      param.psiX1Offset = atof(argv[i+1]);

    if (strcmp(argv[i] ,"-psiX2Offset")==0)
      param.psiX2Offset = atof(argv[i+1]);

    if (strcmp(argv[i] ,"-psiX3Offset")==0)
      param.psiX3Offset = atof(argv[i+1]);

    if (strcmp(argv[i] ,"-psiV1Offset")==0)
      param.psiV1Offset = atof(argv[i+1]);

    if (strcmp(argv[i] ,"-psiV2Offset")==0)
      param.psiV2Offset = atof(argv[i+1]);

    if (strcmp(argv[i] ,"-psiV3Offset")==0)
      param.psiV3Offset = atof(argv[i+1]);
    
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
