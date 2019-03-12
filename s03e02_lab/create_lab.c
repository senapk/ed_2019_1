#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct _Pos{
    int l;
    int c;
} Pos;

#define get_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

/* typedef struct{
    Pos vet[4];
} Neibs;

Neibs fill_neibs(int l, int c){
    Neibs neibs = {{{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}};
    return neibs;
} */

void shuffle(Pos vet[], int size){
    for(int i = 0; i < size; i++){
        int pos = rand() % size;
        Pos aux = vet[i];
        vet[i] = vet[pos];
        vet[pos] = aux;
    }
}

bool equals(int nl, int nc, char mat[nl][nc], int l, int c, char value){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return false;
    return mat[l][c] == value;
}

bool eh_furavel(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!equals(nl, nc, mat, l, c, '#'))
        return false;
    int cont = 0;
    Pos neibs[] = get_neibs(l, c);
    for(int i = 0; i < 4; i++)
        if(equals(nl, nc, mat, neibs[i].l, neibs[i].c, '#'))
            cont++;
    if(cont < 3)
        return false;
    return true;
}

void furar(int nl, int nc, char mat[nl][nc], int l, int c){
    if(!eh_furavel(nl, nc, mat, l, c))
        return;
    mat[l][c] = ' ';
    Pos neibs[] = get_neibs(l, c);
    shuffle(neibs, 4);
    for(int i = 0; i < 4; i++)
        furar(nl, nc, mat, neibs[i].l, neibs[i].c);    
}

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
        //    if(mat[l][c] == '#')
        //         printf("█");
        //    else
                printf("%c", mat[l][c]);
        }
        puts("");
    }
}

bool procurar_saida(nl, nc, mat, mvis, l, c, lsaida, csaida){
    se nao for ' '
        retorne
    se ja foi visitado
        retorne
    marco como visitado
    poe '.'
    se sou saida
        return true
    para cada vizinho
        procurar_saida(viz)
    se alguem retornar verdadeiro
        return true
    else
        retiro '.'
        return false
}

int main(int argc, char * argv[]){
    srand(time(NULL));
    int nl = 10;
    int nc = 30;

    if(argc > 2){
        nl = atoi(argv[1]);
        nc = atoi(argv[2]);
    }

    char mat[nl][nc];
    mat  vis[nl][nc] false;
    char * p = &mat[0][0];
    for(int i = 0; i < nl * nc; i++)
        p[i] = '#';
    furar(nl, nc, mat, 1, 1);
    printf("%d %d\n", nl, nc);
    show(nl, nc, mat);
}
