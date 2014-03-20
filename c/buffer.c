#include <stdio.h>

#define BUFLEN 8

int main()
{
    char buf[BUFLEN];
    char overrun[BUFLEN];
    char *src = "Hello, world";
    int i;

    for (i = 0; i < sizeof(buf); i++) {
        buf[i] = 0xee;
    }

    //sprintf(buf, "%s", src);
    snprintf(buf, sizeof(buf), "%s", src);

    for (i = 0; i < sizeof(buf) + 10; i++) {
        printf("0x%02x ", buf[i]);
    }
    printf("\n");

    printf("%s\n", buf);
    return 0;
}
