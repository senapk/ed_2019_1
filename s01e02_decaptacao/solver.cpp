#include <list>
#include <cstdio>
using namespace std;
const int MORTO = 0;

list<int>::iterator proximo(list<int>& vivos, list<int>::iterator it){
    it++;
    if(it == vivos.end())
        return vivos.begin();
    return it;
}

void mostrar_lista(list<int>& list){
    printf("[");
    bool primeiro = true;
    for(auto elem : list){
        if(primeiro)
            primeiro = false;
        else
            printf(" ");
        printf("%d", elem);
    }
    printf("]\n");
}

int main(){
    int size = 0;
    scanf("%d", &size);
    list<int> vivos;
    for(int i = 1; i <= size; i++)
        vivos.push_back(i);

    int esc = 0; //o escolhido
    scanf("%d", &esc);
    mostrar_lista(vivos);

    auto it = vivos.begin();
    while(*it != esc)
        it++;

    while(vivos.size() > 1){
        auto vai_morrer = proximo(vivos, it);
        it = vivos.erase(vai_morrer);
        if(it == vivos.end())
            it = vivos.begin();
        mostrar_lista(vivos);
    }
}