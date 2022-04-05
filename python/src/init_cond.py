import my_fft
import numpy as np
import copy

def initcond1(G):

    '''
    Initial wavefunction
    '''
    G.psi = (1/np.pi**(1/4))*np.exp(-(my_fft.z_mesh**2/2+my_fft.y_mesh**2+my_fft.x_mesh**2/2))+0j  #1D initial condition
    # G.psi = (1/(np.pi)**(1/2))*np.exp(-(my_fft.z_mesh**2/2+my_fft.y_mesh**2+my_fft.x_mesh**2/2))+0j    #2D initial condition
    # G.psi = (1/(np.pi)**(3/4))*np.exp(-(my_fft.z_mesh**2+my_fft.y_mesh**2+my_fft.x_mesh**2)/2)+0j  # 3D initial condition
    

    G.psik=my_fft.forward_transform(G.psi)
    G.tempF=copy.deepcopy(G.psik)
    G.tempR=copy.deepcopy(G.psi)



    '''
    potential
    '''
    G.V=(my_fft.x_mesh**2+my_fft.y_mesh**2+my_fft.z_mesh**2)/2
    # G.V = G.V *0
    del my_fft.x_mesh,my_fft.y_mesh,my_fft.z_mesh