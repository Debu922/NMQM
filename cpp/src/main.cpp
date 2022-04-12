/*
Schrodinger Wave Equation Solver
1) FFTW
2) CuFFT + CuBLAS
*/
#include <iostream>
#include <iomanip>
#include <complex.h>
// #include <bits/stdc++.h>
// #include <cufft.h>
#include <fftw3.h>
#include <chrono>


using namespace std::complex_literals;
using namespace std::chrono;


class Param
{
public:
  double xmax = 20;
  int res = 2 << 10;
  int Nx = 2 * res;
  double dt = 0.0001;
  int timesteps = 10000;
  bool im_time = false;
  double dx = 2 * xmax / res;
  double dk = M_PI / xmax;
  double vel = 0.0;
  double wfcoffset = 0.0;
  std::complex<double> *x;
  std::complex<double> *k;

  void init_variables(){
    this->x = new std::complex<double>[this->Nx]; 
    this->k = new std::complex<double>[this->Nx]; 
  }

  void set_x()
  {
    for (int i = 0; i < this->Nx; i++)
    {
      this->x[i] = (-this->xmax + this->xmax / this->res + i * this->dx);
    }
    return;
  }

  void set_k()
{
  for (int i = 0; i < this->Nx / 2; i++)
  {
    k[i] = i * this->dk;
    k[this->Nx - i - 1] = k[i];
  }
  return;
}

  Param()
  {
    this->init_variables();
    this->set_x();
    this->set_k();
  }

  void set_x(double *x, Param param);
  void set_k(double *k, Param param);
};

/**
 * @brief The Wave Function class 
 * 
 */
class WFC{
public:
Param *param;
std::complex<double> *V;
std::complex<double> *wfc;
std::complex<double> *K;
std::complex<double> *R;

/**
 * @brief Set the wfc object to its intial state.
 * 
 */
void set_wfc(){
  wfc = new std::complex<double>[this->param->Nx];
  for (int i = 0; i<this->param->Nx; i++){
    std::complex<double> *x, wfcoffset, vel;
    x = this->param->x;
    wfcoffset = this->param->wfcoffset;
    vel = this->param->vel;
    wfc[i] = exp(-(pow(x[i]-wfcoffset,2.0) *0.5 + vel*x[i]*1.0i));
  }
}

/**
 * @brief Set the potential function
 * 
 */
void set_V(){
  V = new std::complex<double>[this->param->Nx];
  for (int i = 0; i<param->Nx; i++){
    V[i] = 0;
  }
}

/**
 * @brief set the K obj
 * 
 */
void set_K(){
  K = new std::complex<double>[this->param->Nx];
  for (int i = 0; i<param->Nx; i++){
    std::complex<double> *k;
    k = param->k;
    k[i] = exp(-pow(k[i],2.0) *0.5i* param->dt);
  }
}

void set_R(){
  R = new std::complex<double>[this->param->Nx];
  for (int i = 0; i<param->Nx; i++){
    R[i] = exp(-V[i]*0.5i* param->dt);
  }
}

  WFC(Param *param){
    this->param = param;
    set_V();
    set_R();
    set_K();
    set_wfc();
  }
};

void split_op(Param *p, WFC *wfc){
  int rank = 1;
  int n[1];
  n[0] = p->Nx;
  fftw_plan plan_fwd = fftw_plan_dft(1, n,
                        reinterpret_cast<fftw_complex*>(wfc->wfc), 
                        reinterpret_cast<fftw_complex*>(wfc->wfc),
                        FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_plan plan_backwd = fftw_plan_dft(1, n,
                        reinterpret_cast<fftw_complex*>(wfc->wfc), 
                        reinterpret_cast<fftw_complex*>(wfc->wfc),
                        FFTW_BACKWARD, FFTW_ESTIMATE);                      

  // std::cout<<wfc->wfc[p->Nx];

  for(int t = 0; t<p->timesteps;t++){
    // Half-step in real space

    for(int i = 0; i < p->Nx; i++){
      wfc->wfc[i] *= wfc->R[i];
    }
    // FFT to momentum space 
    fftw_execute(plan_fwd);

    // Full step in momentum space
    for(int i = 0; i < p->Nx; i++){
      wfc->wfc[i] *= wfc->K[i];
    }

    // iFFT to real space
    fftw_execute(plan_backwd);

    // Half-step in real space
    for(int i = 0; i < p->Nx; i++){
      wfc->wfc[i] *= wfc->R[i];
    }
  }
}

int main()
{
  // Paramaters
  Param param;
  WFC wfc(&param);

  auto start = high_resolution_clock::now();
  split_op(&param, &wfc);
  auto stop = high_resolution_clock::now();
  // Set Intial Conditions

  auto duration = duration_cast<milliseconds>(stop - start);
 
    std::cout << "Time taken by function: "
         << duration.count() << " ms" << std::endl;

  return 0;
}
