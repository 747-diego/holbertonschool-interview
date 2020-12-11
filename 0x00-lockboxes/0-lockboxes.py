#!/usr/bin/python3
"""Write a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """You have n number of locked boxes in front of you."""
    """Each box is numbered sequentially from 0 to n - 1."""
    """And each box may contain keys to the other boxes."""

    lockedBoxes = boxes
    boxesLength = len(lockedBoxes)
    currentKeys = [0]

    # Loop through the current keys and compare the content
    # inside of the locked-Boxes with current-Keys
    for keys in currentKeys:
        for currentBox in lockedBoxes[keys]:
            if currentBox not in currentKeys and currentBox < boxesLength:
                currentKeys.append(currentBox)

    # After adding the keys that were missing, lets compare
    # the final length  of both arrays
    if len(currentKeys) == boxesLength:
        # print(currentKeys)
        return True
    # print(currentKeys)
    return False
