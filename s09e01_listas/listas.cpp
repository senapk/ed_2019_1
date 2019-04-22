#include <iostream>
using namespace std;


struct Node{
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct It{
    Node * node;
    int operator*(){
        return node->value;
    }
    void setValue(int value){
        node->value = value;
    }
    void operator++(){
        node = node->next;
    }
    It(Node * node){
        this->node = node;
    }
    bool operator != (It it){
        return it.node != this->node; 
    }

};

#include <sstream> //stringstream

struct List{
    Node * head;
    List(){
        this->head = nullptr;
    }

    It begin(){
        return It(head);
    }

    It end(){
        return It(nullptr);
    }

    void insert(Node ** elo, int value){
        Node * node = *elo;
        if(node == nullptr || node->value > value){
            *elo = new Node(value, node);
            return;
        }
        insert(&node->next, value);
    }

    void print(){
        cout << "[ ";
        Node * node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << " ]\n";
    }

    string serialize(){
        stringstream ss;
        Node * node = head;
        while(node != nullptr){
            ss << node->value << " ";
            node = node->next;
        }
        string serial = ss.str();
        if(serial.size() > 0)
            serial.pop_back();
        return serial;
    }





    void clone(Node * node, Node ** elo){
        if(node == nullptr)
            return;
        *elo = new Node(node->value);
        clone(node->next, &(*elo)->next);

    }

    Node * clone(stringstream& ss){
        int value;
        if(ss >> value){
            Node * node = new Node(value);
            node->next = clone(ss);
            return node;
        }
        return nullptr;
    }

    List(string serial){
        stringstream ss(serial);
        this->head = clone(ss);
    }
};
#include <cstdlib>

int main(){
    List lista;
    for(int i = 0; i < 10; i++)
        lista.insert(&lista.head, rand() % 30);

    for(It it = lista.begin(); it != lista.end(); ++it){
        cout << *it << " ";
    }

/* 
    List l2(lista.serialize());
    cout << "[" << l2.serialize() << "]\n"; 
*/
}