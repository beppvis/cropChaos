#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"



int insertItem(Array* array,int item){
    array->items = reallocf(array->items,sizeof(int)*array->size+1);
    array->items[array->size] = item;
    array->size+=1;
    return 0;
}

int deleteItem(Array *array, int itemIndex){
    // 0 - n
    // slice 1 : 0 - i
    // slice 2 : (i+1) - n
    // n-(i+1)
    // total 10,5 : one slice must have 4, 5
    int* temp = malloc(sizeof(int)*array->size-1);

    memcpy(temp,
           array->items,
           sizeof(int)*(itemIndex)
           );
    memcpy(temp+itemIndex
           ,array->items+itemIndex+1,
           sizeof(int)*(array->size - itemIndex));
    free(array->items);
    array->items = temp;
    array->size -= 1;
    return 0;
}

