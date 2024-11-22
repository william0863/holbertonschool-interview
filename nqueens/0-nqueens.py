#!/usr/bin/python3
import sys

def print_usage(message):
    print(message)
    sys.exit(1)

def solve_nqueens(n):
    def backtrack(row):
        if row == n:
            solutions.append([[i, board[i]] for i in range(n)])
            return
        for col in range(n):
            if all(board[i] != col and
                   board[i] - i != col - row and
                   board[i] + i != col + row for i in range(row)):
                board[row] = col
                backtrack(row + 1)
                board[row] = -1

    solutions = []
    board = [-1] * n
    backtrack(0)
    return solutions

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print_usage("Usage: nqueens N")

    try:
        N = int(sys.argv[1])
    except ValueError:
        print_usage("N must be a number")

    if N < 4:
        print_usage("N must be at least 4")
        
    solutions = solve_nqueens(N)
    for solution in solutions:
        print(solution)
