import pyfftw.interfaces.numpy_fft as pyfftw
import numpy as np
import matplotlib.pyplot as plt

sampling_freq = 100
start_time = 0
end_time = 10
Dt = end_time-start_time

sig_freq1 = 4
sig_freq2 = 5.5


x = np.arange(sampling_freq*(end_time-start_time))/sampling_freq

y = np.cos(x*sig_freq1*2*np.pi)
y += np.cos(x*sig_freq2*2*np.pi)

z = pyfftw.fftn(y)/len(y)
print(len(y), len(z))

freq = np.arange(-sampling_freq*Dt/2, sampling_freq*Dt/2) /len(x) *sampling_freq
freq = np.roll(freq,int(sampling_freq*Dt/2))
# freq = x / sampling_freq * len(x)
# freq[int(len(x)/2):] = freq[int(len(x)/2):]- sampling_freq
plt.plot(x,y)
plt.show()
plt.plot(freq,np.real(z))
# plt.plot(freq,np.angle(z))
# plt.plot(np.real(-1j*pyfftw.ifftn(x)))
plt.show()
