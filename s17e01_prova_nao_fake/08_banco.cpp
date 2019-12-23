#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <sstream>

using namespace std;

struct Client{

	string id;
	int docs;
	int pac; 

	Client(string id, int docs, int pac){
		this->id = id;
		this->docs = docs; 
		this->pac = pac; 	
	}

	void show(){
		cout << this->id << ":" << this->docs << ":" << this->pac; 
	}
	
};

struct Banco {
	int docs_rec = 0; 
	int docs_lost = 0;
	vector<Client*> cashier;
	list<Client*> queue_in; 
	list<Client*> queue_out; 

	void init(int size){
		for(int i = 0; i < size; i++)
			cashier.push_back(nullptr); 
	}

	void in(string id, int docs, int pac){
		Client *new_client = new Client(id, docs, pac); 
		queue_in.push_back(new_client);
	}

    void show(){
	for(int i = 0; i < (int) cashier.size(); i++){
		if(cashier[i] != nullptr){
			cout << "[";
			cashier[i]->show();
			cout << "]";
		}
		else{
			cout << "[" << "]";
		}
	}
	cout << endl << "in: { ";
	for(auto it = queue_in.begin(); it != queue_in.end(); it++){
		Client *aux = *it;
		aux->show();
		cout << " ";
	}
	cout << " }";

	cout << endl << "out : { ";
	for(auto it = queue_out.begin(); it != queue_out.end(); it++){
		Client *aux = *it;
		aux->show();
		cout << " ";
	}
	cout << " }" << endl;
	}

	void tic(){
		queue_out.erase(queue_out.begin(), queue_out.end());

		for(int i = 0; i < (int) cashier.size(); i++){
    		if(cashier[i] != nullptr){
    			if(cashier[i]->docs > 0){
    				cashier[i]->docs --;	
    				this->docs_rec ++;
    			}
    			else{
    				queue_out.push_back(cashier[i]);
    				cashier[i] = nullptr;
    			}
    		}
    		else{
    			if(queue_in.size() > 0){
    				auto it = queue_in.front();
    				cashier[i] = it;
    				queue_in.pop_front();
    			}
    		}
    	}
    	for(auto it = queue_in.begin(); it != queue_in.end();){
    		Client *aux = *it;
    		if(aux->pac > 0){
    			aux->pac --;
    		}
    		else{
    			this->docs_lost += aux->docs;
    			queue_out.push_back(aux);
    			auto it2 = it;
    			it++;
    			queue_in.erase(it2);
    			continue;
    		}
    		it++;
    	}
    }

	
};

int main(){
	
	Banco *aux = new Banco();

	string cmd, line;

	while(true){
		getline(cin, line);
		stringstream cut(line);
		cut >> cmd;
		if(cmd == "init"){
			int size;
			cut >> size;
			aux->init(size);
		}
		else if(cmd == "in"){
			string id;
			int docs;
            int pac;
			cut >> id;
			cut >> docs;
			cut >> pac;
			aux->in(id, docs, pac);	
		}
		else if(cmd == "show"){
			aux->show();
		}
		else if(cmd == "tic"){
			aux->tic();
		}
		else if(cmd == "end"){
			break;
		}
		else if(cmd == "total"){
			cout << "Documentos recebidos até o momento: " << aux->docs_rec << endl;
			cout << "Documentos perdidos até o momento: " << aux->docs_lost << endl;
		}
	}
    
	while(true){
		bool has = false;
		if(aux->queue_in.size() > 0){
			aux->tic();
			continue;
		}
		else{
			for(int i = 0; i < (int) aux->cashier.size(); i++){
				if(aux->cashier[i] != nullptr){
					has = true;
				}
			}
		}
		if(has){
			aux->tic();
		}
		else{
			break;
		}
	}

	if((int) aux->queue_out.size() > 0){
		aux->queue_out.erase(aux->queue_out.begin(), aux->queue_out.end());
	}

	cout << "Documentos recebidos: " << aux->docs_rec << endl;
	cout << "Documentos perdidos: " << aux->docs_lost;


	return 0;
}