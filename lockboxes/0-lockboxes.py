#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 
and each box may contain keys to the other boxes
This is a method that determines if all the boxes can be opened.

If yes, return True
If no, return False
"""


def canUnlockAll(boxes):
    n = len(boxes)
    opened = set([0])
    keys = set(boxes[0])

    while keys:
        new_key = keys.pop()
        if new_key < n and new_key not in opened:
            opened.add(new_key)
            keys.update(boxes[new_key])

    return len(opened) == n
