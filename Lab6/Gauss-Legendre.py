import math
import time
from decimal import *


def gauss_legendre(n):
    a = Decimal(1.0)
    b = Decimal(1.0) / Decimal(math.sqrt(2))
    t = Decimal(0.25)
    p = Decimal(1.0)

    for _ in range(n):
        a_new = (a + b) / 2
        b = Decimal(math.sqrt(a * b))
        t -= p * (a - a_new) ** 2
        a = a_new
        p *= 2

    pi = (a + b) ** 2 / (4 * t)
    return pi


# Number of iterations for the algorithm
iterations = int(input())
# Set decimal precision to 1000
getcontext().prec = iterations

# Measure the execution time
start_time = time.time()
pi = gauss_legendre(iterations)
end_time = time.time()

execution_time = end_time - start_time

# Convert Pi to string with 1000 decimal places
pi_str = str(pi)

print("Approximation of Pi:", pi_str)
print("Execution time:", execution_time, "seconds")
