from math import pi
from math import sqrt

import numpy as np
import pandas as pd
from pyparsing import col

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.animation import FFMpegWriter

class Param:
    """Container for holding all simulation parameters."""
    def __init__(self,
                 xmax: float,
                 res: int,
                 dt: float,
                 timesteps: int,
                 im_time: bool,
                 skip_frame:int = 10) -> None:

        self.xmax = xmax
        self.res = res
        self.dt = dt
        self.timesteps = timesteps
        self.im_time = im_time

        self.dx = 2 * xmax / res
        self.x = np.arange(-xmax + xmax / res, xmax, self.dx)
        self.dk = pi / xmax
        self.k = np.concatenate((np.arange(0, res / 2),
                                 np.arange(-res / 2, 0))) * self.dk

        self.skip_frame = skip_frame


class Operators:
    """Container for holding operators and wavefunction coefficients."""
    def __init__(self, res: int) -> None:

        self.V = np.empty(res, dtype=complex)
        self.R = np.empty(res, dtype=complex)
        self.K = np.empty(res, dtype=complex)
        self.wfc = np.empty(res, dtype=complex)


def init(par: Param, voffset: float, wfcoffset: float, velocity:float) -> Operators:
    """Initialize the wavefunction coefficients and the potential."""
    opr = Operators(len(par.x))
    opr.V = 0.5 * (par.x - voffset) ** 2
    # Free Particle
    # opr.V = opr.V*0
    
    # Wall:

    # opr.V[:int((par.xmax-19)/par.dx)] = 1000
    # opr.V[int((par.xmax+19)/par.dx):] = 1000
    # opr.V[int((par.xmax-0.5)/par.dx):int((par.xmax+0.5)/par.dx)] = 40

    opr.wfc = np.exp(-((par.x - wfcoffset) ** 2) / 2 + velocity*1j*par.x, dtype=complex)
    if par.im_time:
        opr.K = np.exp(-0.5 * (par.k ** 2) * par.dt)
        opr.R = np.exp(-0.5 * opr.V * par.dt)
    else:
        opr.K = np.exp(-0.5 * (par.k ** 2) * par.dt * 1j)
        opr.R = np.exp(-0.5 * opr.V * par.dt * 1j)
    return opr

class Output():
    def __init__(self, x, timesteps) -> None:
        self.x = x
        self.P = np.zeros((timesteps, x.shape[0]),dtype=np.float64)
        self.V = np.zeros((timesteps, x.shape[0]),dtype=np.float64)
        return

def split_op(par: Param, opr: Operators) -> Output:
    output = Output(par.x,par.timesteps)
    for i in range(par.timesteps):

        # Half-step in real space
        opr.wfc *= opr.R

        # FFT to momentum space
        opr.wfc = np.fft.fft(opr.wfc)

        # Full step in momentum space
        opr.wfc *= opr.K

        # iFFT back
        opr.wfc = np.fft.ifft(opr.wfc)

        # Final half-step in real space
        opr.wfc *= opr.R

        # Density for plotting and potential
        density = np.abs(opr.wfc) ** 2

        # Renormalizing for imaginary time
        if par.im_time:
            renorm_factor = sum(density) * par.dx
            opr.wfc /= sqrt(renorm_factor)

        # Outputting data to file. Plotting can also be done in a
        # similar way. This is set to output exactly 100 files, no
        # matter how many timesteps were specified.
        output.P[i,:] = density.real
        output.V[i,:] = opr.V.real

    return output


def calculate_energy(par: Param, opr: Operators) -> float:
    """Calculate the energy <Psi|H|Psi>."""
    # Creating real, momentum, and conjugate wavefunctions.
    wfc_r = opr.wfc
    wfc_k = np.fft.fft(wfc_r)
    wfc_c = np.conj(wfc_r)

    # Finding the momentum and real-space energy terms
    energy_k = 0.5 * wfc_c * np.fft.ifft((par.k ** 2) * wfc_k)
    energy_r = wfc_c * opr.V * wfc_r

    # Integrating over all space
    energy_final = sum(energy_k + energy_r).real

    return energy_final * par.dx

def generate_animation(output,par,energy):
    fig, ax1 = plt.subplots(figsize=(16,9))

    # Generate the animation
    ax2 = ax1.twinx()
    P_line, = ax1.plot(output.x,output.P[0,:])
    V_line, = ax2.plot(output.V[0,:],output.P[0,:],'r--')
    ax1.set_ylim([0,1])
    ax1.set_xlim([min(output.x),max(output.x)])
    ax2.set_ylim([0,1+np.max([np.max(output.V),energy])])
    ax2.set_xlim([min(output.x),max(output.x)])
    ax1.set_ylabel(r"$|\Psi|^2$")
    def animation_func(i):
        P_line.set_data(output.x,output.P[i*par.skip_frame,:])
        V_line.set_data(output.x,output.V[i*par.skip_frame,:])
        return P_line, V_line
    ax2.set_ylabel(r"$V(x)$")
    animation = FuncAnimation(fig,
                        func = animation_func,
                        frames = int(par.timesteps/par.skip_frame))

    writervideo = FFMpegWriter(fps=30)
    animation.save('output.mp4', writer=writervideo)
    plt.close()
    return 0


def main() -> None:
    par = Param(20, 2<<10, 0.0001, 100000, False, 50)

    # Starting wavefunction slightly offset so we can see it change
    

    opr = init(par, 0.0, -10,10)
    energy = calculate_energy(par, opr)
    print("Energy at start is: ", energy)
    output = split_op(par, opr)

    energy = calculate_energy(par, opr)
    print("Energy at end is: ", energy)

    generate_animation(output,par,energy)

if __name__ == "__main__":
    main()
