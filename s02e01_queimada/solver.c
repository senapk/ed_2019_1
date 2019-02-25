#include <stdio.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.';

void show(int nl, int nc, char mat[nl][nc + 2]){
    for(int i = 0; i < nl; i++)
        printf("%s", mat[i]);
}

void tocar_fogo(int nl, int nc, char mat[nl][nc + 2], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(mat[l][c] != TREE)
        return;
    mat[l][c] = FIRE;
    tocar_fogo(nl, nc, mat, l, c + 1);
    tocar_fogo(nl, nc, mat, l, c - 1);
    tocar_fogo(nl, nc, mat, l - 1, c);
    tocar_fogo(nl, nc, mat, l + 1, c);

}

int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc + 2];
    for(int i = 0; i < nl; i++)
        fgets(mat[i], sizeof(mat[i]), stdin);
    
    tocar_fogo(nl, nc, mat, l, c);
    show(nl, nc, mat);
}
