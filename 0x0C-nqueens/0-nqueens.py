#!/usr/bin/python3
"""The N queens puzzle challenge."""


import sys


def solveQPuzzle(ches):
    """The-N queens puzzle challenge."""
    sizeOfPuzz = len(ches)
    for row in range(sizeOfPuzz):
        num1 = 0
        num2 = 0
        for column in range(sizeOfPuzz):
            num1 += ches[row][column]
            num2 += ches[column][row]
        if num1 > 1:
            return(False)
        if num2 > 1:
            return(False)

    for move in range(sizeOfPuzz):
        firstMove = [0, move]
        secondMove = [move, 0]
        first = chessMoveGrab(ches, firstMove)
        second = chessMoveGrab(ches, secondMove)
        if not first:
            return(False)
        if not second:
            return(False)

    for move in range(sizeOfPuzz):
        firstMove = [sizeOfPuzz - 1, move]
        secondMove = [sizeOfPuzz - 1 - move, 0]
        first = chessMoveGrab(ches, firstMove, False)
        second = chessMoveGrab(ches, secondMove, False)
        if not first:
            return(False)
        if not second:
            return(False)
    return True


def chessMoveGrab(ches, point, boolean=True):
    """The-N queens puzzle challenge."""
    sizeOfPuzz = len(ches)
    GrabMove = 0
    while (point[0] >= 0 and
            point[0] < tabl and
            point[1] >= 0 and
            point[1] < sizeOfPuzz):
        GrabMove += ches[point[0]][point[1]]
        if boolean:
            point[0] += 1
            point[1] += 1
        else:
            point[0] -= 1
            point[1] += 1
        if GrabMove > 1:
            return(False)
    return(True)


def PuzzleSolved(tabl, ches, columns=0, possibleMoves=[], points=[]):
    """The-N queens puzzle challenge."""
    if columns == tabl:
        possibleMoves.append(points[:])
        return(possibleMoves)
    for moves in range(tabl):
        ches[columns][moves] = 1
        if (solveQPuzzle(ches)):
            score = [columns, moves]
            points.append(score)
            PuzzleSolved(tabl, ches, columns + 1, possibleMoves, points)
            points.remove(score)
        ches[columns][moves] = 0
    return(possibleMoves)


sizeOfPuzz = len(sys.argv)
NumOfPuzzPosOne = int(sys.argv[1])
if sizeOfPuzz != 2:
    usage = "Usage: nqueens N"
    print(usage)
    exit(1)
tabl = 0
try:
    tabl = NumOfPuzzPosOne
except ValueError:
    number = "N must be a number"
    print(number)
    exit(1)
if tabl < 4:
    four = "N must be at least 4"
    print(four)
    exit(1)

ches = []
for numOne in range(tabl):
    ches.append([])
    for numTwo in range(tabl):
        ches[-1].append(0)
for possibleSols in PuzzleSolved(tabl, ches):
    print(possibleSols)
