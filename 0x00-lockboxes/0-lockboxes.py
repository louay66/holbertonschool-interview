#!/usr/bin/python3
""" canUnlockAll is function"""


def canUnlockAll(boxes):
    """canUnlockAll is a function that check if all boxes
        can be opned by th key into boxes

    Args:
        boxes (list of list ): is a list of boxes

    Returns:
        boolean: true if all boxes are opned and unlocked and false otherwise
    """
    unlocked = [0]
    for box_id, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
