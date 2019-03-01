#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h> // time()

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char BURN = 'x';
#define LADOS 4

typedef struct{
    int l;
    int c;
} Pos;

typedef struct{
    Pos vet[LADOS];
} Neibs; //empacota um vetor de vizinhos

Neibs get_neibs(int l, int c){ //preenche e retorna os vizinhos
    Neibs neibs = {{{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}};
    return neibs;
}

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int esc = rand() % size;
        Pos temp = vet[i];
        vet[i] = vet[esc];
        vet[esc] = temp;
    }
}

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
    getchar();
}

int tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0;
    if(mat[l][c] != TREE)
        return 0;
    mat[l][c] = FIRE;
    show(nl, nc, mat);
    int cont = 1;
    Neibs neibs = get_neibs(l, c); //obtem os vizinhos
    shuffle(neibs.vet, LADOS); //embaralha os vizinhos
    for(int i = 0; i < LADOS; i++)
        cont += tocar_fogo(nl, nc, mat, neibs.vet[i].l, neibs.vet[i].c);
    mat[l][c] = BURN;
    show(nl, nc, mat);
    return cont;
}

int main(){
    srand(time(NULL));
    int nl = 0;
    int nc = 0;
    puts("Digite dimensoes da matriz");
    scanf("%d %d", &nl, &nc);
    puts("Digite a porcentagem de arvores 0-100");
    int taxa = 0; //proporcao de arvores
    scanf("%d", &taxa);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(rand() % 101 <= taxa)
                mat[l][c] = TREE;
            else
                mat[l][c] = EMPTY;
        }
    }
    show(nl, nc, mat);
    puts("Onde queres incendiar?");
    int l = 0;
    int c = 0;
    scanf("%d %d", &l, &c);
    
    
    int total = tocar_fogo(nl, nc, mat, l, c);
    show(nl, nc, mat);
    printf("total do estrago: %d\n", total);
}
