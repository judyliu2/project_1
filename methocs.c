#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char ** parse_args(char * s1){
	char ** ret = (char **) calloc (6, sizeof(char*));
	int i = 0;
	for (;i<5;i++){
		ret[i] = strsep(&s1," "); 
	}
	return ret;
}
