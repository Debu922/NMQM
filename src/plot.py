import numpy as np
import sympy as sp

from matplotlib import pyplot as plt
from sympy import init_printing
from sympy.utilities.lambdify import lambdify
from matplotlib.animation import FuncAnimation

import ival
import para
import compute

nx = para.nx
nt = para.nt
dx = para.dx
dt = para.dt

fn_phi = ival.fn_phi
fn_v = ival.fn_v

x = compute.x
result = compute.result
#################################################
#################################################
#################################################



fig = plt.figure(figsize = (12,9))
axis = plt.axes(xlim=(-1/2,1/2),ylim =(0,10))
line, = axis.plot([],[],lw =2)

animspeed = para.animspeed

def animate(i):
    line.set_data(x,np.abs(result[i*animspeed]))
    return line,

nanim=int(nt/animspeed)
anim = FuncAnimation(fig, animate, frames = nanim, interval = 1, blit = True)
#anim.save('/home/nanarbar/Desktop/shiggydiggy.mp4', writer = 'ffmpeg', fps = 60)

"""plt.plot(x,np.abs(result[-1]**2), label='after')
plt.plot(x,np.abs(result[0]**2), label='before')
plt.plot(x,np.abs(v), label='potential')
plt.legend()"""
plt.show()
