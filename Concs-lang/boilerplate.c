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
    if(array->length >= array->cap){
        Elt* temp = (Elt*) malloc(sizeof(Elt) * array->cap*2);
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

size_t get(const Array* array, size_t index){ // needs perf?
    size_t out = 0;
    for(size_t i = 0; i < array->length && out < 1; i ++)
        out = i * (array->array[i].index == index);
    return out;
}


Array data;

int main(void){
    Array array = {0, 1, (Elt*) malloc(sizeof(Elt))};

    add(&array, (Elt) {100, 10});
    add(&array, (Elt) {200, 20});
    add(&array, (Elt) {300, 30});
    add(&array, (Elt) {400, 40});

    printf("len: %llu, cap: %llu\n\n", array.length, array.cap);
    for(int i = 0; i < array.length; i ++){
        printf("[%ld] = %ld\n", array.array[i].index, array.array[i].value);
    }
    

    return 0;
}