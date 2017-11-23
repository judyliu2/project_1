#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>

int main()
{
  char dest[256];
  int f;

  printf("Enter command: ");
  fgets(dest, sizeof(dest), stdin);

  char commands[256];
  strcpy(commands,dest);
  char ** test = parse_args(commands);
  execvp(test[0], test);

  /*
  f = fork();

  if (f) {
  }
  */
  return 0;
}
