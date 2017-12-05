#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
  // FILE* file;
  // int fdpipe[2];
  int f; // for forking
  char buf[4096]; // will contain name of working directory // = (char *)malloc(100 * sizeof(char));
  char * dest = (char*)calloc(4000, sizeof(char)); // for fgets()
  char ** line; // for parse_argC()
  char ** commands; // for parse_args()
  char ** placeholder0; // so that we can free the memory allocated to line even after we increment line

  f = 1; // to get into while loop
  // buf = 0;

  while (f) { // parent keeps reading from stdin until user gives exit command
    getcwd(buf, sizeof(buf));
    printf("%s $ ", buf);
    fgets(dest, 4000, stdin);
    dest[strlen(dest) -1] = 0; //gets rid of the new line at the end of the parsed array

    // printf("%d\n", commands[1]);
    
    placeholder0 = line = parse_argC(dest); //separate by semicolons;
    
    while (f && *line) {
      // parent loops through commands that had been separated by semicolons
      
      *line = trim(*line); // get rid of surrounding whitespace
      commands = parse_args(*line); // separate by spaces
      
      
      if (strncmp(line[0], "exit", 4) == 0) {
	// free(buf);
	free(dest);
	free(line);
        free(commands);
	return 0;
      }
     
      //else 
      if (strncmp(line[0], "cd", 2) == 0) {
	//printf("[%s]\n", commands[1]);
	chdir(commands[1]);
	free(commands);
	// free(dest);
	// free(line);
	// free(commands);
      }
      else { // any command besides exit and cd
    
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
    free(placeholder0);
  } // end outer while loop

  //------------Only the child will get to this part:------------

  char ** dummy; // to walk through commands
  // char * arg[2];
  // int exec;
  int fd; // to contain file descriptor of opened file
  int status; // for wait() call
  int descriptors[2]; // for pipe
  char ** placeholder1; // so that we can still free memory occupied by commands
  // int pid;
  
  // else{
  /*
  free(dest);
  */
  
  // free(placeholder);
  

  
  // free(*line);
  placeholder1 = dummy = commands;

  // make placeholder no longer map to commands, but still be at same memory location
  placeholder1++;
  placeholder1--;

  // move dummy to end of commands
  while (*dummy) {
    dummy++;
  }
  dummy--;
  
  // f = 1;
  // arg[1] = 0;
  // exec = 1;
  while (f == 0 && dummy > placeholder1) { // iterate through commands backwards
    // printf("%x", dummy);
    if (strncmp(*dummy, ">\0", 2) == 0) {
      *dummy = 0; // to separate commands from filename
      /*
      f = fork();
      if (f) {
	exec = 0;
	wait(&status);
      } else {
      */
      commands = dummy;
      while (commands > placeholder1 &&
	     /*
	     strncmp(commands[-1], ">\0", 2) &&
	     strncmp(commands[-1], "<\0", 2) &&
	     */
	     strncmp(commands[-1], "|\0", 2)) {
	// move commands to beginning of this section
	commands--;
      }
	// exec = 1;

      // redirect stdout to the specified file
      fd = open(dummy[1], O_WRONLY | O_CREAT, 0644);

      dup(STDOUT_FILENO);
      dup2(fd, STDOUT_FILENO);

      close(fd);
      // }
    } else if (strncmp(*dummy, "<\0", 2) == 0) {
      *dummy = 0; // to separate commands from filename
      /*
      f = fork();
      if (f) {
	commands = dummy;
	commands++;
	// exec = 1;
	*/
      commands = dummy;
      while (commands > placeholder1 &&
	     /*
	     strncmp(commands[-1], ">\0", 2) &&
	     strncmp(commands[-1], "<\0", 2) &&
	     */
	     strncmp(commands[-1], "|\0", 2)) {
	// move commands to beginning of this section
	commands--;
      }

      // redirect stdin from the specified file
      fd = open(dummy[1], O_RDONLY);

      dup(STDIN_FILENO);
      dup2(fd, STDIN_FILENO);

      close(fd);
	// wait(&status);
      /*
      } else {
	exec = 0;
      }
      */
    } else if (strncmp(*dummy, "|\0", 2) == 0) { // redirect stdout of one command to stdin of next
      *dummy = 0; // to separate parent's version of commands from child's

      // set up pipe
      pipe(descriptors);
      f = fork();
      if (f) {
	close(descriptors[1]); // close write end of pipe
	commands = dummy;
	commands++; // parent's command is on the right side of the "|"
	// exec = 1;

	// redirect stdin from the read end of the pipe
	dup(STDIN_FILENO);
	dup2(descriptors[0], STDIN_FILENO);

	close(descriptors[0]); // close read end of pipe
	wait(&status);
      } else {
	close(descriptors[0]); // close read end of pipe
	commands = dummy;
	while (commands > placeholder1 &&
	       /*
	       strncmp(commands[-1], ">\0", 2) &&
	       strncmp(commands[-1], "<\0", 2) &&
	       */
	       strncmp(commands[-1], "|\0", 2)) {
	  // child's command is on the left side of the pipe
	  commands--;
	}
	// exec = 1;

	// redirect stdout to the write end of the pipe
	dup(STDOUT_FILENO);
	dup2(descriptors[1], STDOUT_FILENO);
	close(descriptors[1]);
      } // end else statement
    } // end else if statement
    dummy--;
  } // end while loop
  /*
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
  */
  // if (exec) {

  // commands execute in order of child -> parent (aka left -> right)
  execvp(commands[0], commands);
  
    // }
  // }
      //execvp(command[0],command);
      // return getpid();
      // }
  
  free(dest);
  free(placeholder1);
  return 0;
}
