#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

#define SZ(a)	sizeof(a) / sizeof(a[0])

static uint64_t getTimeInMillis()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000L + tv.tv_usec / 1000L;
}

static const uint32_t P = 295075153;
static uint32_t const captured[] = {210205973, 22795300, 58776750, 121262470, 264731963, 140842553, 242590528, 195244728, 86752752};

static void nextPrng(uint32_t x, uint32_t y, uint32_t *X, uint32_t *Y, uint32_t *Z)
{
    *X = (2 * x + 5) % P;
    *Y = (3 * y + 7) % P;
    *Z = *X ^ *Y;
}

int main(int argc, char *argv[])
{
    uint32_t F = captured[0];
    uint32_t G = captured[1];
    uint32_t x, y;
    uint64_t t = getTimeInMillis();

    for (x = 0; x < P; x++) {
        uint32_t X = 0, Y = 0, Z = 0;

        y = F ^ x;
        nextPrng(x, y, &X, &Y, &Z);
        if (Z == G) {
            uint32_t x1 = X, y1 = Y, X1, Y1, Z1;
            int k;

            for (k = 2; k < SZ(captured); k++) {
                nextPrng(x1, y1, &X1, &Y1, &Z1);
                if (Z1 != captured[k]) {
                    break;
                }
                x1 = X1;
                y1 = Y1;
            }
            if (k == SZ(captured)) {
                uint32_t X2, Y2, Z2;
                nextPrng(X1, Y1, &X2, &Y2, &Z2);
                printf("%u -> %u\n", captured[k - 1], Z2);
                break;
            }
        }
    }
    printf("%lf seconds\n", (double)(getTimeInMillis() - t) / 1000.0);
}

