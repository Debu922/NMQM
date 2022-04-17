#ifndef __WFC_H__
#define __WFC_H__

#include <complex>
#include "param.h"
#include <fftw3.h>
// using namespace std::complex_literals;

class WFC
{
public:
  Param *param;
  std::complex<double> *V;
  std::complex<double> *psi;
  std::complex<double> *K;
  std::complex<double> *R;
  fftw_plan FT_forward_plan;
  fftw_plan FT_backward_plan;

  void alloc_var();

  void set_psi_1D();
  void set_psi_2D();
  void set_psi_3D();

  void set_V_1D();
  void set_V_2D();
  void set_V_3D();

  void set_K_1D();
  void set_K_2D();
  void set_K_3D();

  void set_R_1D();
  void set_R_2D();
  void set_R_3D();

  void R_half_step_1D();
  void R_half_step_2D();
  void R_half_step_3D();

  void K_full_step_1D();
  void K_full_step_2D();
  void K_full_step_3D();

  void FT();
  void FT_1D();
  void FT_2D();
  void FT_3D();

  void step();
  void simulate(int nSteps);

  WFC(Param *p);
  void reset_WFC();
  double norm();

};

#endif // __WFC_H__