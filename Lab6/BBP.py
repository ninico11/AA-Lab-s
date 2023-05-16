import decimal
import time


def calculate_pi_digit(n):
    decimal.getcontext().prec = n + 1  # Set precision to obtain n digits

    pi = decimal.Decimal(0)
    k = 0

    while k <= n:
        pi += (decimal.Decimal(1) / 16 ** k) * (
                (decimal.Decimal(4) / (8 * k + 1)) -
                (decimal.Decimal(2) / (8 * k + 4)) -
                (decimal.Decimal(1) / (8 * k + 5)) -
                (decimal.Decimal(1) / (8 * k + 6))
        )
        k += 1

    return pi


digits = int(input())  # Number of digits to calculate

start_time = time.time()
pi = calculate_pi_digit(digits)
end_time = time.time()

execution_time = end_time - start_time

print(f"Calculated pi: {pi}")
print(f"Execution time: {execution_time} seconds")
