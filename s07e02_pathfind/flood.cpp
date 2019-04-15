#include "xpaint.h"
#include "xmat.h"
#include <vector>
#include <list>
#include <iostream>
using namespace std;

extern "C" void x_close();
extern "C" void x_save(const char *);
extern "C" void xmat_init(int, int);
extern "C" void xmat_draw(int nl, int nc, char * mat);


void mat_show(vector<string>& mat){
    char cmat[mat.size()][mat[0].size()];
    for(int l = 0; l < mat.size(); l++){
        for(int c = 0; c < mat[0].size(); c++){
            mat[l][c] = mat[l][c];
        }
    }
    xmat_draw(mat.size(), mat[0].size(), cmat);
}


struct Pos{
    int l, c;
    Pos(int l, int c): //lista de inicializacao
        l(l), c(c){
    }
};

vector<Pos> get_neibs(int l, int c){
    return vector<Pos> {Pos(l, c - 1), Pos(l - 1, c), Pos(l, c + 1), Pos(l + 1, c)};
}
 
bool has_value(vector<string> &mat, int l, int c, char value){
    if(l < 0 || l >= mat.size())
        return false;
    if(c < 0 || c >= mat[0].size())
        return false;
    return mat[l][c] == value;
}

void pintar(vector<string> &mat,int l, int c, char cor_base, char cor_final){
    if(!has_value(mat, l, c, cor_base))
        return;
    mat[l][c] = cor_final;
    mat_show(mat);
    x_step("mat");
    for(auto viz : get_neibs(l, c)){
        pintar(mat, viz.l, viz.c, cor_base, cor_final);
    }
}


int main(){
    int nl = 20, nc = 20;
    xmat_init(nl, nc);
    vector<string> mat(nl, string(nc, ' '));
    const char * color = "rgb";
    for(int l = 0; l < mat.size(); l++){
        for(int c = 0; c < mat[0].size(); c++){
            mat[l][c] = color[xm_rand(0, 2)]; 
        }
    }
    mat_show(mat);
    x_save("mat");
    int l = 0, c = 0;
    puts("Digite o ponto de inicio l e c");
    scanf("%d %d", &l, &c);

    pintar(mat, l, c, mat[l][c], 'y');
    x_save("mat");
    x_close();
}