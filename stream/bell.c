#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
  int i;
  printf("10decimal:Ascii\n\n");
  for (i = 97; i < 123; i++) {
    printf("%2d:%2c\n", i, i);
  }
  exit(0);
}
