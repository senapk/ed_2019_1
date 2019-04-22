#include <iostream>
#include <list>
using namespace std;

int main(){
    int qtd = 0; 
    int esc = 0;
    cin >> qtd >> esc; 
    list<int> lista;
    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);

    auto it = lista.begin();
    std::advance(it, esc - 1);
    
    while(lista.size() > 1){
        it++;
        if(it == lista.end())
            it = lista.begin();
        it = lista.erase(it);
        if(it == lista.end())
            it = lista.begin();
    }
    
    cout << lista.front() << endl;
    
}