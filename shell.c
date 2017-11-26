#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  char dest[256];

  printf("Enter command: ");
  fgets(dest, sizeof(dest), stdin);
  //printf("%s",dest);
  char commands[256];
  strcpy(commands,dest);
  char ** test = parse_args(commands);
  
  int child = fork();
   if (!child){
    
     execvp(test[0], test);
   }
   else{
     //printf("Enter command: ");
     fgets(dest, sizeof(dest), stdin);
     //printf("%s",dest);
     char commands[256];
     strcpy(commands,dest);
     char ** test = parse_args(commands);
     child = fork();
     
     if(!child){
       execvp(test[0], test);
     }

     int status;
     int finished = wait(&status);
     int ret = WEXITSTATUS(status);
   }
   
  return 0;
}
