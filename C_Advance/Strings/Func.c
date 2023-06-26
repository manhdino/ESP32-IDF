#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char* argv[]) {
    char string[] = "Hello World";
    long len = strlen(string);
    printf("String %s has length %d\n", string, len);


    /*
     char* strcpy(char* copyString, const char* stringCopy);
    */
    return 0;
}
