/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define init_capac 3

void push(int *arr, int index, int value, int *size, int *capacity){
     if(*size > *capacity){
          realloc(arr, sizeof(arr) * 2);
          *capacity = sizeof(arr) * 2;
     }

     arr[index] = value;
     *size = *size + 1;
}

int main(){
    //capacity = 0 to 3, i.e 4 elements
    //initialized size at 0
    int size = 0;
    int capacity = init_capac;
    int* arr = malloc(init_capac * sizeof(int));
    
    push(arr,0,1,&size,&capacity);
    //first element
    printf("first element:  %d\n",arr[0]);
    //second element
    push(arr,1,2,&size,&capacity);
    printf("Second element: %d\n",arr[1]);

    push(arr,2,3,&size,&capacity);
    printf("third element: %d\n",arr[2]);
    push(arr,3,4,&size,&capacity);
    
    printf("Current capacity: %d\n", capacity);
    push(arr,4,5,&size,&capacity);
    push(arr,5,6,&size,&capacity);

    printf("Current capacity: %d\n", capacity);
   // printf
    return 0;
    
}
