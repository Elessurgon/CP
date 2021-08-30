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


def main():
    pass


S = input()


def check(mid, array, n, K):
    count = 0
    sum = 0
    for i in range(n):
        if (array[i] > mid):
            return False
        sum += array[i]
        if (sum > mid):
            count += 1
            sum = array[i]
    count += 1
    if (count <= K):
        return True
    return False


def solve(array, n, K):
    start = max(array)
    end = 0
    for i in range(n):
        end += array[i]
    answer = 0
    while (start <= end):
        mid = (start + end) // 2
        if (check(mid, array, n, K)):
            answer = mid
            end = mid - 1
        else:
            start = mid + 1
    return answer


x = inlt()
print(x)
a = x[0]
b = x[1]
c = x[2]

if pow(a, b) < pow(b, c):
    print("<")
elif pow(a, b) > pow(b, c):
    print(">")
else:
    print("=")
