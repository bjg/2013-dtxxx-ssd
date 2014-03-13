#include <stdio.h>

int main()
{
    int length = 0xffffffff;
    printf("%x %d %u\n", (length + 1), (length + 1), (length + 1));
    return 0;
}
