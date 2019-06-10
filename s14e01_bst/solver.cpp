
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root;
    BTree(){
        this->root = nullptr;
    }

    BTree(string serial){
        //fazer construtor
    }

    void _destroy(Node * node){
        if(node == nullptr)
            return;
        _destroy(node->left);
        _destroy(node->right);
        delete node;
    }

    ~BTree(){
        _destroy(this->root);
    }
    
    void show(){
        //fazer
    }
};




int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show();
}