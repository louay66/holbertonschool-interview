#!/usr/bin/python3
"""
valid the list of int if thare is character in
utf-8 ot note
"""


def validUTF8(data):
    for i in data:
        if (i >= 0 and i <= 127):
            i = i >> 31
            if i != 0:
                return False
        elif (i >= 128 and i <= 1919):
            a = i << 8
            a = a >> 30
            i = i >> 29
            if i != 6 or a != 2:
                return False
        elif (i >= 1920 and i <= 61440):
            b = i << 16
            b = b >> 30
            a = i << 8
            a = i >> 30
            i = i >> 28
            if i != 14 or a != 2 or b != 2:
                return False
        elif (i >= 61440 and i <= 1048575):
            c = i << 24
            c = c >> 30
            b = i << 16
            b = b >> 30
            a = i << 8
            a = a >> 30
            i = i >> 27
            if i != 30 or a != 2 or b != 2 or c != 2:
                return False
    return True
