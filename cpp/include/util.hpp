/**
*******************************************
* Author:       Debaditya Bhattacharya    *
* Email:        debbh@iitk.ac.in          *
* Affiliation:  IIT Kanpur                *
* Course:       IDC606A                   *
* Instructor:   Prof. Mahindra Verma      *
*                                         *
* File Name:    util.hpp                  *
* Description:  Contians functions used   *
*               in overall simulation     *
*******************************************
**/
#ifndef __UTIL_H__
#define __UTIL_H__

#include "param.hpp"


void simulation(int i, Param *param);

Param set_params(int argc, char **argv);

#endif // __UTIL_H__