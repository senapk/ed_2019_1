#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

struct Pos{
    int l;
    int c;
    Pos(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

vector<Pos> get_neibs(int l, int c){
/*     vector<Pos> neibs = {Pos(l, c - 1), Pos(l - 1, c), 
                         Pos(l, c + 1), Pos(l + 1, c)};
    return neibs; */
    
    vector<Pos> neibs;
    neibs.push_back(Pos(l, c - 1));
    neibs.push_back(Pos(l - 1, c));
    neibs.push_back(Pos(l, c + 1));
    neibs.push_back(Pos(l + 1, c));
    return neibs;
}

vector<Pos> shuffle(vector<Pos> vet){
    random_shuffle(vet.begin(), vet.end());
    return vet;
}

bool has_value(vector<string> &mat, Pos pos, char value){
    if((pos.l < 0) || (pos.l >= (int) mat.size()))
        return false;
    if((pos.c < 0) || (pos.c >= (int) mat[0].size()))
        return false;
    return mat[pos.l][pos.c] == value;
}

void show(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
    getchar();
}

bool achar_saida(vector<string> &mat, Pos pos, Pos final){
        if(!has_value(mat, pos, '#'))
        return false;
    mat[pos.l][pos.c] = 'o';
    show(mat);
    if(pos.l == final.l && pos.c == final.c){
        mat[pos.l][pos.c] = '.';
        return true;
    }

    for(auto viz : shuffle(get_neibs(pos.l, pos.c)))
        if(achar_saida(mat, viz, final)){
            mat[pos.l][pos.c] = '.';
            show(mat);
            return true;
        }
    mat[pos.l][pos.c] = 'x';
    show(mat);
    return false;
}



int main(){
    //conteiner
    srand(time(NULL));
    
    int nl = 6;
    int nc = 10;
    int taxa = 80;
    vector<string> mat(nl, string(nc, '#'));
    for(int l = 0; l < (int) mat.size(); l++)
        for(int c = 0; c < (int) mat[0].size(); c++)
            if(rand() % 100 > taxa)
                mat[l][c] = ' ';

    show(mat);
    achar_saida(mat, Pos(0, 0), Pos(nl - 1, nc - 1));
}