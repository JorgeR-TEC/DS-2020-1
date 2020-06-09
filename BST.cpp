#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

template <class T>
class Nodo{
	public:
	T id;
	Nodo<T> *izquierdo;
	Nodo<T> *derecho;
	Nodo(){
		id=NULL;
		izquierdo=NULL;
		derecho=NULL;
	}
	
	Nodo(T id){
		this->id=id;
		izquierdo=NULL;
		derecho=NULL;
	}
};

template <class T>
class BST{
	public:
	Nodo<T> *root;
	
	BST(){
		root=NULL;
	}
	
	void insertar(T id){
		Nodo<T> *nuevo=new Nodo<T>(id);
		if(root==NULL){
			root=nuevo;
		}else{
			insertar(nuevo, root);
		}
	}
	
	void insertar(Nodo<T> *nuevo, Nodo<T> *temp){
		if(nuevo->id<temp->id){
			if(temp->izquierdo==NULL){
				temp->izquierdo=nuevo;
			}else{
				insertar(nuevo, temp->izquierdo);
			}
		}else if(nuevo->id>temp->id){
			if(temp->derecho==NULL){
				temp->derecho=nuevo;
			}else{
				insertar(nuevo, temp->derecho);
			}
		}
	}
	
	bool buscar(T id){
		return buscar(root, id);
	}
	
	bool buscar(Nodo<T> *temp, T id){
		if(temp==NULL){
			return false;
		}else if(temp->id==id){
			return true;
		}else if(id<temp->id){
			return buscar(temp->izquierdo, id);
		}else{
			return buscar(temp->derecho, id);
		}
	}
	
	
	
	//el mas grande siguiente es el nodo hasta la izquierda empezando desde el derecho
	void recorrido(){
		inorden(root);
		cout<<endl;
	}
	
	void inorden(Nodo<T> *temp){
		if(temp==NULL){
			return;
		}
		inorden(temp->izquierdo);
		cout<<temp->id<<", ";
		inorden(temp->derecho);
	}
	
	void borrar(T id){
		root=borrar(root, id);
	}
	
	Nodo<T> *borrar(Nodo<T> *raizS, T id){
		if(raizS==NULL){//el nodo actual no existe
			return NULL;
		}
		if(id<raizS->id){//el valor buscado es menor que el del nodo actual
			raizS->izquierdo=borrar(raizS->izquierdo, id);
		}else if(id>raizS->id){//el valor buscado es mayor que el del nodo actual
			raizS->derecho=borrar(raizS->derecho, id);
		}else{//el valor buscado es del del nodo actual
			if(raizS->derecho==NULL&&raizS->izquierdo==NULL){
				delete(raizS);
				return NULL;
			}else if(raizS->derecho==NULL&&raizS->izquierdo!=NULL){
				Nodo<T> *regreso=raizS->izquierdo;
				delete(raizS);
				return regreso;
			}
			else if(raizS->derecho!=NULL&&raizS->izquierdo==NULL){
				Nodo<T> *regreso=raizS->derecho;
				delete(raizS);
				return regreso;
			}else{// el nodo a borrar tiene 2 hijos
				Nodo<T> *sustituto=raizS->izquierdo;
				while(sustituto->derecho!=NULL){
					sustituto=sustituto->derecho;
				}
				raizS->id=sustituto->id;
				raizS->izquierdo=borrar(raizS->izquierdo, sustituto->id);
			}
		}
		return raizS;
	}
	
	/*Nodo<T> a(5);
	Nodo<T> *b=new Nodo<T>(5);
	a.derecho;
	(*b).derecho
	b->derecho*/
};

int main(){
	BST<int> a;
	a.insertar(10);
	a.insertar(3);
	a.insertar(20);
	a.insertar(40);
	a.insertar(45);
	a.insertar(11);
	a.recorrido();
	cout<<a.buscar(3)<<endl;
	cout<<a.buscar(7)<<endl;
	a.borrar(20);
	a.recorrido();
	return 0;
}