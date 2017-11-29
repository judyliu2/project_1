#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{

  int f = 1;
  char ** commands = (char**) calloc(20, sizeof(char*));
  char *  dest = (char)calloc(100, sizeof(char));
  char ** line = (char *)calloc(20, sizeof(char*));
  int i;

  while (f) {
    printf("Enter commands: ");
    fgets(dest, 30, stdin);
    
    dest[strlen(dest) -1] = 0; //gets rid of the new line at the end of the parsed array

    commands = parse_args(dest);
    printf("%d\n", commands[1]);
    
    line = parse_argC(dest); //separated by semicolons;

    // int num_of_commands = sizeof(commands)/sizeof(char*);
    // for (i = 0; line[i]
    
   
    //command = parse_args(command[num_of_commands]); //separated by spaces
    
    
    if (!strncmp(commands[0], "exit", 4)) {
      break;
    }
    //else 
    if (!strncmp(commands[0], "cd", 2)) {
      chdir(commands[1]);
    }
//else {
    
      f = fork();
    
      if (f){
	int status;
	int finish = wait(&status);
	  }
      //}
  } // end while loop

  // Only child will get to this part:
  
  // else{
  execvp(commands[0], commands);
      //execvp(command[0],command);
      // return getpid();
      // }
 
  return 0;
}
