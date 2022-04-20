#ifndef __PARAM_H__
#define __PARAM_H__

#include <complex>

class Init{
  
};

class Param
{
public:
  int dims;
  double xmax;
  int res;
  int Nx;
  double dt;
  int timesteps;
  bool im_time;
  double dx ;
  double dk ;

  double psiX1Offset ;
  double psiX2Offset ;
  double psiX3Offset ;
  
  double psiV1Offset;
  double psiV2Offset;
  double psiV3Offset;

  bool verbose;
  bool verify;
  int iter;
  

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