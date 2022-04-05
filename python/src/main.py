from sch import Wavefunction
import numpy as np
import para 
import init_cond
from my_fft import *

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.animation import FFMpegWriter
import numpy as np


fig = plt.figure()

t=para.dt
G=Wavefunction()
G.set_arrays()
init_cond.initcond1(G)

output = np.zeros((para.Ngt,G.psi.shape[2]))

j=0
for i in range(para.Ngt):
    G.i_time_sstep_strang()
    abs_psi = np.abs(G.psi).squeeze()
    output[i,:] = abs_psi
    # if (para.tstepMov[j]-t)/para.dt<para.dt:
    #     print('\n----------------------')
    #     print('t: ',t)
    #     print('norm: ',G.norm())
    #     print('energy: ',G.energy())
    #     j=j+1
    # t =t+para.dt
print(len(output))

figure,ax = plt.subplots(figsize=(15, 8))
line, = ax.plot(output[i,:])
line.set_xdata(range(G.psi.shape[2]))
ax.set_ylim([0,1])
def animation_function(i):
    line.set_ydata(output[i*100,:])
    if i%100==0:
        print("Stitching image ",i)
    return line
  
animation = FuncAnimation(figure,
                          func = animation_function,
                          frames = int(len(output)/100), 
                          interval = 1000)

writervideo = FFMpegWriter(fps=60)
animation.save('output.mp4', writer=writervideo)
plt.close()