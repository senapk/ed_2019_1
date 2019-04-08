#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../s06e02_sort/xpaint.h"
#include "../s06e02_sort/xvet.h"
#define SUAPI(a, b, tipo) do{tipo SUAPI = a; a = b; b = SUAPI;}while(0)

void quick_sort(int vet[], int A, int B){
    if(B <= A)
        return;
    int meio = (A + B) / 2;
    SUAPI(vet[A], vet[meio], int);
    int pivo = vet[A];
    int i = A + 1;
    int j = B;
    while(1){
        while((vet[i] < pivo) && (i <= B))
            i++;
        while((vet[j] > pivo) && (j >= A))
            j--;
        if(i > j)
            break;
        SUAPI(vet[i], vet[j], int);
        i++;
        j--;
    }
    SUAPI(vet[A], vet[j], int);
    quick_sort(vet, A, j - 1);
    quick_sort(vet, j + 1, B);
}


void verify(int * vet, int size){
    int i = 0;
    for(i = 0;i < size - 1; i++){  
        if(vet[i] > vet[i + 1])
            return false;
    }
    return true;
}

/* 

//merge_sort(vet, 0, size)
//ordenar a lista entre [A, B[

void merge(int vet[], int A, int m, int B){
    int * vaux = (int*) malloc(sizeof(int) * (B - A));
    int i = 0, a = A, b = m;
    while((a < m) && (b < B)){
        if(vet[a] < vet[b]){
            vaux[i++] = vet[a++];
        }else{
            vaux[i++] = vet[b++];
        }
    }
    while(a < m)
        vaux[i++] = vet[a++];
    while(b < B)
        vaux[i++] = vet[b++];
    for(int j = 0; j < (B - A); j++)
        vet[A + j] = vaux[j];
    free(vaux);
}

void merge_sort(int vet[], int A, int B){
    if(B - A <= 1)
        return;
    int meio = (A + B) / 2;
    xs_partition(A, B);
    xd_vet(vet, size, "rgb", A, meio, B);
    merge_sort(vet, A, meio);
    merge_sort(vet, meio, B);
    merge(vet, A, meio, B);
    xd_vet(vet, size, "rgb", A, meio, B);
    
}

void insertion_sort(int vet[], int size){
    for(int i = 0; i < size; i++){//vou inserir i na lista ordenada
        for(int j = i; j > 0; j--)
            if(vet[j] < vet[j - 1])
                SUAPI(vet[j], vet[j - 1], int);
    }
}

void bolha_sorte(int vet[], int size){
    for(int i = 0; i < size - 1; i++){ //onde quero posicionar o elemento
        for(int j = size - 1; j > i; j--){//volta trazendo o menor
            if(vet[j] < vet[j - 1])
                SUAPI(vet[j], vet[j - 1], int);
        }
    }
}

//find indice de menor na particao [inicio, fim[
int find_ind_menor(int vet[], int ini, int fim){
    int imenor = ini;
    for(int i = ini + 1; i < fim; i++){ 
        if(vet[i] < vet[imenor])
            imenor = i;
    }
    return imenor;
}

void selection(int vet[], int size){
    for(int i = 0; i < size; i++){//onde eu quero posicionar
        int imenor = find_ind_menor(vet, i, size);
        SUAPI(vet[i], vet[imenor], int);
    }
}

void selection_maior(int vet[], int size){
    for(int i = size - 1; i > -1; i -= 1){
        int imaior = i;
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[imaior])
                imaior = j;
        }
        SUAPI(vet[imaior], vet[i], int);
    }
}
*/
void show_vet(int vet[], int size){
    printf("[ ");
    for(int i = 0; i < size; i++)
        printf("%d ", vet[i]);
    printf("]\n");
}

int main(){
    //x_open(800, 600);
    //srand((unsigned)time(NULL));
    srand(1);
    int vet[size];
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    quick_sort(vet, 0, size - 1);
    show_vet(vet, size);
    //x_close();

}