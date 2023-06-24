#include<stdio.h>
#include<stdlib.h>

/* A function pointer is going store the memory address not data for a function(the first 
adress of the function)
  typedef function_pointer allow you to create another function pointer
  with different name 
*/

typedef int (*funcptr)(int,int);

int add(int a,int b){
  return a + b;
}


void function(int x){
    printf("x: %d\n",x);
}

int main(){
    /*
      return type: void
      parameter: int 
      function pointer name: function_pointer
    */
    void (*function_pointer)(int);
    function_pointer = &function;

    //using function_pointer to call function
    (*function_pointer)(4);

    //typedef function pointer
     funcptr addptr = add; 
     printf("Sum: %d",addptr(5,10));
    return 0;
}