#!/usr/bin/python3
"""
valid the list of int if thare is character in
utf-8 ot note
"""


def validUTF8(data):

    bit_count = 0
    for byte in data:
        if bit_count == 0:
            if (byte >> 5) == 0b110:
                bit_count = 1
            elif (byte >> 4) == 0b1110:
                bit_count = 2
            elif (byte >> 3) == 0b11110:
                bit_count = 3
            elif (byte >> 7):
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            bit_count -= 1
    return bit_count == 0
