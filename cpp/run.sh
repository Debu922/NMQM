#!/bin/bash
###########################################
# Author:       Debaditya Bhattacharya    #
# Email:        debbh@iitk.ac.in          #
# Affiliation:  IIT Kanpur                #
# Course:       IDC606A                   #
# Instructor:   Prof. Mahindra Verma      #
#                                         #
# File Name:    run.sh                    #
# Description:  Run script which compiles #
#               and runs testcases on the #
#               projects.                 #
###########################################
touch output.txt
# Compile the script
make clean >> output.txt
make    >> output.txt
echo "" >> output.txt
# # Run 1D test cases
./output/main -dims 1 -Nx  32  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -Nx  64  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -Nx  128 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -Nx  256 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -Nx  512 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt

# # Run 2D test cases
./output/main -dims 2 -Nx  32  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -Nx  64  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -Nx  128 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -Nx  256 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -Nx  512 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt

# # Run 3D test cases
./output/main -dims 3 -Nx  32  -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -Nx  64  -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -Nx  128 -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -Nx  256 -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -Nx  512 -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt