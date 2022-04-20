/**
*******************************************
* Author:       Debaditya Bhattacharya    *
* Email:        debbh@iitk.ac.in          *
* Affiliation:  IIT Kanpur                *
* Course:       IDC606A                   *
* Instructor:   Prof. Mahindra Verma      *
*                                         *
* File Name:    util.cpp                  *
* Description:  Contians functions used   *
*               in overall simulation     *
*******************************************
**/
#include <iostream>
#include <chrono>
#include <string.h>
#include <wchar.h>
#include <unistd.h>
#include <iomanip>
#include "util.hpp"
#include "wfc.hpp"

/**
 * @brief Overall simulation runner.
 *
 * @param i Number of timesteps
 * @param param Pointer to param object.
 */
void simulation(int i, Param *param)
{
    // Initialize Phase
    auto start = std::chrono::steady_clock::now();
    WFC wfc(param);
    auto finish = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    if (param->verbose)
        std::cout << i << "\t"
                  << duration << "\t";

    // Verify initial
    double norm_i, norm_f;
    double energy_i, energy_f;
    if (param->verify)
    {
        norm_i = wfc.norm();
        energy_i = wfc.energy();
    }

    // Run simulation
    start = std::chrono::steady_clock::now();
    wfc.simulate(param->timesteps);
    finish = std::chrono::steady_clock::now();

    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
    if (param->verbose)
        std::cout << duration;

    // Verify final

    if (param->verify)
    {
        norm_f = wfc.norm();
        energy_f = wfc.energy();
        std::cout << std::setprecision(5)<< "\t" <<norm_i << "\t" << norm_f << "\t"<<  energy_i <<"\t" << energy_f;
    }
    std::cout << std::endl;
}

/**
 * @brief Set the params object
 *
 * @param argc
 * @param argv
 * @return Param
 */
Param set_params(int argc, char **argv)
{

    Param param;
    // Default params
    param.dims = 1;
    param.xmax = 5;
    param.res = 2 << 10;
    param.Nx = 2 * param.res;
    param.dt = 0.0001;
    param.timesteps = 10000;
    param.im_time = false;
    param.dx = 2 * param.xmax / param.res;
    param.dk = M_PI / param.xmax;

    param.psiX1Offset = 0.0;
    param.psiX2Offset = 0.0;
    param.psiX3Offset = 0.0;

    param.psiV1Offset = 1.0;
    param.psiV2Offset = 1.0;
    param.psiV3Offset = 1.0;

    param.verbose = false;
    param.verify = false;
    param.iter = 1;

    // Take user input for params
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-iter") == 0)
            param.iter = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-dims") == 0)
            param.dims = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-xmax") == 0)
            param.xmax = atof(argv[i + 1]);

        if (strcmp(argv[i], "-res") == 0)
            param.res = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-dims") == 0)
            param.dims = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-dt") == 0)
            param.dt = atof(argv[i + 1]);

        if (strcmp(argv[i], "-timesteps") == 0)
            param.timesteps = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-im_time") == 0)
            param.im_time = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-psiX1Offset") == 0)
            param.psiX1Offset = atof(argv[i + 1]);

        if (strcmp(argv[i], "-psiX2Offset") == 0)
            param.psiX2Offset = atof(argv[i + 1]);

        if (strcmp(argv[i], "-psiX3Offset") == 0)
            param.psiX3Offset = atof(argv[i + 1]);

        if (strcmp(argv[i], "-psiV1Offset") == 0)
            param.psiV1Offset = atof(argv[i + 1]);

        if (strcmp(argv[i], "-psiV2Offset") == 0)
            param.psiV2Offset = atof(argv[i + 1]);

        if (strcmp(argv[i], "-psiV3Offset") == 0)
            param.psiV3Offset = atof(argv[i + 1]);

        if (strcmp(argv[i], "-verbose") == 0)
            param.verbose = atoi(argv[i + 1]);

        if (strcmp(argv[i], "-verify") == 0)
            param.verify = atoi(argv[i + 1]);
        i += 2;
    }

    // Set derived parameters
    param.Nx = 2 * param.res;
    param.dx = param.xmax / param.res;
    param.dk = M_PI / param.xmax;

    // Init parameter class by malloc.
    param.init_param();

    return param;
}