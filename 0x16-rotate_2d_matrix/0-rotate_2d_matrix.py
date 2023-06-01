#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):

    """Rotations 2D
    """
    new_matrix = []
    c = 0
    length = len(matrix)
    for i in range(0, length):
        for j in reversed(matrix):
            new_matrix.append(j[i])
    for k in range(0, length):
        for a in range(0, len(matrix[k])):
            matrix[k][a] = new_matrix[c]
            c += 1
