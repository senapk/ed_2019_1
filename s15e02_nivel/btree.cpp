
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <list>
#include <map>
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
    



    Node ** smart_find(Node ** elo, int value){
        Node * node = *elo;
        if(node == nullptr || node->value == value)
            return elo;
        if (value < node->value)
            return smart_find(&node->left, value);
        else
            return smart_find(&node->right, value);
    }

    void insert(int value){
        Node ** elo = smart_find(&root, value);
        if(*elo == nullptr)
            *elo = new Node(value);
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

    void topViewRec(Node * node, int hd, int height, map<int, pair<int, int>>& view){
        if(node == nullptr)
            return;
        if(view.count(hd) == 0)
            view[hd] = make_pair(height, node->value);
        else if(height < view[hd].first)
            view[hd] = make_pair(height, node->value);
        topViewRec(node->left, hd - 1, height + 1, view);
        topViewRec(node->right, hd + 1, height + 1, view);
    }

    string topViewRec(){
        //map<dh, pair<height, value> view
        map<int, pair<int, int>> view;
        topViewRec(root, 0, 1, view);
        stringstream ss;
        for(auto par : view)
            ss << par.second.second << " ";
        return ss.str() + "\n";
    }

    string topView(){
        //dh, value
        map<int, int> view;
        //list <dh, no>
        list<pair<int, Node *>> fila;
        if(root == nullptr)
            return "";

        fila.push_back(make_pair(0, root));
        view[0] = root->value;

        while(!fila.empty()){
            auto par = fila.front();
            int dh = par.first;
            Node * node = par.second;
            fila.pop_front();
            if(node->left)  fila.push_back(make_pair(dh - 1, node->left));
            if(node->right) fila.push_back(make_pair(dh + 1, node->right));
            if(view.count(dh) == 0)
                view[dh] = node->value;            
        }
        stringstream ss;
        for(auto par : view)
            ss << par.second << " ";
        return ss.str() + "\n";
    }

    list<pair<int, int>> getLevelTransversal(){
        list<pair<int, int>> answer;
        list<pair<int, Node *>> fila;
        if(root == nullptr)
            return answer;
        fila.push_back(make_pair(1, root));
        while(!fila.empty()){
            auto par = fila.front();
            int nivel = par.first;
            Node * node = par.second;
            fila.pop_front();
            if(node->left)  fila.push_back(make_pair(nivel + 1, node->left));
            if(node->right) fila.push_back(make_pair(nivel + 1, node->right));
            answer.push_back(make_pair(nivel, node->value));
        }
        return answer;
    }

    string getLevel(){
        stringstream ss;
        list<pair<int, int>> pares = getLevelTransversal();
        if(!pares.empty())
            ss << pares.front().second << " ";
        for(auto it = std::next(pares.begin()); it != pares.end(); it++){
            if(it->first != std::prev(it)->first)
                ss << "\n";
            ss << it->second << " ";
        }
        return ss.str() + "\n";
    }
};




int main(){
    BSTree bt;
    srand(2);
    for(int i = 0; i < 10; i++)
        bt.insert(rand() % 90 + 10);
    bt.bshow();
    cout << bt.topViewRec();
}