#include <iostream>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

struct LC{
    int l, c;
    LC(int l, int c){
        this->l = l;
        this->c = c;
    }
};

vector<LC> get_neib(LC pos){
    int l = pos.l;
    int c = pos.c;
    return vector<LC> {LC(l, c - 1), LC(l - 1, c), LC(l, c + 1), LC(l + 1, c)};
}

list<LC> find_greater_partition(vector<string> & mat){
    list<LC> greater;
    int nl = mat.size();
    int nc = mat[0].size();
    vector<vector<bool>> visited(nl, vector<bool>(nc, false));
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++){
            if(!visited[l][c]){
                visited[l][c] = true;
                list<LC> partition;
                list<LC> fila;
                partition.push_back(LC(l, c));
                fila.push_back(LC(l, c));
                while(!fila.empty()){
                    auto top = fila.front();
                    fila.pop_front();
                    for(auto viz : get_neib(top)){
                        if((viz.l < 0) || (viz.l >= nl) || (viz.c < 0) || (viz.c >= nc))
                            continue;
                        if(visited[viz.l][viz.c])
                            continue;
                        if(mat[viz.l][viz.c] == mat[top.l][top.c]){
                            visited[viz.l][viz.c] = true;
                            partition.push_back(viz);
                            fila.push_back(viz);
                        }
                    }
                }
                if(partition.size() > greater.size())
                    greater = partition;
            }
        }
    }
    return greater;
}

int main(){
    int nl, nc;
    string line;
    getline(cin, line);
    stringstream(line) >> nl >> nc;
    vector<string> mat(nl, "");
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);
    auto partition = find_greater_partition(mat);
    for(auto lc : partition)
        mat[lc.l][lc.c] = '*';
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
}