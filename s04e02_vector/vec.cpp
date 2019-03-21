#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template <class Elem>
struct Vector{
    Elem * data;
    int size;
    int capacity;

    Vector(int cap){
        this->size = 0;
        this->capacity = cap;
        this->data = new Elem[cap];
    }
    ~Vector(){
        delete [] this->data;
    }
    void push_back(Elem value){
        if(this->size == this->capacity)
            resize(this->capacity * 2);
        this->data[this->size] = value;
        this->size += 1;
    }

    void resize(int new_capacity){
        this->data = (Elem*) realloc(this->data, new_capacity * sizeof(int));
        this->capacity = new_capacity;
        if(new_capacity < this->size)
            this->size = new_capacity;
    }

    void pop_back(){
        if(this->size > 0)
            return;
        this->size -= 1;
    }

    void show(){
        printf("[ ");
        for(int i = 0; i < this->size; i++){
            cout << this->data[i];
        }
        printf("] %d/%d\n", this->size, this->capacity);
    }
};


int main(){
    Vector<string> nomes(3);
    nomes.push_back("oi");
    nomes.push_back("tim");



    Vector<int> vec(1);
    vec.show();
    vec.push_back(4);
    vec.show();
    vec.push_back(4);
    vec.show();
    vec.push_back(6);
    vec.show();
    vec.push_back(1);
    vec.show();
    vec.push_back(2);
    vec.show();
    vec.push_back(3);
    vec.show();
    vec.push_back(8);
    vec.show();
    vec.push_back(9);
    vec.show();

}

/* struct Pessoa{
    string nome;
    int idade;

    Pessoa cruzar(Pessoa other){
        Pessoa filho;
        filho.idade = 0;
        filho.name = this->name + other.name;
        return filho;
    }
};


Pessoa a("jose", 33);
Pessoa b("maria", 32);
Pessoa filho = b.cruzar(a) */