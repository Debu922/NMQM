/**
*******************************************
* Author:       Debaditya Bhattacharya    *
* Email:        debbh@iitk.ac.in          *
* Affiliation:  IIT Kanpur                *
* Course:       IDC606A                   *
* Instructor:   Prof. Mahindra Verma      *
*                                         *
* File Name:    main.cpp                  *
* Description:  Main file for Sequential  *
*               Schrodinger Equation      *
*               Solver                    *
*******************************************
**/
#include <iostream>
#include "param.hpp"
#include "wfc.hpp"
#include "util.hpp"

/**
 * @brief main function for simulation
 */
int main(int argc, char **argv)
{
  //  Simulation data output
  for (int i = 1; i < argc; i++)
    std::cout << argv[i] << " ";
  std::cout << std::endl;

  // Setup Parameters
  Param param = set_params(argc, argv);

  // Setup I/O:
  if (param.verbose)
    std::cout<<"i\tinit time (ns)\tsim time (ns)";
  if (param.verify)
    std::cout<<"\tnorm_i\tnorm_f\tenergy_i\tenergy_f"<<std::endl;

  // Run simulation
  for (int i = 0; i < param.iter; i++)
    simulation(i, &param);

  std::cout << std::endl;
  return 0;
}
