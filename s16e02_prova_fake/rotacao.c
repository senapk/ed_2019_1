#include <stdio.h>

int main(){
    int size, nrot;
    scanf("%d %d", &size, &nrot);
    int vet[size];
    for(int i = 0; i < size; i++)
        scanf("%d", &vet[i]);
    int aux[size];
    nrot %= size;
    int ind = size - nrot;
    int j = 0;
    for(int i = ind; i < size; i++, j++)
        aux[j] = vet[i];
    for(int i = 0; i < ind; i++, j++)
        aux[j] = vet[i];
    for(int i = 0; i < size; i++)
        printf("%d ", aux[i]);
    puts("");
}