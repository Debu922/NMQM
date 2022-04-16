#ifndef __PARAM_H__
#define __PARAM_H__

#include <complex>

class Init{
  
};

class Param
{
public:
  int dims = 1;
  double xmax = 5;
  int res = 2 << 10;
  int Nx = 2 * res;
  double dt = 0.0001;
  int timesteps = 10000;
  bool im_time = false;
  double dx = 2 * xmax / res;
  double dk = M_PI / xmax;

  double psiX1Offset = 0.0;
  double psiX2Offset = 0.0;
  double psiX3Offset = 0.0;
  
  double psiV1Offset = 1.0;
  double psiV2Offset = 1.0;
  double psiV3Offset = 1.0;

  double verbose = false;
  int iter = 1;
  

  std::complex<double> *x1;
  std::complex<double> *x2;
  std::complex<double> *x3;
  std::complex<double> *k1;
  std::complex<double> *k2;
  std::complex<double> *k3;

  void alloc_vector();
  void set_x_1D();
  void set_x_2D();
  void set_x_3D();

  void set_k_1D();
  void set_k_2D();
  void set_k_3D();

  Param();

  void init_param();

};

#endif // __PARAM_H__