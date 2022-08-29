import math
import sys
from collections import Counter
input = sys.stdin.readline


def inp():
    return(int(input()))


def inlt():
    return(list(map(int, input().split())))


def insr():
    s = input()
    return(list(s[:len(s) - 1]))


def invr():
    return(map(int, input().split()))


def check(m, t, w, low):
    wd = 0
    for h, r in t:
        x = h + r * m
        if x >= low:
            wd += x
    return wd >= w


def solve():
    n, w, low = inlt()
    t = [inlt() for _ in range(n)]
    l = 0
    r = 1e18
    if check(0, t, w, low):
        print(0)
        return
    while(l + 1 < r):
        m = int((l + r)) // 2
        if check(m, t, w, low):
            r = m
        else:
            l = m
    print(r)


solve()
