#!/usr/bin/python3
"""
This module contains the function minOperations.

The function calculates the minimum number of operations needed to get exactly 
n 'H' characters using only 'Copy All' and 'Paste' operations.
"""

def minOperations(n):

    if n < 2:
        return 0
    operations = 0
    divisor = 2
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1
    return operations
