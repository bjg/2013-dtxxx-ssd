#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>

#define SZ(a)    sizeof(a) / sizeof(a[0])

static uint64_t getTimeInMillis()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000L + tv.tv_usec / 1000L;
}

static const uint32_t P = 295075153;
static uint32_t const captured[] = {
    210205973,
    22795300,
    58776750,
    121262470,
    264731963,
    140842553,
    242590528,
    195244728,
    86752752
};

typedef struct {
    uint32_t x, y;
} prng_t;

static uint32_t
nextPrng(prng_t *p)
{
    p->x = (2 * p->x + 5) % P;
    p->y = (3 * p->y + 7) % P;
    return p->x ^ p->y;
}

static bool
verify(prng_t *p)
{
    prng_t q = *p;
    int k;

    for (k = 2; k < SZ(captured); k++) {
        if (captured[k] != nextPrng(&q)) {
            return false;
        }
    }
    printf("%u\n", nextPrng(&q));
    return true;
}

int main(int argc, char *argv[])
{
    uint64_t t = getTimeInMillis();
    int x;
    for (x = 0; x < P; x++) {
        prng_t p = {x, captured[0] ^ x};
        if (captured[1] == nextPrng(&p) && verify(&p)) {
            break;
        }
    }
    printf("%lf seconds\n", (double)(getTimeInMillis() - t) / 1000.0);
}

