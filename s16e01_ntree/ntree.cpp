#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    vector<Node *> children;
    Node(int value){
        this->value = value;
    }
};

struct NTree{
    Node * root;
    NTree(){
        root = nullptr;
    }

    void destroy(Node * node){
        for(auto * kid : node->children)
            destroy(kid);
        delete node;
    }

    ~NTree(){
        if(root != nullptr)
            destroy(root);
    }

    void show(Node * node, int nivel = 0, int indice = 0, Node * ref = nullptr){
        char sep = ' ';
        if(node == ref)
            sep = '>';
        cout << sep << string(2 * nivel, sep) << indice << ":" << node->value << "\n";
        int ind = 0;
        for(Node * kid : node->children)
            show(kid, nivel + 1, ind++, ref);
    }

    void show(){
        if(root != nullptr)
            show(root);
    }
    void serialize(stringstream &ss, Node * node){
        ss << node->value << " ";
        for(Node * kid : node->children)
            serialize(ss, kid);
        ss << "# ";
    }
    string serialize(){
        stringstream ss;
        serialize(ss, root);
        return ss.str();
    }

    Node * copy(stringstream &ss){
        string data;
        ss >> data;
        if(data == "#")
            return nullptr;
        int value;
        stringstream(data) >> value;
        Node * node = new Node(value);
        Node * kid;
        while((kid = copy(ss))!= nullptr)
            node->children.push_back(kid);
        return node;
    }

    NTree(string serial){
        stringstream ss(serial);
        this->root = copy(ss);
    }

    void menu(Node * node){
        cout << "ins _value; rem _ind; go _ind; back; show\n";
        while(true){
            string op;
            cin >> op;
            if(op == "ins"){
                int value;
                cin >> value;
                node->children.push_back(new Node(value));
            }else if(op == "rem"){
                int ind;
                cin >> ind;
                destroy(node->children[ind]);
                node->children.erase(node->children.begin() + ind);
            }else if(op == "go"){
                int ind;
                cin >> ind;
                menu(node->children[ind]);
            }else if(op == "back"){
                return;
            }else if(op == "show"){
                show(root, 0, 0, node);
            }
        }
    }
};

int main(){
    NTree nt;
    nt.root = new Node(6);
    nt.root->children.push_back(new Node(5));
    nt.root->children.push_back(new Node(4));
    nt.root->children.push_back(new Node(2));
    nt.root->children[0]->children.push_back(new Node(3));
    nt.menu(nt.root);
}