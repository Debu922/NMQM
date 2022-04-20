/**
*******************************************
* Author:       Debaditya Bhattacharya    *
* Email:        debbh@iitk.ac.in          *
* Affiliation:  IIT Kanpur                *
* Course:       IDC606A                   *
* Instructor:   Prof. Mahindra Verma      *
*                                         *
* File Name:    param.cpp                 *
* Description:  Param class. Holds all    *
*               the Parameters used in    *
*               the Simulation.           *
*******************************************
**/
#include "param.hpp"
#include "iostream"

/**
 * @brief This function allocates memory for the unit vectors.
 * 
 */
void Param::alloc_vector()
{
  if (dims >= 1)
  {
    this->x1 = new std::complex<double>[this->Nx];
    this->k1 = new std::complex<double>[this->Nx];
  }
  if (dims >= 2)
  {
    this->x2 = new std::complex<double>[this->Nx];
    this->k2 = new std::complex<double>[this->Nx];
  }
  if (dims >= 3)
  {
    this->x3 = new std::complex<double>[this->Nx];
    this->k3 = new std::complex<double>[this->Nx];
  }
  return;
}

/**
 * @brief Set 1D axis vector
 * 
 */
void Param::set_x_1D()
{
  for (int i = 0; i < Nx; i++)
  {
    x1[i] = (-xmax + xmax / res + i * dx);
  }
  return;
}

/**
 * @brief Set 2D axis vector 
 * 
 */
void Param::set_x_2D()
{
  set_x_1D();
  for (int i = 0; i < Nx; i++)
  {
    x2[i] = (-xmax + xmax / res + i * dx);
  }
  return;
}

/**
 * @brief Set 3D axis vector
 * 
 */
void Param::set_x_3D()
{
  set_x_2D();
  for (int i = 0; i < Nx; i++)
  {
    x3[i] = (-xmax + xmax / res + i * dx);
  }
  return;
}

/**
 * @brief Set 1D axis vector (momentum)
 * 
 */
void Param::set_k_1D()
{
  for (int i = 0; i < Nx / 2; i++)
  {
    k1[i] = i * dk;
    k1[Nx - i - 1] = k1[i];
  }
  return;
}

/**
 * @brief Set 2D axis vector (momentum)
 * 
 */
void Param::set_k_2D()
{
  set_k_1D();
  for (int i = 0; i < Nx / 2; i++)
  {
    k2[i] = i * dk;
    k2[Nx - i - 1] = k2[i];
  }
}

/**
 * @brief Set 3D axis vector (momentum)
 * 
 */
void Param::set_k_3D()
{
  set_k_2D();
  for (int i = 0; i < Nx / 2; i++)
  {
    k3[i] = i * dk;
    k3[Nx - i - 1] = k3[i];
  }
}

/**
 * @brief Construct a new Param:: Param object
 * Create empty constructor object. Previously filled with initialization code but now replaced by Param::init_param()
 * 
 */
Param::Param()
{
}

/**
 * @brief Initialize the param class.
 * Allocates Memory and checks for incorrect dimentions.
 * 
 */
void Param::init_param()
{
  alloc_vector();
  if (dims == 1)
  {
    set_x_1D();
    set_k_1D();
  }
  else if (dims == 2)
  {
    set_x_2D();
    set_k_2D();
  }
  else if (dims == 3)
  {
    set_x_3D();
    set_k_3D();
  }
  else
  {
    std::cout << "Invalid dimentions. Accepted dimentions: 1, 2, 3";
    exit(1);
  }
}
