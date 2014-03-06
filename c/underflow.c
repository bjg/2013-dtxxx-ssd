#include <stdio.h>

int main()
{
    int length = 0;
    unsigned hdr_len = 8;

    unsigned data_len = length - hdr_len;

    printf("%u\n", data_len);
    return 0;
}
