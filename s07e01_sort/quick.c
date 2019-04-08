#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SUAPI(a, b, tipo) do{tipo SUAPI = a; a = b; b = SUAPI;}while(0)

void quick_sort(int vet[], int A, int B){
    if(B <= A)
        return;
    int pivo = vet[A];
    int i = A + 1;
    int j = B;
    while(i <= j){
        while((vet[i] < pivo) && (i <= j))
            i++;
        while((vet[j] > pivo) && (j >= i))
            j--;
        if(i <= j){
            SUAPI(vet[i], vet[j], int);
            i++;
            j--;
        }
    }
    SUAPI(vet[A], vet[j], int);
    quick_sort(vet, A, j - 1);
    quick_sort(vet, j + 1, B);
}

bool verify(int * vet, int size){
    int i = 0;
    for(i = 0;i < size - 1; i++){  
        if(vet[i] > vet[i + 1])
            return false;
    }
    return true;
}

void show_vet(int vet[], int size){
    printf("[ ");
    for(int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}

int main(){
    for(int k = 1; k < 10000; k++){
        srand(k);
        int size = 40;
        int vet[size];
        for(int i = 0; i < size; i++)
            vet[i] = rand();
        quick_sort(vet, 0, size - 1);
        //show_vet(vet, size);
        if(!verify(vet, size))
            printf("%d", k);
    }
}