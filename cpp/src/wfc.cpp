/**
*******************************************
* Author:       Debaditya Bhattacharya    *
* Email:        debbh@iitk.ac.in          *
* Affiliation:  IIT Kanpur                *
* Course:       IDC606A                   *
* Instructor:   Prof. Mahindra Verma      *
*                                         *
* File Name:    wfc.cpp                   *
* Description:  Contians functions used   *
*               in overall simulation     *
*******************************************
**/
#include "wfc.hpp"
#include <complex>
#include <iostream>

/**
 * @brief Allocates memory for the variables to be used.
 * 
 */
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

/**
 * @brief Create a 1D Gaussian wave function according to the parameters defined in param.
 * 
 */
void WFC::set_psi_1D()
{
    std::complex<double> img(0, 1.0);
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] = exp(-(pow(param->x1[i] - param->psiX1Offset, 2.0) * 0.5 + param->psiV1Offset * param->x1[i] * 1.0 * img));
    }
    // Normalize WFC
    double x = 1 / sqrt(this->norm());
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] *= x;
    }
}

/**
 * @brief Create a 2D Gaussian wave function according to the parameters defined in param.
 * 
 */
void WFC::set_psi_2D()
{
    std::complex<double> img(0, 1.0);
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            psi[i * Nx + j] = exp(-(
                (pow(param->x1[i] - param->psiX1Offset, 2.0) + pow(param->x2[j] - param->psiX2Offset, 2.0)) * 0.5 +
                (param->psiV1Offset * param->x1[i] + param->psiV2Offset * param->x2[j]) * 1.0 * img));
        }
    }
    // Normalize WFC
    double x = sqrt(1 / this->norm());
    for (int i = 0; i < param->Nx * param->Nx; i++)
    {
        psi[i] *= x;
    }
}


/**
 * @brief Create a 3D Gaussian wave function according to the parameters defined in param.
 * 
 */
void WFC::set_psi_3D()
{
    std::complex<double> img(0, 1.0);
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                psi[(i * Nx + j) * Nx + k] = exp(-(
                    (pow(param->x1[i] - param->psiX1Offset, 2.0) + pow(param->x2[j] - param->psiX2Offset, 2.0) + pow(param->x3[k] - param->psiX3Offset, 2.0)) * 0.5 +
                    (param->psiV1Offset * param->x1[i] + param->psiV2Offset * param->x2[j] + param->psiV3Offset * param->x3[k]) * 1.0 * img));
            }
        }
    }
    // Normalize WFC
    double x = sqrt(1 / this->norm());
    for (int i = 0; i < Nx * Nx * Nx; i++)
    {
        psi[i] *= x;
    }
}


/**
 * @brief Set the potential for a 1D system. (Harmonic Potential)
 * 
 */
void WFC::set_V_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        V[i] = pow(param->x1[i], 2.0);
    }
}

/**
 * @brief Set the potential for a 2D system. (Harmonic Potential)
 * 
 */
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


/**
 * @brief Set the potential for a 3D system. (Harmonic Potential)
 * 
 */
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


/**
 * @brief Set the kinetic terms for a 1D system.
 * 
 */
void WFC::set_K_1D()
{
    std::complex<double> img(0, 1.0);
    for (int i = 0; i < param->Nx; i++)
    {
        K[i] = exp(-pow(param->k1[i], 2.0) * 0.5 * img * param->dt);
    }
}


/**
 * @brief Set the kinetic terms for a 2D system.
 * 
 */
void WFC::set_K_2D()
{
    std::complex<double> img(0, 1.0);
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            K[i * param->Nx + j] = exp(-(pow(param->k1[i], 2.0) + pow(param->k2[j], 2.0)) * 0.5 * img * param->dt);
        }
    }
}


/**
 * @brief Set the kinetic terms for a 3D system.
 * 
 */
void WFC::set_K_3D()
{
    std::complex<double> img(0, 1.0);
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                K[(i * Nx + j) * Nx + k] = exp(-(pow(param->k1[i], 2.0) + pow(param->k2[j], 2.0) + +pow(param->k3[k], 2.0)) * 0.5 * img * param->dt);
            }
        }
    }
}

/**
 * @brief Set the real time evolution terms for a 1D system.
 * 
 */
void WFC::set_R_1D()
{
    std::complex<double> img(0, 1.0);
    for (int i = 0; i < param->Nx; i++)
    {
        R[i] = exp(-V[i] * 0.5 * img * param->dt);
    }
}


/**
 * @brief Set the real time evolution terms for a 2D system.
 * 
 */
void WFC::set_R_2D()
{
    std::complex<double> img(0, 1.0);
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            R[i * param->Nx + j] = exp(-V[i * param->Nx + j] * 0.5 * img * param->dt);
        }
    }
}

/**
 * @brief Set the real time evolution terms for a 3D system.
 * 
 */
