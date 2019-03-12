#include <stdio.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';
const int NLADOS = 4;

typedef struct{
    int l;
    int c;
} Pos;

#define fill_neibs(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

void show(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
}

void tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(mat[l][c] != TREE)
        return;
    mat[l][c] = FIRE;
    Pos neibs[NLADOS] = fill_neibs(l, c);
    for(int i = 0; i < NLADOS; ++i)
        tocar_fogo(nl, nc, mat, neibs[i].l, neibs[i].c);
}

int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc];
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            scanf(" %c", &mat[l][c]);
    tocar_fogo(nl, nc, mat, l, c);
    show(nl, nc, mat);

}
