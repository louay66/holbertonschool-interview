#!/usr/bin/python3
"""
valid the list of int if thare is character in
utf-8 ot note
"""


def validUTF8(data):
    count_byte = 0
    for i in data:
        if count_byte == 0:
            if (i >> 5) == 0b110:
                count_byte = 1
            elif (i >> 4) == 0b1110:
                count_byte = 2
            elif (i >> 3) == 0b11110:
                count_byte = 3
            elif (i >> 7):
                return False
        else:
            if (i >> 6) != 0b10:
                return False
            count_byte -= 1
    return count_byte == 0
