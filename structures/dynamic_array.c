#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

int main()
{
    
    Array a;
    int i;

    initArray(&a, 1);  // initially 0 elements
    printf("%d\n",sizeof(a));
    //for (i = 0; i < 500; i++)
        insertArray(&a, 1); 
        insertArray(&a,20);
        insertArray(&a,30);

        // automatically resizes as necessary
        //printf("%d\n", a.array[19]);  // print 10th element
    printf("%d\n", a.used);  // print number of elements
    freeArray(&a);
    
}
