import para
import my_fft
from scipy.integrate import simpson as sn


def my_integral(psi):
    if para.Nx==1 and para.Ny==1:
        return(sn(psi,my_fft.z).reshape(-1))
    elif para.Ny==1:
        return sn(sn(psi,my_fft.z).reshape(-1),my_fft.x)
    return sn(sn(sn(psi,my_fft.z),my_fft.y),my_fft.x)