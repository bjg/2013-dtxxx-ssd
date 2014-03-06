#include <stdio.h>

int main()
{
    int nresp = 0x4000000000000000;
    unsigned long long allocated = nresp * sizeof(char *);

    printf("%llu\n", allocated);
    return 0;
}
