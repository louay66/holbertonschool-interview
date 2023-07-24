#!/usr/bin/python3
"""island_perimeter
    """


def island_perimeter(grid):
    """_summary_

    Args:
        grid (list): list of sea of 0 that hold a island if 1

    Returns:
        int: perimeter of the island
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if j == 0 or j == len(grid[i]) or i == 0 or i == len(grid):
                    return 0
                if grid[i][j-1] == 0:
                    perimeter += 1
                if grid[i][j + 1] == 0:
                    perimeter += 1
                if grid[i - 1][j] == 0:
                    perimeter += 1
                if grid[i + 1][j] == 0:
                    perimeter += 1
    return perimeter
