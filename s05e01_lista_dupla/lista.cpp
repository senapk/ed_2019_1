#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node * prev;
    Node(int value = 0, Node * next = nullptr, Node * prev = nullptr){
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
};

struct Lista{
    Node * head;
    Node * tail;
    //Node * ref;

    Lista(){
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    void show(){
        cout << "[ ";
        Node * node = head->next;
        while(node != tail){
            cout << node->value << " ";
            node = node->next;
        }
        cout << "]\n";
    }

    void push_back(int value){
        insert(tail, value);
    }

    void pop_back(){
        if(head->next == tail)
            return;
        remove(tail->prev);
    }

    void pop_front(){
        if(head->next == tail)
            return;
        remove(head->next);
    }

    void push_front(int value){
        insert(head->next, value);
    }

    void insert(Node * ref, int value){
        Node * node = new Node(value, ref, ref->prev);
        ref->prev = node;
        node->prev->next = node;
    }

    void remove(Node * ref){
        ref->prev->next = ref->next;
        ref->next->prev = ref->prev;
        delete ref;
    }
};

int main(){
    Lista lista;
    while(true){
        string line;
        getline(cin, line);
        stringstream ui(line);
        string cmd;
        ui >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "show"){
            lista.show();
        }else if(cmd == "pb"){
            int value;
            while(ui >> value){
                lista.push_back(value);
            }
        }else if(cmd == "pf"){
            int value;
            while(ui >> value){
                lista.push_front(value);
            }
        }else if(cmd == "popf"){
            lista.pop_front();
        }else if(cmd == "popb"){
            lista.pop_back();
        }else{
            cout << "fail: comando invalido\n";
        }
    }

}

