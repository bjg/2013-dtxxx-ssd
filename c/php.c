#include <stdio.h>

int main()
{
    char buf[22];

    char *username = "xx.php";
    snprintf(buf,sizeof(buf),"/data/profiles/%s.txt", username);
    printf("%s\n", buf);
    return 0;
}
