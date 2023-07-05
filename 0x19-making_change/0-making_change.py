#!/usr/bin/python3
"""
Simple python code to determine the fewest
number of coins needed to meet agiven amount " total ".
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0
    coins.sort(reverse=true)
    fewest = 0
    i = 0
    while (i < len(coins)):
        if total == 0:
            return fewest
        if coins[i] > total:
            i += 1
        else:
            total -= coins[i]
            fewest += 1
    return -1
