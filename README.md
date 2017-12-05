# Project 1: Shelling-out Commands
## By Judy Liu and Gian Tricarico

1. Features
   - Forks and executes commands
   - Parses through multiple commands 
   - Redirects using >, <
   - Uses simple pipes
   - Can accept commands with multiple redirections and/or multiple pipes
  
2. Unsucessful attempts
   - Redirecting using < (fixed)
   - Simple pipes (fixed)
   
3. Bugs
   - When parsing through multiple commands, so spaces can be used between semicolons (fixed)
   - When you type enough characters in the shell for it to go to the next line,
     you can't do backspace on the stuff from the previous line for some reason.
   - If you make the shell read from a file containing commands
     (`./tester < <*command file*>) and that file does not have an exit file at
     the end, the shell will go into an infinite loop of printing the command
     prompt.
4. Files & Function Headers

methods.c
```C
Handles all line-parsing functions
/*
 * Function: parse_args
 * --------------------
 * separates a string into an array for use with execvp
 *
 *  s1: a string
 *
 *  returns: Array of strings where each entry is a token separated by spaces
 *
 *  Precondition: s1 is null-terminating and does not exceed 799 tokens
 *  separated by spaces.
 *
 *  Postcondition: replaces each space in s1 with a null character
 */
 
/*
 * Function: parse_argC
 * --------------------
 * separates a string into an array using semicolon as the delimiter
 *
 *  s1: a string
 *
 *  returns: Array of strings where each entry is a token separated by
 *           semicolons
 *
 *  Precondition: s1 is null-terminating and does not exceed 799 tokens
 *  separated by semicolons.
 *
 *  Postcondition: replaces each semicolon in s1 with a null character
 */

/*
 * Function: trim
 * --------------
 * Removes spaces from the beginning and end of a string
 *
 *  s: a string
 *
 *  returns: a string with no spaces at the beginning or at the end
 *
 *  Precondition: s is null-terminating.
 *
 *  Postcondition: replaces the spaces at the end of s (but not at the
 *                 beginning) with null characters
 */
```
   
shell.h
```
contains headers
```

shell.c
```
Runs the shell and handles forking
```
