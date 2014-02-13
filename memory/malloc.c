#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *p = (char *) malloc(14);
  char *q = (char *) malloc(16);

  printf("p=%p q=%p dist=%d\n", p, q, (int)(q-p));

  strcpy(&p[24], "Overflow");
  printf("%s\n", q);

  free(p);
  free(q);
}
