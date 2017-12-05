#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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
char ** parse_args(char * s1){
	char ** ret = (char **) calloc (800, sizeof(char*));
	int i = 0;    

	while (s1 && i < 799){
	  char * string = strsep (&s1," ");
	  ret[i] = string;
	  i++;
	}
	ret[i] = NULL;
	return ret;
}

/*
 * Function: parse_argC
 * --------------------
 * Separates a string into an array using semicolon as the delimiter
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
char ** parse_argC(char * s1){
	char ** ret = (char **) calloc (800, sizeof(char*));
	int i = 0;

	while (s1 && i < 799){
	  char * string = strsep (&s1,";");
	  ret[i] = string;
	  i++;
	}
	ret[i] = NULL;
	return ret;
}

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
char * trim(char * s)
{
  char * str;
  
  while (*s == ' ') { // remove spaces from front of string
    s++;
  }
  str = s;
  while (*str) { // move str to null byte at the end
    str++;
  }
  str--;
  while (str > s && *str == ' ') {
    // keep taking spaces off the end until you arrive at a different character
    *str = 0;
    str--;
  }
  return s;
}
