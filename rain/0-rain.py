#!/usr/bin/python3
"""
Function to calculate the total amount of rain retained
"""


def rain(walls):
    """
    Calculate the total amount of water trapped between walls after it rains.

    Args:
    walls (list): A list of non-negative integers representing the heights
    of the walls.

    Returns:
    int: The total amount of rain retained.
    """
    if not walls or len(walls) < 3:
        return 0

    left_max = [0] * len(walls)
    right_max = [0] * len(walls)
    rain_retained = 0

    left_max[0] = walls[0]
    for i in range(1, len(walls)):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[len(walls) - 1] = walls[len(walls) - 1]
    for i in range(len(walls) - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    for i in range(1, len(walls) - 1):
        rain_retained += max(0, min(left_max[i], right_max[i]) - walls[i])

    return rain_retained
