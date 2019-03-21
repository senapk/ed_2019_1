#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * data;
    int size;
    int capacity;
} Vector;

Vector * vector_create(int cap){
    Vector * vec = (Vector*) malloc(sizeof(Vector));
    vec->size = 0;
    vec->capacity = cap;
    vec->data = (int*) malloc(cap * sizeof(int));
    return vec;
}

void vector_destroy(Vector * vec){
    free(vec->data);
    free(vec);
}


void vector_resize(Vector * vec, int new_capacity){
    vec->data = (int*) realloc(vec->data, new_capacity * sizeof(int));
    vec->capacity = new_capacity;
    if(new_capacity < vec->size)
        vec->size = new_capacity;
}

void vector_push_back(Vector * vec, int value){
    if(vec->size == vec->capacity)
        vector_resize(vec, vec->capacity * 2);
    vec->data[vec->size] = value;
    vec->size += 1;
}

void vector_pop_back(Vector * vec){
    if(vec->size > 0)
        return;
    vec->size -= 1;
}

void vector_show(Vector * vector){
    printf("[ ");
    for(int i = 0; i < vector->size; i++){
        printf("%d ", vector->data[i]);
    }
    printf("] %d/%d\n", vector->size, vector->capacity);
}


int main(){
    Vector * vec = vector_create(1);
    vector_show(vec);
    vector_push_back(vec, 4);
    vector_show(vec);
    vector_push_back(vec, 6);
    vector_show(vec);
    vector_push_back(vec, 2);
    vector_show(vec);
    vector_push_back(vec, 1);
    vector_show(vec);
    vector_push_back(vec, 8);
    vector_show(vec);
    vector_destroy(vec);
}