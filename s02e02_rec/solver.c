#include <stdio.h>
#include <stdlib.h> //srand, rand
#include <time.h> // time()

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const char BURN = 'x';

//left, up, right, down
int deltaL[] = {0, -1, 0, 1};
int deltaC[] = {-1, 0, 1, 0};
int lados = sizeof(deltaL)/sizeof(int); 

void shuffle(int vet[], int size){
    for(int i = 0; i < size; i++){
        int esc = rand() % size;
        int temp = vet[i];
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
    int neib[] = {0, 1, 2, 3};
    shuffle(neib, lados);
    for(int v = 0; v < lados; v++){
        int i = neib[v];
        cont += tocar_fogo(nl, nc, mat, l + deltaL[i], c + deltaC[i]);
    }
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
