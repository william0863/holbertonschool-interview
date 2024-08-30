#!/usr/bin/python3
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
