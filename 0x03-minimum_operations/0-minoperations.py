#!/usr/bin/python3
"""calculates the fewest number of
   operations needed to result in exactly n H
   """


def minOperations(n):
    """
    method that calculates the fewest operations
    """
    newvalue = n
    minm = 0
    if not isinstance(n, int):
        return 0
    if n < 2:
        return 0
    while newvalue != 1:
        if newvalue % 2 == 0:
            newvalue = newvalue / 2
            minm += 2
        elif newvalue % 3 == 0:
            newvalue = newvalue / 3
            minm += 3
        elif newvalue % 5 == 0:
            newvalue = newvalue / 5
            minm += 5
        elif newvalue % 7 == 0:
            newvalue = newvalue / 7
            minm += 7
        else:
            minm += newvalue
            newvalue = 1
    return int(minm)
