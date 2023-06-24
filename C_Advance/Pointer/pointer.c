#include <stdio.h>
#include <stdlib.h>

int main(){
    int tuoi = 10;
    printf("Address HEX of variable:  %p\n", &tuoi);
    printf("Address DEC of variable:  %d\n", &tuoi);
    int *pointerTuoi  = &tuoi;
    
    printf("Address HEX of pointerTuoi: %p\n", &pointerTuoi);
    printf("Value  of pointerTuoi: %d\n",pointerTuoi);
    printf("Value of tuoi which pointerTuoi points to: %d\n", *pointerTuoi);
    return 0;
}