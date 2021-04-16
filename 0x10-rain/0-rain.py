#!/usr/bin/python3
"""TASK 0. Rain."""


def rain(walls):
    """Calculate how much water will be retained after it rains."""
    if len(walls) is 0:
        return(0)
    beforeRetained = 0
    afterRetained = 0
    currentAmountOfWAter = 0
    for length in range(len(walls)):
        if walls[length] >= walls[beforeRetained]:
            beforeRetained = length
        else:
            CalculatedWater = walls[beforeRetained] - walls[length]
            afterRetained = afterRetained + CalculatedWater
            currentAmountOfWAter = currentAmountOfWAter + CalculatedWater
    endOfWaterContainer = len(walls) - 1
    if beforeRetained < endOfWaterContainer:
        afterRetained = afterRetained - currentAmountOfWAter
        beforeRetained = endOfWaterContainer
        rainWater = beforeRetained
        for water in range(endOfWaterContainer, rainWater, -1):
            if walls[water] >= walls[beforeRetained]:
                beforeRetained = water
            else:
                CalculatedWater = walls[beforeRetained] - walls[water]
                afterRetained = afterRetained + CalculatedWater
    totalAmountofRainWAter = afterRetained
    return(totalAmountofRainWAter)
