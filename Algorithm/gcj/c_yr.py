from string import ascii_uppercase


def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)


T = int(input())
for i in range(1, 1 + T):
    n, l = map(int, input().split())
    a = list(map(int, input().split()))
    x = gcd(a[0], a[1])
    b = [a[0] // x, x]
    for y in a[1:]:
        b.append(y // b[-1])
        c = {
            xx: yy
        for xx, yy in zip(sorted(list(set(b))), ascii_uppercase)
        }
        print('Case #{0}: {1}'.format(i, ''.join(c[xx] for xx in b)))
