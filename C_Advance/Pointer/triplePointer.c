#include<stdio.h>
#include<stdlib.h>

void triplePointer(int *ptrConstant);

int main(int argc, char *argv[]){
     int constant = 5;
     triplePointer(&constant);
     printf("Constant: %d\n",constant);
    return 0;
}

void triplePointer(int *ptrConstant){
    *ptrConstant *= 3;
}