#include <stdio.h>

int main()
{
    unsigned int uid = 0xabcd0000;
    printf("full=%u narrowed=%hd\n", uid, (short)uid);
    return 0;
}
