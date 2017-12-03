#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
  FILE* file;
  int fd;
  int fdpipe[2];
  int pid;
  int f; // for forking
  char buf[4096]; // will contain name of working directory // = (char *)malloc(100 * sizeof(char));
  char * dest = (char*)calloc(100, sizeof(char)); // for fgets()
  char ** line; // = (char **)calloc(20, sizeof(char*)); // for parse_argC()
  char ** commands; // = (char**) calloc(20, sizeof(char*)); // for parse_args()
  char ** placeholder; // so that we can free the memory allocated to line even after we increment line

  f = 1; // to get into while loop
  // buf = 0;

  while (f) {
    getcwd(buf, sizeof(buf));
    printf("%s $ ", buf);
    fgets(dest, 30, stdin);
    dest[strlen(dest) -1] = 0; //gets rid of the new line at the end of the parsed array

    // printf("%d\n", commands[1]);
    
    placeholder = line = parse_argC(dest); //separated by semicolons;
    
    while (f && *line) { // parent loops through commands that were separated by semicolons
      
      
      commands = parse_args(*line);
      
      
      if (strncmp(commands[0], "exit", 4) == 0) {
	// free(buf);
	free(dest);
	free(line);
	free(commands);
	return 0;
      }
     
      //else 
      if (strncmp(commands[0], "cd", 2) == 0) {
	//printf("[%s]\n", commands[1]);
	chdir(commands[1]);
	free(commands);
	// free(dest);
	// free(line);
	// free(commands);
      }
      else {
    
	f = fork();
    
	if (f){
	  int status;

	  free(commands);
	  wait(&status);
	  /*
	  if (strncmp(commands[1], "|",1) == 0){
	    char * arg[] = {commands[2], NULL};
	    dup2(fdpipe[1], 1);
	    close(fdpipe[0]);
	    execvp(arg[0], arg);
	  }
	  */
	}
      }
      
      line++;
      
    } // end inner while loop
    free(placeholder);
  } // end outer while loop

  //------------Only the child will get to this part:------------
  
  // else{
  /*
  free(dest);
  */
  
  // free(placeholder);
  


  // free(*line);
  if (commands[1] == ">" || commands[1] == "<" || commands[1] == "|") {
	
	if (strncmp(commands[1], ">", 1) == 0){//redirects stdout by overwriting file
	  char * arg[] = { commands[0], NULL};
	  fd = open(commands[2], O_WRONLY | O_CREAT, 0644); // creates a new file
	  dup2(fd, 1); //stdout(1) is put into the new file
	  
	  close(fd);
	  execvp(arg[0] , arg);
	}
	
	if (strncmp(commands[1], "<", 1) == 0){//redirects stdin from file
	  char * arg[] = { commands[0], NULL};
	  fd = open(commands[0], O_RDONLY, 0644);
	  dup2(fd, 0); //stdin (0)
	  close(fd);
	  execvp(arg[0] , arg);
	}
	
	
	if (strncmp(commands[1], "|", 1) == 0){ //make a copy of stdout of file and  use it for stdin of the other
	  char * arg[] = { commands[0], NULL};
	  dup2(fdpipe[0], 0);
	  close(fdpipe[1]);
	  execvp (arg[0], arg);
	  
	
	}
   }
   
  else{
  execvp(commands[0], commands);
  }
      //execvp(command[0],command);
      // return getpid();
      // }
 
  return 0;
}
