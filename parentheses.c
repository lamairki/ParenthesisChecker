#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int stringCheck(char *, int);

/* main function, drives the program, allocates memory for a string and 
 * calls the verification function on each string to ensure the 
 * parentheses are valid.
*/
int main(void) {
    char *s;
    int nread;
    size_t maxn = 10;

    s = (char *) malloc(sizeof(char)*maxn);

    while ((nread = getline(&s, &maxn, stdin)) != -1) {
        if (stringCheck(s, nread) == 1) {
            printf("VALID\n");
        }
        else {
            printf("NOT VALID\n");
        }
    }

    free(s);
    return 0;
}

/* stringCheck function, checks for ballanced parentheticals in a given string.
 * takes inputs of char *, pointing to the beginning character of a string, and 
 * int, representing the length of the string that is passed.
 * Returns the value of flag. flag is 1 if the string is valid and 0 if invalid.
*/
int stringCheck(char *a, int sLen){
   char *parenStack = (char*) malloc(sizeof(char)*sLen);
   int endChar = 0;
   int flag = 1;
   for(int i = 0; i < sLen; i++) {
       if (*(a+i) == '[' || *(a+i) == '{' || *(a+i) == '(') {
           parenStack[endChar] = *(a+i);
           endChar++;
       }
       else if (*(a+i) == ']' || *(a+i) == '}' || *(a+i) == ')') {
           if (*(a+i) == ']' && *(parenStack + endChar-1) == '[') {
               endChar--;
               parenStack[endChar] = '\0';
           }
           else if (*(a+i) == '}' && *(parenStack + endChar-1) == '{') {
               endChar--;
               parenStack[endChar] = '\0';
           }
           else if (*(a+i) == ')' && *(parenStack + endChar-1) == '(') {
               endChar--;
               parenStack[endChar] = '\0';
           }
           else {
               flag = 0;
           }
       }
   }
   if (*(parenStack) != '\0') {
       flag = 0;
   }

    free(parenStack);
    return flag;
}
