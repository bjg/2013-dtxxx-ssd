#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: count <n>\n");
        exit(0);
    }
    unsigned long long n = 1 << atol(argv[1]);
    unsigned long long i, sum;
    for (i = 0, sum = 0; i < n; i++) {
        sum++;
    }
    printf("%llu\n", sum);
}
