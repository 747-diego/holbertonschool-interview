#!/usr/bin/python3
"""0x16. Rotate 2D Matrix."""


def rotate_2d_matrix(matrix):
    """TASK 0. Rotate 2D Matrix."""
    for numOne in range(len(matrix)):
        for numTwo in range(len(matrix)):
            if numOne > numTwo:
                # matrix demensions
                demOne = (numOne, numTwo)
                demTwo = (numTwo, numOne)
                twoD(matrix, demOne, demTwo)
    for numTwo in range(len(matrix) // 2):
        for numOne in range(len(matrix)):
            twoD(matrix, (numOne, numTwo), (numOne, len(matrix) - 1 - numTwo))


def twoD(rotate, numOne, numTwo):
    """Rotate 90 degrees."""
    rotate[numOne[0]][numOne[1]] = \
        rotate[numOne[0]][numOne[1]] ^ rotate[numTwo[0]][numTwo[1]]
    rotate[numTwo[0]][numTwo[1]] = \
        rotate[numOne[0]][numOne[1]] ^ rotate[numTwo[0]][numTwo[1]]
    rotate[numOne[0]][numOne[1]] = \
        rotate[numOne[0]][numOne[1]] ^ rotate[numTwo[0]][numTwo[1]]
