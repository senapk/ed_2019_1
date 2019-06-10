
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

struct BSTree{
    Node * root;
    BSTree(){
        this->root = nullptr;
    }

    void _destroy(Node * node){
        if(node == nullptr)
            return;
        _destroy(node->left);
        _destroy(node->right);
        delete node;
    }

    ~BSTree(){
        _destroy(this->root);
    }
    
    bool equals(Node * one, Node * two){
        if(one == nullptr && two == nullptr)
            return true;
        if(one != nullptr && two != nullptr){
            if(one->value == two->value)
                return equals(one->left, two->left) && equals(one->right, two->right);
        }
        return false;
    }

    void remove(Node ** elo){
        Node * node = *elo;
        if(node == nullptr)
            return;
        if(node->left == nullptr && node->right == nullptr){
            delete node;
            *elo = nullptr;
            return;
        }
        if(node->right == nullptr){
            *elo = node->left;
            delete node;
            return;
        }
        if(node->left = nullptr){
            *elo = node->right;
            delete node;
            return;
        }

        Node ** suc = &node->right;
        while((*suc)->left != nullptr)
            suc = &(*suc)->left;

        (*elo)->value = (*suc)->value;
        remove(suc);
    }

    void remove(int value){
        Node ** elo = smart_find(&root, value);
        remove(elo);
    }


    bool equals(BSTree other){
        return equals(root, other.root);
    }

    void _serialize(stringstream& ss, Node * node){
        if(node == nullptr)
            ss << "# ";
        else{
            ss << node->value << " ";
            _serialize(ss, node->left);
            _serialize(ss, node->right);
        }
    }

    string serialize(){
        stringstream ss;
        _serialize(ss, this->root);
        return ss.str();
    }

    Node ** smart_find(Node ** elo, int value){
        Node * node = *elo;
        if(node == nullptr || node->value == value)
            return elo;
        if (value < node->value)
            return smart_find(&node->left, value);
        else
            return smart_find(&node->right, value);
    }

    bool find(int value){
        Node ** elo = smart_find(&root, value);
        return ((*elo) != nullptr);
    }

    void insert(int value){
        Node ** elo = smart_find(&root, value);
        if(*elo == nullptr)
            *elo = new Node(value);
    }

    void _show(Node * node, int nivel){
        if(node == nullptr){
            cout << string(nivel, '.') << "#\n";
            return;
        }
        if(node->left != nullptr || node->right != nullptr)
            _show(node->left, nivel + 1);
        cout << string(nivel, '.') << node->value << "\n";
        if(node->left != nullptr || node->right != nullptr)
            _show(node->right, nivel + 1);
    }

    void show(){
        _show(this->root, 0);
    }


    void _bshow(Node * node, string heranca, ostream & fout){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            _bshow(node->left , heranca + "l", fout);
        int tam = heranca.size();
        for(int i = 0; i < tam - 1; i++){
            if(heranca[i] != heranca[i + 1])
                fout << "│" << "   ";
            else
                fout << " " << "   ";
        }
        if(heranca != ""){
            if(heranca.back() == 'l')
                fout << "┌───";
            else
                fout << "└───";
        }
        if(node == nullptr){
            fout << "#" << endl;
            return;
        }
        fout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            _bshow(node->right, heranca + "r", fout);
    }

    void bshow(){
        _bshow(this->root, "", cout);
    }
};




int main(){
    BSTree bt;
    string line, cmd;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value)
                bt.insert(value);
        }else if(cmd == "rm"){
            int value;
            ss >> value;
            bt.remove(value);
        }else if(cmd == "show"){
            bt.bshow();
        }else if(cmd == "find"){
            int value;
            ss >> value;
            cout << (bt.find(value) ? "Encontrei\n" : "Nao encontrei\n");
        }else{
            cout << "fail: comando invalido\n"; 
        }

    }
}