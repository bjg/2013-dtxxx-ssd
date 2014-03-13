#include <stdio.h>

int main()
{
    signed int uid = 0xabcd0000;
    printf("full=%d narrowed=%hd\n", uid, (unsigned short)uid);
    return 0;
}
