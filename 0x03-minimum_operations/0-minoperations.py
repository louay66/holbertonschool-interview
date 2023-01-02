#!/usr/bin/python3
"""calculates the fewest number of
   operations needed to result in exactly n H
   """


def minOperations(n):

    newvalue = n
    minm = 0

    if n <= 0 or n is None:
        return 0
    while newvalue != 1:
        if newvalue % 2 == 0:
            newvalue = newvalue / 2
            minm += 2
        elif newvalue % 3 == 0:
            newvalue = newvalue / 3
            minm += 3
        elif newvalue % 4 == 0:
            newvalue = newvalue / 4
            minm += 4
        elif newvalue % 5 == 0:
            newvalue = newvalue / 5
            minm += 5
        else:
            minm += newvalue
            newvalue = 1
    return minm
