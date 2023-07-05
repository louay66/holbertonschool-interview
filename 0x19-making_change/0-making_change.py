#!/usr/bin/python3
"""
finds fewest number of coins needed
to meet a given amount total.
"""


def makeChange(coins, total):
    """
    returns fewest number of coins needed
    to meet a given amount total.
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
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
