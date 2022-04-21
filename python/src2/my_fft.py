import numpy as np
import para
import pyfftw.interfaces.numpy_fft as pyfftw


def forward_transform(psi):
    psik = (pyfftw.fftn(psi)/(para.Nx*para.Ny*para.Nz))
    return psik

def inverse_transform(psik):
    # psik=dealias(psik)
    psi = (pyfftw.ifftn(psik)*(para.Nx*para.Ny*para.Nz))
    return psi


## meshgrid
Dx=np.arange(-para.Nx//2+1,para.Nx//2+1)
kx=2*np.pi*np.roll(Dx,para.Nx//2+1)/para.Lx
x=Dx*para.Lx/para.Nx

Dy=np.arange(-para.Ny//2+1,para.Ny//2+1)
ky=2*np.pi*np.roll(Dy,para.Ny//2+1)/para.Ly
y=Dy*para.Ly/para.Ny

Dz=np.arange(-para.Nz//2+1,para.Nz//2+1)
kz=2*np.pi*np.roll(Dz,para.Nz//2+1)/para.Lz
z=Dz*para.Lz/para.Nz
 

x_mesh,y_mesh,z_mesh=np.meshgrid(x,y,z,indexing='ij')
kx_mesh, ky_mesh, kz_mesh = np.meshgrid(kx, ky, kz,indexing = 'ij')
ksqr = kx_mesh**2 + ky_mesh**2 + kz_mesh**2






'''
def dealias(psik): 
    if (para.dimension == 1):
        psik[para.Nz//3+1:2*para.Nz//3+1] = 0
        return psik
    elif (para.dimension == 2):
        psik[para.Nx//3:(2*para.Nx)//3+1, :] = 0
        psik[:,para.Nz//3:2*para.Nz//3+1] = 0
        return psik
    elif (para.dimension == 3):
        psik[para.Nx//3:(2*para.Nx)//3+1, :, :] = 0
        psik[:, para.Ny//3+1:(2*para.Ny)//3+1, :] = 0
        psik[:, :, para.Nz//3:2*para.Nz//3+1] = 0
        return psik
'''