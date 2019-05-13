#include <vector>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;
struct HashTable{
    vector<list<int>> vet;
    HashTable(int size):
        vet(size, list<int>()){
    }

    bool add(int value){
        int hash = value % vet.size();
        auto it = std::find(vet[hash].begin(), vet[hash].end(), value);
        if(it == vet[hash].end()){
            vet[hash].push_back(value);
            return true;
        }
        return false;
    }

    bool rm(int value){
        int hash = value % vet.size();
        auto it = std::find(vet[hash].begin(), vet[hash].end(), value);
        if(it != vet[hash].end()){
            vet[hash].erase(it);
            return true;
        }
        return false;
    }

    void show(){
        int ind = 0;
        for(auto& lista : vet){
            cout << ind << ": ";
            for(auto elem : lista)
                cout << elem << " ";
            ind++;
            cout << "\n";
        }
    }
};
#include <sstream>
int main(){
    HashTable ht(10);
    string cmd;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "add"){
            int value;
            while(ss >> value)
                ht.add(value);
        }else if(cmd == "rm"){
            int value;
            while(ss >> value)
                ht.rm(value);
        }else if(cmd == "show"){
            ht.show();
        }else{
            cout << "fail: comando invalido\n";
        }
        
    }
}