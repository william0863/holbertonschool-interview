def minOperations(n):
    """
    Calculate the minimum number of operations needed to get exactly n 'H' characters
    using only 'Copy All' and 'Paste' operations.
    
    :param n: The target number of 'H' characters
    :return: Minimum number of operations, or 0 if n is impossible to achieve
    """
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
