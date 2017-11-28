#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args(char * s1){
	char ** ret = (char **) calloc (10, sizeof(char*));
	int i = 0;    

	while (s1){
	  char * string = strsep (&s1," ");
	  ret[i] = string;
	  i++;
	}
	return ret;
}

char ** parse_argC(char * s1){
	char ** ret = (char **) calloc (10, sizeof(char*));
	int i = 0;

	while (s1){
	  char * string = strsep (&s1,";");
	  ret[i] = string;
	  i++;
	}
	return ret;
}
