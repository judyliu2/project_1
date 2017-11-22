#include <stdio.h>
#include <unistd.h>

int main()
{
  char dest[256];
  int f;

  printf("Enter command: ");
  fgets(dest, sizeof(dest), stdin);

  f = fork();

  if (f) {
  }

  return 0;
}
