#!/usr/bin/python3
"""TASK 0. Pascal's Triangle."""


def pascal_triangle(n):
    """Create a function that returns a list of lists of Pascal’s triangles."""
    triNum = n
    lists = []
    for list in range(triNum):
        angle = []
        for integer in range(list + 1):
            if integer == 0:
                angle.append(1)
                continue
            if integer == list:
                angle.append(1)
                continue
            down = lists[list - 1][integer]
            downOne = lists[list - 1][integer - 1]
            angle.append(downOne + down)
        lists.append(angle)
    return (lists)
