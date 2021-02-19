#!/usr/bin/python3
"""Write a method that determines if a given data set."""
"""Represents a valid UTF-8 encoding."""


def validUTF8(data):
    """Return: True if data is a valid UTF-8 encoding, else return False."""
    byteInteger = 0
    dataOne = 1 << 7
    dataTwo = 1 << 6

    for byte in data:
        utf = 1 << 7
        if byteInteger == 0:
            while (byte & utf):
                byteInteger = byteInteger + 1
                utf = utf >> 1
            if byteInteger == 0:
                continue
            if byteInteger > 4 or byteInteger == 1:
                return False
        else:
            if not (byte & dataOne and not (byte & dataTwo)):
                return False
        byteInteger = byteInteger - 1
    if byteInteger:
        return False
    else:
        return True
