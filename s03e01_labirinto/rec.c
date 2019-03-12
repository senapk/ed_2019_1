#include <stdio.h>

int somar(int vet[], int size){
    if(size == 0)
        return 0;
    return vet[size - 1] + somar(vet, size - 1);
}

void show(int vet[], int size){
    if(size == 0)
        return;
    printf("%d ", vet[0]);
    show(vet + 1, size - 1);
}

int min(int vet[], int size){
    if(size == 1)
        return vet[0];
    int resto = min(vet + 1, size - 1);
    if(vet[0] < resto)
        return vet[0];
    return resto; 
}

void inverter(int vet[], int size){
    if(size < 2)
        return;
    int c = vet[0];
    vet[0] = vet[size - 1];
    vet[size - 1] = c;
    inverter(vet + 1, size - 2);
}



int main(){
    int vet[] = {1, 2, 3, 4, 2, 3, 4, 0, 6};
    int size = sizeof(vet)/sizeof(int);

    int soma = 0;
    for(int i = 0; i < size; i++)
        soma += vet[i];
    printf("[ ");
    show(vet, size);
    printf("]\n");    
    inverter(vet, size);
    printf("[ ");
    show(vet, size);
    printf("]\n");    
}
