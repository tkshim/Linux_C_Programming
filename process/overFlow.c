#include <stdio.h>

int main(void)
{
  /*Setting of char size*/
  char str[5];

  puts("Please input any words");
  fgets(str, sizeof(str), stdin);
  puts(str);

  return 0;
}
/* Reference: Programing Place Plus web site*/
