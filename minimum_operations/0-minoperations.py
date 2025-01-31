#!/usr/bin/python3

"""
Module to calculate the minimum number of operations required
for achieving exactly n 'H' characters using Copy All and Paste operations.
"""

def min_operations(n):
    if n <= 1:
        return 0
    
    operations = 0
    divisor = 2
    
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1
    
    return operations

if __name__ == "__main__":
    n = 9
    print(min_operations(n))
