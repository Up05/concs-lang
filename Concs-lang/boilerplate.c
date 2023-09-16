#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <stdlib.h>

typedef struct {
    int32_t value,
            index;
} Elt;

typedef struct {
    size_t length, 
           cap;
    Elt* array;
} Array;

void add(Array* array, Elt number){

    for(int i = 0; i < array->length; i ++)
        if(array->array[i].index == number.index){
            array->array[i].value = number.value;
            break;
        }

    if(array->length >= array->cap){
        Elt* temp = (Elt*) malloc(sizeof(Elt) * array->cap*2);
        if(!temp) {
            puts("Program ran out of memory!");   
            exit(-1);
        }
        array->cap *= 2;
        memcpy (
            temp, array->array, 
            array->length * sizeof(Elt)
        );

        free(array->array);

        array->array = temp;
    }

    array->array[array->length] = number;
    array->length ++;
}

int32_t get(const Array* array, size_t index){ // needs perf?
    int32_t out = -1;
    for(size_t i = 0; i < array->length; i ++){
        out = i * (array->array[i].index == index);
        if(out >= 1) break; 
    }
    return out;
}


Array data;