void WFC::set_R_3D()
{
    std::complex<double> img(0, 1.0);
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                R[(i * Nx + j) * Nx + k] = exp(-V[(i * Nx + j) * Nx + k] * 0.5 * img * param->dt);
            }
        }
    }
}

/**
 * @brief Perform 1D half step in real space.
 * 
 */
void WFC::R_half_step_1D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] *= R[i];
    }
}

/**
 * @brief Perform 2D half step in real space.
 * 
 */
void WFC::R_half_step_2D()
{
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            psi[i * param->Nx + j] *= R[i * param->Nx + j];
        }
    }
}

/**
 * @brief Perform 3D half step in real space.
 * 
 */
void WFC::R_half_step_3D()
{
    int Nx = param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                psi[(i * Nx + j) * Nx + k] *= R[(i * Nx + j) * Nx + k];
            }
        }
    }
}


/**
 * @brief Perform 1D step in momentum space. Wave function is normalizied for FT also. 
 * 
 */
void WFC::K_full_step_1D()
{
    double x = 1.0 / param->Nx;
    for (int i = 0; i < param->Nx; i++)
    {
        psi[i] *= K[i]*x;
    }
}

/**
 * @brief Perform 2D step in momentum space. Wave function is normalizied for FT also. 
 * 
 */
void WFC::K_full_step_2D()
{
    double x = 1.0 / (param->Nx*param->Nx);
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            psi[i * param->Nx + j] *= K[i * param->Nx + j]*x;
        }
    }
}


/**
 * @brief Perform 3D step in momentum space. Wave function is normalizied for FT also. 
 * 
 */
void WFC::K_full_step_3D()
{
    long Nx = param->Nx;
    double x = 1.0 / (Nx*Nx*Nx);
    for (int i = 0; i < param->Nx; i++)
    {
        for (int j = 0; j < param->Nx; j++)
        {
            for (int k = 0; k < param->Nx; k++)
            {
                psi[(i * Nx + j) * Nx + k] *= K[(i * Nx + j) * Nx + k]*x;
            }
        }
    }
}

/**
 * @brief Setup FFTW plan for 1D FT transorms.
 * 
 */
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


/**
 * @brief Setup FFTW plan for 2D FT transorms.
 * 
 */
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


/**
 * @brief Setup FFTW plan for 3D FT transorms.
 * 
 */
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


/**
 * @brief Perform a time evolution step.
 * 
 */
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


/**
 * @brief Simulate the system by performing multiple steps
 * 
 * @param nSteps Number of steps to simulate
 */
void WFC::simulate(int nSteps)
{
    for (int n = 0; n < nSteps; n++)
    {
        step();
    }
}

/**
 * @brief Construct a new WFC::WFC object
 * 
 * @param p Pointer to Params object
 */
WFC::WFC(Param *p)
{
    param = p;
    alloc_var();
    reset_WFC();
}

/**
 * @brief Reset the wave function to original condtions. Also used to intialize the wavefunction for the first time.
 * 
 */
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

/**
 * @brief Calculate the norm of the probability distribution. Should be equal to 1.
 * 
 * @return double Norm.
 */
double WFC::norm()
{
    double norm = 0;
    long N = param->Nx;
    if (param->dims == 2)
        N = param->Nx * param->Nx;
    else if (param->dims == 3)
        N = param->Nx * param->Nx * param->Nx;

    for (long i = 0; i < N; i++)
    {
        norm += real(psi[i] * conj(psi[i]));
    }
    return norm;
}

/**
 * @brief Calculate the energy of the wavefunction. Should be constant for a closed system.
 * The energy is calculated as <psi|H|psi>. 
 * 
 * @return double Energy.
 */
double WFC::energy()
{
    double energy = 0;
    long N = param->Nx;
    if (param->dims == 2)
        N = param->Nx * param->Nx;
    if (param->dims == 3)
        N = param->Nx * param->Nx * param->Nx;
    
    // Init array to keep psi copy and psi conjugate.
    std::complex<double> psi_copy[N];
    std::complex<double> psi_conj[N];
    for (long i = 0; i < N; i++)
    {
        psi_copy[i] = psi[i];
        psi_conj[i] = conj(psi[i]);
    }
    fftw_execute(FT_forward_plan);
    double x = 1.0/N;
    for (long i = 0; i < N; i++)
    {
        psi[i] = psi[i] * K[i] * K[i]*x;
    }
    fftw_execute(FT_backward_plan);
    for (long i = 0; i < N; i++)
    {
        energy += real(0.5 * psi_conj[i] * psi[i] + psi_conj[i] * V[i] * psi_copy[i]);
        psi[i] = psi_copy[i];
    }
    energy *= param->dx;
    if (param->dims == 2)
    {
        energy *= param->dx;
    }
    if (param->dims == 3)
    {
        energy *= param->dx * param->dx;
    }
    return energy;
}