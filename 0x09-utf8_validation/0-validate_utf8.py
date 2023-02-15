#!/usr/bin/python3
"""
valid the list of int if thare is character in
utf-8 ot note
"""


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding,
    else return False
    """
    i = 0
    while i < len(data):
        count = 0
        mask = 1 << 7
        while mask & data[i]:
            count += 1
            mask >>= 1
        if count == 0:
            pass
        elif count == 1 or count > 4:
            return False
        else:
            for j in range(i + 1, i + count):
                if j >= len(data) or (data[j] >> 6) != 2:
                    return False
            i += count - 1
        i += 1
    return True