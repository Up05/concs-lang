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
    Elt* buffer;
} Array;

Array data;

void set(int32_t index, int32_t value){

    for(int i = 0; i < data.length; i ++)
        if(data.buffer[i].index == index){
            data.buffer[i].value = value;
            break;
        }

    if(data.length >= data.cap){
        Elt* temp = (Elt*) malloc(sizeof(Elt) * data.cap*2);
        if(!temp) {
            puts("Program ran out of memory!");   
            exit(-1);
        }
        data.cap *= 2;
        memcpy (
            temp, data.buffer, 
            data.length * sizeof(Elt)
        );

        free(data.buffer);

        data.buffer = temp;
    }

    data.buffer[data.length].index = index;
    data.buffer[data.length].value = value;
    data.length ++;
}

int32_t get(size_t index){
    for(size_t i = 0; i < data.length; i ++){
        if(data.buffer[i].index == index){
            return data.buffer[i].value;
        }
    }
    return -1;
}


void print(int32_t value){ // TODO: PERFORMANCE!
    
    printf("%d", value);
}



