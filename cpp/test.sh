#!/bin/bash
g++ speed_test.cpp -O3 -o speed_test
touch speed_test_out.txt
./speed_test >> speed_test_out.txt