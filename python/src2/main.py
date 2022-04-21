import numpy as np
import para 
from time import time
import sys

def set_params():
    return

start = time()
argv = sys.argv

for i in range(len(argv)):
    if i == 0:
        continue
    if argv[i] =="-dims":
        para.dimension = int(argv[i+1])
    if argv[i] =="-Nx":
        para.Nz = int(argv[i+1])
    if argv[i] =="-iter":
        para.iterations = int(argv[i+1])
    if argv[i] =="-timesteps":
        para.timesteps = int(argv[i+1])
    if argv[i] =="-verbpse":
        para.verbose = bool(argv[i+1])
    if argv[i] =="-verify":
        para.verify = bool(argv[i+1])
    print(sys.argv[i],"",end='')
print("")

if para.dimension ==1:
    para.Lx = 1
    para.Ly = 1
    para.Lz = 10
    para.Nx = 1
    para.Ny = 1
    para.Nz = para.Nz
if para.dimension == 2:
    para.Lx = 10
    para.Ly = 1
    para.Lz = 10
    para.Nx = para.Nz
    para.Ny = 1
    para.Nz = para.Nz
if para.dimension == 3:
    para.Lx = 10
    para.Ly = 10
    para.Lz = 10
    para.Nx = para.Nz
    para.Ny = para.Nz
    para.Nz = para.Nz
para.Nlin=12.52


import init_cond
from sch import Wavefunction


for i in range(para.iterations):
    
    start = time()
    G=Wavefunction()
    G.set_arrays()
    init_cond.initcond1(G,para.dimension)
    finish = time()
    init_time = int((finish-start)*1e9)
    norm_i = G.norm()
    energy_i = G.energy()

    start = time()
    for step in range(para.timesteps):
        G.sstep_strang()
    finish = time()
    norm_f = G.norm()
    energy_f = G.energy()
    sim_time = int((finish-start)*1e9)
    print(i, init_time, sim_time, norm_i, norm_f, energy_i, energy_f,sep="\t")
