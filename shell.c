#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  int f; // for forking
  char *  dest = (char*)calloc(100, sizeof(char)); // for fgets()
  char ** line = (char **)calloc(20, sizeof(char*)); // for parse_argC()
  char ** commands = (char**) calloc(20, sizeof(char*)); // for parse_args()

  f = 1; // to get into while loop

  while (f) {
    printf("Enter commands: ");
    fgets(dest, 30, stdin);
    dest[strlen(dest) -1] = 0; //gets rid of the new line at the end of the parsed array

    // printf("%d\n", commands[1]);
    
    line = parse_argC(dest); //separated by semicolons;
    
    while (f && *line) { // parent loops through commands that were separated by semicolons
      // printf("%d\n", line);
      // commands = parse_args(dest);
      // printf("[%s]\n", line[0]);
      
      commands = parse_args(*line);
      
      // printf("%d\n", parse_args(*line));
      // printf("[%s]\n", commands[0]);
    
    // int num_of_commands = sizeof(commands)/sizeof(char*);
    // for (i = 0; line[i]
    
   
    //command = parse_args(command[num_of_commands]); //separated by spaces
    
      if (strncmp(commands[0], "exit", 4) == 0) {
	free(dest);
	free(line);
	free(commands);
	exit(EXIT_SUCCESS);
      }
      //else 
      if (strncmp(commands[0], "cd", 2) == 0) {
	printf("[%s]\n", commands[1]);
	chdir(commands[1]);
      }
      else {
    
	f = fork();
    
	if (f){
	  int status;
	  int finish = wait(&status);
	}
      }
      
      line++;
      
    } // end inner while loop
  } // end outer while loop

  //------------Only the child will get to this part:------------
  
  // else{
  /*
  free(dest);
  free(line);
  */
  
  execvp(commands[0], commands);
  
      //execvp(command[0],command);
      // return getpid();
      // }
 
  return 0;
}
