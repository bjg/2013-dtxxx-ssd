#include <stdio.h>

int main()
{
    signed char wrong = 150;
    unsigned long better = 150;
    printf("wrong=%u better=%u\n", (unsigned int)wrong, (unsigned int)better);
    return 0;
}
