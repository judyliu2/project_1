#include <stdio.h>
#include <unistd.h>
#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
  
    char *  dest= (char *) calloc(20, sizeof(char*));
    printf("Enter commands: ");
    fgets(dest, 30, stdin);
    
    dest[strlen(dest) -1] = 0; //gets rid of the new line at the end of the parsed array
    char ** commands = (char**) calloc(20, sizeof(char*));
    commands = parse_args(dest);
    // commands = parse_argC(dest); //separated by semicolons;

    //int num_of_commands = 0;
    //num_of_commands = sizeof(commands)/sizeof(char*);
    
    //while(num_of_commands){
    //char ** command = (char**) calloc(20,sizeof(char*));
    //command = parse_args(command[num_of_commands]); //separated by spaces
    
    //make this into a loop
    //while(command){
    int parent = getpid();
    int child = fork();
    
    if (getpid() == parent){
      int status;
      int finish = wait(&status);
    }
    else{
      execvp(commands[0], commands);
      //execvp(command[0],command);
      return getpid();
    }
    //}
 
  return 0;
}
