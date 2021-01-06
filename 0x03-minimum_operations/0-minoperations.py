#!/usr/bin/python3
"""TASK 0. Minimum Operations."""

def minOperations(n):
    """Write a method that calculates the fewest number of operations."""
    """Needed to result in a number of H characters in the file."""
    idx = 2
    # this variable holds the mininum number if operations
    minOps = 0
    # this variable holds the number of H characters
    numberOfHs = n
    if numberOfHs < 2:
        return 0
    while (idx < numberOfHs + 1):
        while (numberOfHs % idx == 0):
            minOps = minOps + idx
            numberOfHs = numberOfHs / idx
        idx = idx + 1
    return minOps
