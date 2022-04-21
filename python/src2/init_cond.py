import my_fft
import numpy as np
import copy
import para

def initcond1(G,dims):

    '''
    Initial wavefunction
    '''
    if para.dimension==1:
        G.psi = (1/np.pi**(1/4))*np.exp(-(my_fft.z_mesh**2/2+my_fft.y_mesh**2+my_fft.x_mesh**2/2))+0j  #1D initial condition
    if para.dimension==2:
        G.psi = (1/(np.pi)**(1/2))*np.exp(-(my_fft.z_mesh**2/2+my_fft.y_mesh**2+my_fft.x_mesh**2/2))+0j  #2D initial condition
    if para.dimension==3:
        G.psi = (1/(np.pi)**(3/4))*np.exp(-(my_fft.z_mesh**2+my_fft.y_mesh**2+my_fft.x_mesh**2)/2)+0j  # 3D initial condition
    G.psi /= np.sqrt(G.norm())


    G.psik=my_fft.forward_transform(G.psi)
    G.tempF=copy.deepcopy(G.psik)
    G.tempR=copy.deepcopy(G.psi)



    '''
    potential
    '''
    G.V=(my_fft.x_mesh**2+my_fft.y_mesh**2+my_fft.z_mesh**2)/2
    # del my_fft.x_mesh,my_fft.y_mesh,my_fft.z_mesh