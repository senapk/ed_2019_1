#include <iostream>

struct Node{
    int value;
    Node * prev;
    Node * next;
    Node(int value = 0, Node * prev = nullptr, Node * next = nullptr){
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
};

struct Lista{
    Node * head;
    Node * tail;
    Lista(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void push_back(int value){
        insert(tail, value);
    }

    void insert(Node * ref, int value){
        if(ref == head)
            return;
        Node * node = new Node(value);
        node->next = ref;
        node->prev = ref->prev;
        ref->prev = node;
        node->prev->next = node; 
    }

    void remove(Node * node){
        if(node == head || node == tail)
            return;
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void show(Node * espada = nullptr){
        std::cout << "[ ";
        Node * node = head->next;
        while(node != tail){
            std::cout << node->value;
            if(node == espada)
                std::cout << ">";
            std::cout << " ";
        }
        std::cout << "]\n";
    }

    Node * next(Node * node){
        if(node->next == tail)
            return head->next;
        return node->next;
    }
};


int main(){
    Lista lista;
    lista.show();

    for(int i = 1; i < 10; i++)
        lista.push_back(i);
    lista.show();
    Node * node = lista.head->next;
    while(node->next{
        remove_right(lista);
        lista = lista->next;
        show_ord(lista);
    }
    show(lista);
}