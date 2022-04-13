#include "wfc.h"
#include <complex>
#include <iostream>

using namespace std::complex_literals;

void WFC::alloc_var()
{
    if (param->dims == 1)
    {
        psi = new std::complex<double>[param->Nx];
        V = new std::complex<double>[param->Nx];
        R = new std::complex<double>[param->Nx];
        K = new std::complex<double>[param->Nx];
    }
    if (param->dims == 2)
    {
        psi = new std::complex<double>[param->Nx * param->Nx];
        V = new std::complex<double>[param->Nx * param->Nx];
        R = new std::complex<double>[param->Nx * param->Nx];
        K = new std::complex<double>[param->Nx * param->Nx];
    }
    if (param->dims == 3)
    {
        psi = new std::complex<double>[param->Nx * param->Nx * param->Nx];
        V = new std::complex<double>[param->Nx * param->Nx * param->Nx];
        R = new std::complex<double>[param->Nx * param->Nx * param->Nx];
        K = new std::complex<double>[param->Nx * param->Nx * param->Nx];
    }
}

void WFC::set_psi_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] = exp(-(pow(param->x1[i] - param->psiX1Offset, 2.0) * 0.5 + param->psiV1Offset * param->x1[i] * 1.0i));
    }
    // Normalize WFC
    double x = 1 / sqrt(this->norm());
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] *= x;
    }
}
void WFC::set_psi_2D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            psi[i * Nx + j] = exp(-(
                (pow(param->x1[i] - param->psiX1Offset, 2.0) + pow(param->x2[j] - param->psiX2Offset, 2.0)) * 0.5 +
                (param->psiV1Offset * param->x1[i] + param->psiV2Offset * param->x2[j]) * 1.0i));
            // std::cout<<" "<<psi[i * Nx + j];
        }
    }
    // Normalize WFC
    double x = sqrt(1 / this->norm());
    // std::cout<<x<<" ";
    for (int i = 0; i < param->Nx * param->Nx; i++)
    {
        psi[i] *= x;
    }
}

void WFC::set_psi_3D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                psi[(i * Nx + j) * Nx + k] = exp(-(
                    (pow(param->x1[i] - param->psiX1Offset, 2.0) + pow(param->x2[j] - param->psiX2Offset, 2.0) + pow(param->x3[k] - param->psiX3Offset, 2.0)) * 0.5 +
                    (param->psiV1Offset * param->x1[i] + param->psiV2Offset * param->x2[j] + param->psiV3Offset * param->x3[k]) * 1.0i));
            }
        }
    }
    double x = sqrt(1 / this->norm());
    for (int i = 0; i < Nx * Nx * Nx; i++)
    {
        psi[i] *= x;
    }
}

void WFC::set_V_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        V[i] = pow(param->x1[i], 2.0);
    }
}

void WFC::set_V_2D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            V[i * param->Nx + j] = pow(param->x1[i], 2.0) + pow(param->x2[j], 2.0);
        }
    }
}

void WFC::set_V_3D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                V[(i * Nx + j) * Nx + k] = pow(param->x1[i], 2.0) + pow(param->x2[j], 2.0) + +pow(param->x3[k], 2.0);
            }
        }
    }
}

void WFC::set_K_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        K[i] = exp(-pow(param->k1[i], 2.0) * 0.5i * param->dt);
    }
}

void WFC::set_K_2D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            K[i * param->Nx + j] = exp(-(pow(param->k1[i], 2.0) + pow(param->k2[j], 2.0)) * 0.5i * param->dt);
        }
    }
}

void WFC::set_K_3D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                K[(i * Nx + j) * Nx + k] = exp(-(pow(param->k1[i], 2.0) + pow(param->k2[j], 2.0) + +pow(param->k3[k], 2.0)) * 0.5i * param->dt);
            }
        }
    }
}
void WFC::set_R_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        R[i] = exp(-V[i] * 0.5i * param->dt);
    }
}

void WFC::set_R_2D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            R[i * param->Nx + j] = exp(-V[i * param->Nx + j] * 0.5i * param->dt);
        }
    }
}

void WFC::set_R_3D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                R[(i * Nx + j) * Nx + k] = exp(-V[(i * Nx + j) * Nx + k] * 0.5i * param->dt);
            }
        }
    }
}

void WFC::R_half_step_1D()
{
    double x = 1 / sqrt(param->Nx);
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] *= R[i] * x;
    }
}

void WFC::R_half_step_2D()
{
    double x = 1 / double(param->Nx);
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            psi[i * param->Nx + j] *= R[i * param->Nx + j] * x;
        }
    }
}

