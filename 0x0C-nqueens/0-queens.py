#!/usr/bin/python3
"""The N queens puzzle challenge."""


import sys


def solveQPuzzle(ches):
    """The-N queens puzzle challenge."""
    # check rows and columns
    for row in range(len(ches)):
        num1 = 0
        num2 = 0
        for column in range(len(ches)):
            num1 += ches[row][column]
            num2 += ches[column][row]
        if num1 > 1:
            return(False)
        if num2 > 1:
            return(False)

    # check diagonals to bottom-right
    for move in range(len(ches)):
        firstMove = [0, move]
        secondMove = [move, 0]
        first = chessMoveGrab(ches, firstMove)
        second = chessMoveGrab(ches, secondMove)
        if not first:
            return(False)
        if not second:
            return(False)

    # check diagonals to bottom-left
    for move in range(len(ches)):
        firstMove = [len(ches) - 1, move]
        secondMove = [len(ches) - 1 - move, 0]
        first = chessMoveGrab(ches, firstMove, False)
        second = chessMoveGrab(ches, secondMove, False)
        if not first:
            return(False)
        if not second:
            return(False)
    return True


def chessMoveGrab(ches, point, direction=True):
    """The-N queens puzzle challenge."""
    ones = 0
    while (point[0] >= 0 and
            point[0] < tabl and
            point[1] >= 0 and
            point[1] < len(ches)):
        ones = ones + ches[point[0]][point[1]]
        if direction:
            point[0] = point[0]+1
            point[1] = point[1]+1
        else:
            point[0] = point[0]-1
            point[1] = point[1]+1
        if ones > 1:
            return False
    return True


def PuzzleSolved(tabl, ches, col=0, solutions=[], acc=[]):
    """The-N queens puzzle challenge."""
    if col == tabl:
        solutions.append(acc[:])
        return solutions
    for i in range(tabl):
        ches[col][i] = 1
        if (solveQPuzzle(ches)):
            # add point to acc
            pt = [col, i]
            acc.append(pt)

            PuzzleSolved(tabl, ches, col+1, solutions, acc)
            # remove point from acc
            acc.remove(pt)
        # remove one from grid
        ches[col][i] = 0

    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    tabl = 0
    try:
        tabl = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)
    if tabl < 4:
        print("N must be at least 4")
        exit(1)

    ches = []
    for i in range(tabl):
        ches.append([])
        for j in range(tabl):
            ches[-1].append(0)

    for s in PuzzleSolved(tabl, ches):
        print(s)
