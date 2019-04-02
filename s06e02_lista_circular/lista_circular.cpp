#include <iostream>

struct Node{
    int value;
    Node * prev;
    Node * next;
    Node(int value){
        this->value = value;
        this->prev = this;
        this->next = this;
    }
};

void insert_right(Node * ref, int value){
    Node * node = new Node(value);
    node->next = ref->next;
    node->prev = ref;
    ref->next = node;
    node->next->prev = node; 
}

void insert_left(Node * ref, int value){
    insert_right(ref->prev, value);
}

void remove(Node * node){
    node->next->prev = node->prev;
    node->prev->next = node->next;
}

void remove_left(Node * node){
    remove(node->prev);
}

void remove_right(Node * node){
    remove(node->next);
}

void show(Node * node, Node * espada = nullptr){
    std::cout << "[";
    if(node != nullptr){
        Node * aux = node;
        do{
            std::cout << " " << aux->value;
            if((espada != nullptr) && (aux == espada))
                std::cout << ">";
            aux = aux->next;
        }while(aux != node);
    }
    std::cout << " ]\n";
}

void show_ord(Node * node){
    Node * menor = node;
    Node * aux = node;
    do{
        if(aux->value < menor->value)
            menor = aux;
        aux = aux->next;
    }while(aux != node);
    show(menor, node);
}

int main(){
    Node * lista = nullptr;
    show(lista);
    lista = new Node(0);
    show(lista);

    for(int i = 1; i < 10; i++)
        insert_left(lista, i);
    show(lista, lista);
    while(lista->next != lista){
        remove_right(lista);
        lista = lista->next;
        show_ord(lista);
    }
    show(lista);
}