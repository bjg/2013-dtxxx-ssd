#!/usr/bin/env python3

import time

P = 295075153
captured = [
    210205973,
    22795300,
    58776750,
    121262470,
    264731963,
    140842553,
    242590528,
    195244728,
    86752752
]

class Prng(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def nextPrng(self):
        self.x = (2 * self.x + 5) % P
        self.y = (3 * self.y + 7) % P
        return self.x ^ self.y

    def verify(self):
        q = Prng(self.x, self.y)
        for c in captured[2:]:
            if c != q.nextPrng():
                return False
        print(q.nextPrng())
        return True

t = time.clock()
for x in range(P):
    p = Prng(x, captured[0] ^ x)
    if p.nextPrng() == captured[1] and p.verify():
        break;

print(time.clock() - t, "seconds")
