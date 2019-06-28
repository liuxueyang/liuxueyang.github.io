#!/usr/bin/env python

import math

def gcd(x, y):
    if y == 0:
        return x
    if x < y:
        x, y = y, x
    while y != 0:
        x, y = y, x % y
    return x

def is_prime(n):
    for x in range(2, int(math.sqrt(n)) + 1):
        if n % x == 0:
            return False
    return True

T = int(input())

for i in range(T):
    print("Case #{}: ".format(i + 1), end='')
    N, L = map(int, input().split())
    a = list(map(int, input().split()))
    b = [None] * (len(a) + 1)
    if a[0] == a[1]:
        g = int(math.sqrt(a[0]))
    else:
        g = gcd(a[0], a[1])
    # assert(g != 0)
    b[0] = a[0] // g
    t = b[0]
    for i, x in enumerate(a):
        # assert(t != 0)
        b[i+1] = x // t         # Runtime Error
        t = b[i+1]
    n_c = {}
    for i, x in enumerate(sorted(list(set(b)))):
        n_c[x] = chr(i + ord('A'))

    print("n_c = {}, b = {}".format(n_c, b))
    for x in b:
        print(n_c[x], sep='', end='')
    print()
