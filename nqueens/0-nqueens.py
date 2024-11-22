#!/usr/bin/python3
import sys

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
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        sys.exit(1)
    if N < 4:
        sys.exit(1)
    solutions = solve_nqueens(N)
    for solution in solutions:
        print(solution)
