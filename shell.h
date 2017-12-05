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
char ** parse_args(char*);

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
char ** parse_argC(char*);

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
char * trim(char *);
