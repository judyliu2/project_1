#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args(char * s1){
	char ** ret = (char **) calloc (10, sizeof(char*));
	int i = 0;    

	while (s1 && i < 9){
	  char * string = strsep (&s1," ");
	  ret[i] = string;
	  i++;
	}
	ret[i] = NULL;
	return ret;
}

char ** parse_argC(char * s1){
	char ** ret = (char **) calloc (10, sizeof(char*));
	int i = 0;

	while (s1 && i < 9){
	  char * string = strsep (&s1,";");
	  ret[i] = string;
	  i++;
	}
	ret[i] = NULL;
	return ret;
}

// Precondition: s must be null-terminating.
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
