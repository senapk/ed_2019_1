
#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

list<int>::iterator find(list<int> &lista, int value){
    for(auto it = lista.begin(); it != lista.end(); it++){
        if(*it == value)
            return it;
    }
    return lista.end();
}

list<int>::iterator next_circ(list<int>& lista, list<int>::iterator& it){
    if(std::next(it) == lista.end())
        return lista.begin();
    return std::next(it);
}


void exemplo_lista(){
    list<int> lista {3, 4, 5, 1, 1, 1, 1, 1, 2, 3, 5, 9};
    for(int elem : lista)
        cout << elem << " ";
    cout << "\n";
    //list<int>::iterator it = lista.begin();
    for(auto it = lista.begin(); it != lista.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";

    auto it = find(lista, 1);
    *it = 5000;

    auto it2 = std::find(lista.begin(), lista.end(), 9);
    *it2 = 900;

    for(auto it = lista.begin(); it != lista.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";

    auto it3 = std::find(lista.begin(), lista.end(), 1);
    it3 = lista.erase(it3);
}



int main(){
}