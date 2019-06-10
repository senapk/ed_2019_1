
#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node * father;
    bool isDummy;
    
    Node(int value = 0, Node * father = nullptr, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
        this->father = father;
        this->isDummy = true;
    }
};

struct BSTree{
    Node * root;
    BSTree(){
        this->root = new Node();
        root->left = new Node(0, root);
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

    void remove(Node * node){
        if(node->isDummy)
            return;
        else if(node->left->isDummy && node->right->isDummy){
            node->isDummy = true;
            delete(node->left);
            delete(node->right);
            node->left = nullptr;
            node->right = nullptr;
            return;
        }
        if(node->right->isDummy){ //only left
            delete(node->right);
            if(node->father->left == node)
                node->father->left = node->left;
            else
                node->father->right = node->left;
            node->left->father = node->father;
            delete(node);
            return;
        }
        if(node->left->isDummy){ //only right
            delete(node->left);
            if(node->father->left == node)
                node->father->left = node->right;
            else
                node->father->right = node->right;
            node->right->father = node->father;
            delete(node);
            return;
        }
        Node * suc = node->right;
        while(!suc->left->isDummy)
            suc = suc->left;
        node->value = suc->value;
        remove(suc);
    }

    void remove(int value){
        remove(smart_find(this->root->left, value));
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

    bool equals(BSTree other){
        return equals(root, other.root);
    }

    void _serialize(stringstream& ss, Node * node){
        if(node->isDummy)
            ss << "# ";
        else{
            ss << node->value << " ";
            _serialize(ss, node->left);
            _serialize(ss, node->right);
        }
    }

    string serialize(){
        stringstream ss;
        _serialize(ss, this->root->left);
        return ss.str();
    }

    Node * smart_find(Node * node, int value){
        if(node->isDummy || node->value == value)
            return node;
        if (value < node->value)
            return smart_find(node->left, value);
        else
            return smart_find(node->right, value);
    }

    bool find(int value){
        Node * node = smart_find(root->left, value);
        return (!node->isDummy);
    }

    void insert(int value){
        Node * node = smart_find(root->left, value);
        if(node->isDummy){
            node->isDummy = false;
            node->value = value;
            node->left = new Node(0, node);
            node->right = new Node(0, node);
        }
    }

    void bshow(Node * node, string hist, ostream & fout){
        bool kids = !node->isDummy && (!node->left->isDummy || !node->right->isDummy);
        if(kids) bshow(node->left , hist + "l", fout);
        for(int i = 0; i < (int) hist.size() - 1; i++)
            fout << (hist[i] != hist[i + 1] ? "│   " : "    ");
        fout << (hist == "" ? "" : (hist.back() == 'l' ? "┌───" : "└───"));
        fout << (node->isDummy ? "#" :  to_string(node->value)) << endl;
        if(kids) bshow(node->right, hist + "r", fout);
    }

    void bshow(){
        bshow(this->root->left, "", cout);
    }
};

int main(){
    BSTree bt;
    string line, cmd;
    int value;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        cout << line << endl;
        ss >> cmd;
        if(line == "" || line[0] == '#')
            continue;
        if(cmd == "$end"){
            break;
        }else if(cmd == "$add"){
            while(ss >> value)
                bt.insert(value);
        }else if(cmd == "$rm"){
            while(ss >> value)
                bt.remove(value);
        }else if(cmd == "$show"){
            bt.bshow();
        }else if(cmd == "$find"){
            ss >> value;
            cout << (bt.find(value) ? "Found\n" : "Not found\n");
        }else if(cmd == "$serial"){
            cout << bt.serialize() << endl;
        }else{
            cout << "fail: invalid command\n"; 
        }

    }
}