void WFC::R_half_step_3D()
{
    double x = 1 / (double(param->Nx) * sqrt(param->Nx));
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                psi[(i * Nx + j) * Nx + k] *= R[(i * Nx + j) * Nx + k] * x;
            }
        }
    }
}

void WFC::K_full_step_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] *= K[i];
    }
}

void WFC::K_full_step_2D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            psi[i * param->Nx + j] *= K[i * param->Nx + j];
        }
    }
}

void WFC::K_full_step_3D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                psi[(i * Nx + j) * Nx + k] *= K[(i * Nx + j) * Nx + k];
            }
        }
    }
}

void WFC::FT_1D()
{
    int n[1];
    n[0] = param->Nx;
    FT_forward_plan = fftw_plan_dft(1, n,
                                    reinterpret_cast<fftw_complex *>(psi),
                                    reinterpret_cast<fftw_complex *>(psi),
                                    FFTW_FORWARD, FFTW_ESTIMATE);
    FT_backward_plan = fftw_plan_dft(1, n,
                                     reinterpret_cast<fftw_complex *>(psi),
                                     reinterpret_cast<fftw_complex *>(psi),
                                     FFTW_BACKWARD, FFTW_ESTIMATE);
}

void WFC::FT_2D()
{
    int n[2];
    n[0] = param->Nx;
    n[1] = param->Nx;
    FT_forward_plan = fftw_plan_dft(2, n,
                                    reinterpret_cast<fftw_complex *>(psi),
                                    reinterpret_cast<fftw_complex *>(psi),
                                    FFTW_FORWARD, FFTW_ESTIMATE);
    FT_backward_plan = fftw_plan_dft(2, n,
                                     reinterpret_cast<fftw_complex *>(psi),
                                     reinterpret_cast<fftw_complex *>(psi),
                                     FFTW_BACKWARD, FFTW_ESTIMATE);
}

void WFC::FT_3D()
{
    int n[3];
    n[0] = param->Nx;
    n[1] = param->Nx;
    n[2] = param->Nx;
    FT_forward_plan = fftw_plan_dft(3, n,
                                    reinterpret_cast<fftw_complex *>(psi),
                                    reinterpret_cast<fftw_complex *>(psi),
                                    FFTW_FORWARD, FFTW_ESTIMATE);
    FT_backward_plan = fftw_plan_dft(3, n,
                                     reinterpret_cast<fftw_complex *>(psi),
                                     reinterpret_cast<fftw_complex *>(psi),
                                     FFTW_BACKWARD, FFTW_ESTIMATE);
}

void WFC::step()
{

    if (param->dims == 1)
    {
        R_half_step_1D();
        fftw_execute(FT_forward_plan);
        K_full_step_1D();
        fftw_execute(FT_backward_plan);
        R_half_step_1D();
    }
    else if (param->dims == 2)
    {
        R_half_step_2D();
        fftw_execute(FT_forward_plan);
        K_full_step_2D();
        fftw_execute(FT_backward_plan);
        R_half_step_2D();
    }
    else if (param->dims == 3)
    {
        R_half_step_3D();
        fftw_execute(FT_forward_plan);
        K_full_step_3D();
        fftw_execute(FT_backward_plan);
        R_half_step_3D();
    }
}

void WFC::simulate(int nSteps)
{
    for (int n = 0; n < nSteps; n++)
    {
        step();
        if (n % 1000 == 0)
        {
            std::cout << "Normalization = " << norm() << std::endl;
        }
    }
}

WFC::WFC(Param *p)
{
    param = p;
    alloc_var();
    reset_WFC();
}

void WFC::reset_WFC()
{
    if (param->dims == 1)
    {
        set_V_1D();
        set_R_1D();
        set_K_1D();
        set_psi_1D();
        FT_1D();
    }
    else if (param->dims == 2)
    {
        set_V_2D();
        set_R_2D();
        set_K_2D();
        set_psi_2D();
        FT_2D();
    }

    else if (param->dims == 3)
    {
        set_V_3D();
        set_R_3D();
        set_K_3D();
        set_psi_3D();
        FT_3D();
    }
    return;
}

double WFC::norm()
{
    double norm = 0;
    int N = param->Nx;
    if (param->dims == 2)
        N = param->Nx * param->Nx;
    else if (param->dims == 3)
        N = param->Nx * param->Nx * param->Nx;

    for (int i = 0; i < N; i++)
    {
        norm += real(psi[i] * conj(psi[i]));
    }
    return norm;
}