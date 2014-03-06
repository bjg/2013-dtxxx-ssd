#include <stdio.h>

main()
{
    char n = 56;

    printf("%x, %x, %x\n", n&0xff, ~n&0xff, -n&0xff);
    return 0;
}
