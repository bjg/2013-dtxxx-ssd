#include <stdio.h>

int main()
{
    short s1 = 0x8001;
    printf("0x%hx (%hd) -> 0x%08x (%d)\n", s1, s1, (int)s1, (int)s1);
    printf("0x%hx (%hu) -> 0x%08x (%u)\n", s1, s1, (unsigned int)s1, (unsigned int)s1);

    unsigned short s2 = 0x8001;
    printf("0x%hx (%hu) -> 0x%08x (%u)\n", s2, s2, (int)s2, (int)s2);

    short s3 = 0x7001;
    printf("0x%hx (%hd) -> 0x%08x (%d)\n", s3, s3, (int)s3, (int)s3);

    return 0;
}
