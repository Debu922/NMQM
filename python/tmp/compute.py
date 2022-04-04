import numpy as np
import sympy as sp

from matplotlib import pyplot as plt
from sympy import init_printing
from sympy.utilities.lambdify import lambdify
from matplotlib.animation import FuncAnimation

import ival
import para

nx = para.nx
nt = para.nt
dx = para.dx
dt = para.dt

fn_phi = ival.fn_phi
fn_v = ival.fn_v
#################################################
#################################################
#################################################


x=np.linspace(-1/2,1/2,nx)

phi=np.asarray([fn_phi(xi) for xi in x], dtype=complex)
norm = np.sum(np.abs(phi**2))
phi = phi/norm
v=np.asarray([fn_v(xi) for xi in x], dtype=complex) * 500

#################################################
#################################################
#################################################

def phi():
    
    result=np.zeros([nt,nx], dtype=complex)
    result[0]=[fn_phi(xi) for xi in x]
    
    for i in range(len(result)-1):
        result[i+1][1:-1] = result[i][1:-1] +\
            1j*dt*v[1:-1]*result[i][1:-1] +\
            1j/2 * dt/dx**2 * (result[i][2:] - 2*result[i][1:-1] + result[i][:-2]) 
        result[i+1][0]=result[i+1][-1]=0

        norm = np.sum(np.abs(result[i+1])) * dx*2
        result[i+1]=result[i+1]/norm

    return result


