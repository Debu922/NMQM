from sch import Wavefunction
import numpy as np
import para 
import init_cond
from my_fft import *

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np


fig = plt.figure()

t=para.dt
G=Wavefunction()
G.set_arrays()
init_cond.initcond1(G)

output = []

j=0
for i in range(para.Ngt):
    G.sstep_strang()
    abs_psi = np.abs(G.psi).squeeze()
    output.append(abs_psi)
    if (para.tstepMov[j]-t)/para.dt<para.dt:
        print('\n----------------------')
        print('t: ',t)
        print('norm: ',G.norm())
        print('energy: ',G.energy())
        j=j+1
    t =t+para.dt
print(len(output))

figure,ax = plt.subplots(figsize=(15, 8))
def animation_function(i):
    ax.clear()
    plot = plt.plot(output[i])
    return plot
  
animation = FuncAnimation(figure,
                          func = animation_function,
                          frames = len(output)), 
                          interval = 10)

writervideo = animation.FFMpegWriter(fps=60)
anim.save('increasingStraightLine.mp4', writer=writervideo)