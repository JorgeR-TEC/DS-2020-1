#include <iostream>
#include <unordered_map>
using namespace std;

template <class T>
class Nodo{
	public:
	T id;
	unordered_map<Nodo<T> *, int> arcos;
	
	Nodo(){
		id=NULL;
	}
	
	Nodo(T value){
		id=value;
	}
	
	void agregarArco(Nodo<T> *next, int peso){
		arcos[next]=peso;
	}
	
	void agregarArco(Nodo<T> *next){
		arcos[next]=1;
	}
	
	void print(){
		cout<<id<<":";
		for(auto i: arcos){
			cout<<i.first->id<<", "<<i.second<<"; ";
		}
		cout<<endl;
	}
	
};

template <class T>
class Graph{
	public:
	unordered_map<T, Nodo<T> *> vertices;
	
	void agregarVertice(T id){
		Nodo<T> *nuevo=new Nodo<T>(id);
		if(vertices.find(id)==vertices.end()){
			vertices[id]=nuevo;
		}else{
			cout<<"el nodo ya existe"<<endl;
		}	
	}
	
	void agregarArco(T idFuente, T idDestino, int peso){
		vertices[idFuente]->agregarArco(vertices[idDestino],peso);
		//vertices[idDestino]->agregarArco(vertices[idFuente],peso);
	}
	
	void imprimirGrafo(){
		for(auto i: vertices){
			i.second->print();
		}
	}
	
};

int main(){
	Graph<string> a;
	a.agregarVertice("cdmx");
	a.agregarVertice("tlaxcala");
	a.agregarArco("cdmx", "tlaxcala", 180);
	a.agregarArco("cdmx", "cdmx", 2);
	a.imprimirGrafo();
	return 0;
}