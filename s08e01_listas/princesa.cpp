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

    while(lista.front() != esc){
        lista.push_back(lista.front());
        lista.pop_front();
    }

    while(lista.size() > 1){
        lista.push_back(lista.front());
        lista.pop_front();
        lista.pop_front();
    }
    
    cout << lista.front() << endl;
    
}