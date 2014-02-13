#include <stdio.h>

void * find_start(void)
{
  __asm__("movq %rsp, %rax");
}

int main()
{
  printf("%p\n", find_start());
}
