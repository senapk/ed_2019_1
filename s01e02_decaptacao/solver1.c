#include <stdio.h>
#include <stdbool.h>

const int MORTO = 0;

void mostrar_vetor(int vet[], int size){
    printf("[");
    bool eh_o_primeiro = true;
    for(int i = 0; i < size; i++){
        if(vet[i] != MORTO){
            if(eh_o_primeiro)
                eh_o_primeiro = false;
            else
                printf(" ");
            printf("%d", vet[i]);
        }
    }
    printf("]\n");
}

int main(){
    int size = 0;
    scanf("%d", &size);
    int vet[size];
    for(int i = 0; i < size; i++)
        vet[i] = i + 1;
    int esc = 0; //o escolhido
    scanf("%d", &esc);
    mostrar_vetor(vet, size);

}

/* leia n
criar um vetor de "pessoas" tamanho n
preenche o vetor "pessoas" com valores de 1 a n
leia e
mostra_vetor
enquanto qtd de vivos for maior que um:
    m = descobre o proximo vivo depois de 'e'
    vetor [m] = 0
    mostrar_vetor
    e = descobrir o proximo vivo a partir de 'm'

 */


