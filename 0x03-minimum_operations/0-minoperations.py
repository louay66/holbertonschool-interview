#!/usr/bin/python3
"""calculates the fewest number of
   operations needed to result in exactly n H
   """


def minOperations(n):
    """
    method that calculates the fewest operations
    """
    newvalue = n
    i = 2
    minm = 0
    if (not isinstance(n, int)):
        return 0
    if n < 2:
        return 0
    while newvalue != 1:
        if newvalue % i == 0:
            newvalue = newvalue / i
            minm += i
        else:
            i = i + 1        
    return minm
