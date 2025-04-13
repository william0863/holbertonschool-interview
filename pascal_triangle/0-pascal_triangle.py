#!/usr/bin/python3
"""
Module for generating Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Generate Pascal's Triangle

    Args:
        n (int): number of rows

    Returns:
        list: A list of lists of integers
              Returns empty list if n <= 0
    """
    if n <= 0:
        return []

    triangle = [[1]]

    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i-1][j-1] + triangle[i-1][j])
        row.append(1)
        triangle.append(row)

    return triangle
