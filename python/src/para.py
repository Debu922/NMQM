import numpy as np
'''
For 1D set Nx=1,Ny=1,Lx=1,Ly=1
For 2D set Ny=1,Ly=1
'''

Lx=1
Ly=1
Lz=16

dimension=1

Nlin=12.52

Nx = 1
Ny = 1
Nz = 64

tinit = 0
tstepMov=np.array([0.001,1.0,4.0,6.0,10.0]) #points at which we have to print Norm and Energy
volume=Lx*Ly*Lz


tMax=10 # time 
dt=0.001 
Ngt=int(tMax/dt)