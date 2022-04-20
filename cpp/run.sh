#!/bin/bash
touch output.txt
# Compile the script
make clean >> output.txt
make    >> output.txt
echo "" >> output.txt
# # Run 1D test cases
./output/main -dims 1 -res  16  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -res  32  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -res  64  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -res  128 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 1 -res  256 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt

# # Run 2D test cases
./output/main -dims 2 -res  16  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -res  32  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -res  64  -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -res  128 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt
./output/main -dims 2 -res  256 -iter   10  -timesteps 1000 -verbose 1 -verify 1 >> output.txt

# # Run 3D test cases
./output/main -dims 3 -res  16  -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -res  32  -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -res  64  -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -res  128 -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt
./output/main -dims 3 -res  256 -iter   10  -timesteps 10 -verbose  1 -verify 1 >> output.txt