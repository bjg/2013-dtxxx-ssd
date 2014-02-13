#!/usr/bin/env python3

import time

P = 295075153
captured = [210205973, 22795300, 58776750, 121262470, 264731963, 140842553, 242590528, 195244728, 86752752]

def nextPrng(x, y):
    X = (2 * x + 5) % P
    Y = (3 * y + 7) % P
    return X, Y, X ^ Y

F = captured[0]
G = captured[1]

t = time.clock()
for x in range(P):
    y = F ^ x
    X, Y, Z = nextPrng(x, y)
    if Z == G:
        x1, y1 = X, Y

        for k in range(2, len(captured)):
            X1, Y1, Z1 = nextPrng(x1, y1);
            if Z1 != captured[k]:
                break
            x1, y1 = X1, Y1;

        if Z1 == captured[len(captured)-1]:
            _, _, Z2 = nextPrng(X1, Y1)
            print(captured[k], "->", Z2)
            break;

print(time.clock() - t, "seconds")
