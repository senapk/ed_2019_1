#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void spam(vector<string>&mat, vector<vector<int>>& visit, int l, int c, char base){
    int nl = (int) mat.size();
    int nc = (int) mat[0].size();
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return;
    if(visit[l][c] == true)
        return;
    if(mat[l][c] != base)
        return;
    visit[l][c] = true;
    spam(mat, visit, l, c - 1, base);
    spam(mat, visit, l, c + 1, base);
    spam(mat, visit, l - 1, c, base);
    spam(mat, visit, l + 1, c, base);
}

bool has_new_partition(vector<string>&mat, vector<vector<int>>& visit, int l, int c){
    if(visit[l][c] == true)
        return false;
    spam(mat, visit, l, c, mat[l][c]);
    return true;
}

int main(){
    int nl, nc;
    string line;
    getline(cin, line);
    stringstream(line) >> nl >> nc;
    vector<string> mat(nl, "");
    for(int i = 0; i < nl; i++)
        getline(cin, mat[i]);
    vector<vector<int>> visit(nl, vector<int>(nc, false));
    int cont = 0;
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            if(has_new_partition(mat, visit, l, c))
                cont++;
    }
    cout << cont << endl;
}