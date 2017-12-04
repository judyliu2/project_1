# Project 1: Shelling-out Commands
## By Judy Liu and Gian Tricarico

1. - Features
   - Forks and executes commands
   - Parses through multiple commands 
   - Redirects using >, <
   - Uses simple pipes
  
2. Unsucessful attempts
   - None   
3. Bugs
   - When parsing through multiple commands, so spaces can be used between semicolons
4. Files & Function Headers

```
functions.c 
   - Contains functions
   /*===== char * * parse args()=======
   - Inputs: char * line
   - Returns Array of strings separated by spaces
   */
   /*===== char * * parse argC()=======
   - Inputs: char * line
   - Returns Array of strings separated by semicolons
   */
   /*===== char * trim) ===========
   - Inputs: char * line
   - Returns a char *
   
shell.h
   - contains header files
shell.c
   - Runs the shell and handles forking
```
