#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char dest[256];

  printf("Enter command: ");
  fgets(dest, sizeof(dest), stdin);

  return 0;
}
