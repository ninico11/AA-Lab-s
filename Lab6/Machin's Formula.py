import mpmath
import time


def machins_formula(precision):
    mpmath.mp.dps = precision  # Set the desired number of decimal places

    # Calculate the value of π/4 using Machin's formula
    pi = 4 * (4 * mpmath.atan(1 / 5) - mpmath.atan(1 / 239))

    return pi


# Example usage:
precision = int(input())
# Measure the execution time
start_time = time.time()
result = machins_formula(precision)
end_time = time.time()

execution_time = end_time - start_time

print(f'π calculated with Machin\'s formula to {precision} decimal places:')
print(result)
print("Execution time:", execution_time, "seconds")
