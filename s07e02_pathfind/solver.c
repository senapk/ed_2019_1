#include "xpaint.h"
#include "xmat.h"
#include <stdbool.h>

typedef struct{
    int l, c;
} Pos;

#define get_neib(l, c) {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}}

bool has_value(int nl, int nc, char mat[nl][nc], 
            int l, int c, char value){
    if(l < 0 || l >= nl)
        return false;
    if(c < 0 || c >= nc)
        return false;
    return mat[l][c] == value;
}

void pintar(int nl, int nc, char mat[nl][nc], 
            int l, int c, char cor_base, char cor_final){
    if(!has_value(nl, nc, mat, l, c, cor_base))
        return;
    mat[l][c] = cor_final;
    xmat_draw(nl, nc, mat);
    x_step("mat");
    Pos neibs[] = get_neib(l, c);
    for(int i = 0; i < 4; i++){
        pintar(nl, nc, mat, neibs[i].l, neibs[i].c, cor_base, cor_final);
    }
}


int main(){
    int nl = 20, nc = 20;
    xmat_init(nl, nc);
    xs_jump(0);
    char mat[nl][nc];
    char *p = &mat[0][0];
    const char * color = "rgb";
    for(int i = 0; i < nl * nc; i++)
        p[i] = color[xm_rand(0, 2)]; 
    xmat_draw(nl, nc, mat);
    x_save("mat");
    int l = 0, c = 0;
    puts("Digite o ponto de inicio l e c");
    scanf("%d %d", &l, &c);

    pintar(nl, nc, mat, l, c, mat[l][c], 'y');
    x_save("mat");
    x_close();
}