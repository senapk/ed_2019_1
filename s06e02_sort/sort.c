#include "xpaint.h"
#include "xvet.h"

#define SUAPI(a, b, tipo) do{tipo SUAPI = a; a = b; b = SUAPI;}while(0)

//find indice de menor na particao [inicio, fim[
int find_ind_menor(int vet[], int size, int ini, int fim){
    int imenor = ini;
    for(int i = ini + 1; i < fim; i++){
        if(vet[i] < vet[imenor])
            imenor = i;
        xd_vet(vet, size, "gr", i, imenor);
    }
    return imenor;
}

void selection(int vet[], int size){
    for(int i = 0; i < size; i++){
        xs_partition(i, size - 1);
        int imenor = find_ind_menor(vet, size, i, size);
        xd_vet(vet, size, "ry", imenor, i);
        SUAPI(vet[i], vet[imenor], int);
        xd_vet(vet, size, "ry", imenor, i);
    }
}

void selection_maior(int vet[], int size){
    for(int i = size - 1; i > -1; i -= 1){
        int imaior = i;
        for(int j = 0; j < i; j++){
            if(vet[j] > vet[imaior])
                imaior = j;
            xd_vet(vet, size, "ryg", imaior, i, j);
        }
        SUAPI(vet[imaior], vet[i], int);
        xd_vet(vet, size, "ry", imaior, i);
    }
}

int main(){
    x_open(800, 500);
    xs_log("imagens/");
    int size = 40;
    int vet[size];
    srand(1);
    for(int i = 0; i < size; i++)
        vet[i] = rand() % 191 + 10;
    xd_vet(vet, size, "");
    selection_maior(vet, size);
    xd_vet(vet, size, "");
    x_close();
}