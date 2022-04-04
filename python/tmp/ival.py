import numpy as np
import sympy as sp

from matplotlib import pyplot as plt
from sympy import init_printing
from sympy.utilities.lambdify import lambdify
from matplotlib.animation import FuncAnimation


#################################################
#################################################
#################################################
#setting initial functions for potential and wavefunction

x,t = sp.symbols('x t')

initphi = sp.exp(-(x)**2 * 100 )                      #wavefunction at t=0
fn_phi = sp.lambdify((x) , initphi)
#print(fn_init(0))

#initv = sp.exp(x*5)                      #Potential V
#initv = 1000* x**2  #harmonic
initv = 0 * x 
#initv = (sp.exp(x*100))/(1+sp.exp(x*100)) # barrier
fn_v = sp.lambdify((x) , initv)
#print(fn_v(0))
