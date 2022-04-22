import numpy as np 
from time import time

logN_max = 18
iter = 10

# Integer Addition
print("Integer Addition")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.randint(-1<<63,1<<63,N)
        B = np.random.randint(-1<<63,1<<63,N)
        S = np.zeros(N)

        start = time()
        S = A + B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Integer Multiplication
print("Integer Multiplication")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.randint(-1<<63,1<<63,N)
        B = np.random.randint(-1<<63,1<<63,N)
        S = np.zeros(N)

        start = time()
        S = A * B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Integer Division
print("Integer Division")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.randint(-1<<63,1<<63,N)
        B = np.random.randint(-1<<63,1<<63,N)
        S = np.zeros(N,dtype=np.int)

        start = time()
        S = A / B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Integer Accumulation
print("Integer Accumulation")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.randint(-1<<63,1<<63,N)
        S = np.int

        start = time()
        S = np.sum(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real Addition
print("Real Addition")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        B = np.random.rand(N)
        S = np.zeros(N)

        start = time()
        S = A + B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real Multiplication
print("Real Multiplicaiton")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        B = np.random.rand(N)
        S = np.zeros(N)

        start = time()
        S = A * B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real Division
print("Real Division")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        B = np.random.rand(N)
        S = np.zeros(N)

        start = time()
        S = A / B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real Accumulation
print("Real Accumulation")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        S = np.float

        start = time()
        S = sum(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real Sin
print("Real Sin")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        S = np.zeros(N)

        start = time()
        S = np.sin(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real Exp
print("Real Sin")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        S = np.zeros(N)

        start = time()
        S = np.exp(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Real log
print("Real Log")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.rand(N)
        S = np.zeros(N)

        start = time()
        S = np.log(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex addition
print("Complex addition")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j
        B = np.random.random(N) + np.random.random(N) * 1j
        S = np.zeros(N)

        start = time()
        S = A+B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex Multiplicaiton
print("Complex Multiplicaiton")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j
        B = np.random.random(N) + np.random.random(N) * 1j
        S = np.zeros(N)

        start = time()
        S = A*B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex Division
print("Complex Division")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j
        B = np.random.random(N) + np.random.random(N) * 1j
        S = np.zeros(N)

        start = time()
        S = A/B
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex Accumulation
print("Complex Accumulation")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j
        S = np.cdouble

        start = time()
        S = np.sum(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex Sin
print("Complex Sin")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j

        start = time()
        S = np.sin(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex Exp
print("Complex Exp")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j

        start = time()
        S = np.exp(A)
        finish = time()
        print(finish-start, "", end="")
    print("")

# Complex log
print("Complex log")
N=1
for logN in range(logN_max):
    N *= 2
    print(logN,"", end="")
    for iteration in range(iter):
        A = np.random.random(N) + np.random.random(N) * 1j

        start = time()
        S = np.log(A)
        finish = time()
        print(finish-start, "", end="")
    print("")