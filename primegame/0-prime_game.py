#!/usr/bin/python3
"""
Prime Game
"""


def isWinner(x, nums):
    """
    Generate Prime Game

    Args:
        x: number of rounds
        nums: array of n

    Returns:
        name of the player that won the most rounds
              Returns none if name of player cant be determined
    """
def isWinner(x, nums):
    if not nums or x < 1:
        return None

    n = max(nums)
    # Sieve of Eratosthenes to count primes up to n
    is_prime = [False, False] + [True for _ in range(2, n + 1)]
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    # Count number of primes up to i
    prime_count = [0] * (n + 1)
    count = 0
    for i in range(1, n + 1):
        if is_prime[i]:
            count += 1
        prime_count[i] = count

    # Determine winners
    maria_wins = 0
    ben_wins = 0
    for num in nums:
        if prime_count[num] % 2 == 0:
            ben_wins += 1
        else:
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None

