#include <stdio.h>

int main()
{
    short s1 = 0x8001;
    printf("0x%hx (%hd) -> 0x%x (%d)\n", s1, s1, (int)s1, (int)s1);
    printf("0x%hx (%hu) -> 0x%x (%u)\n", s1, s1, (unsigned int)s1, (unsigned int)s1);

    unsigned short s2 = 0x8001;
    printf("0x%hx (%hu) -> 0x%x (%u)\n", s2, s2, (int)s2, (int)s2);

    // 0x0000ffff or 0xffffffff;

    return 0;
}
