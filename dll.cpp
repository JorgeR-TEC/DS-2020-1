#include <iostream>

using namespace std;

template <class T>
class Nodo{
	public:
	T value;
	Nodo<T> *next;
	Nodo<T> *prev;
	
	
	Nodo(T value){
		this->value=value;
		next=NULL;
		prev=NULL;
	}
	
	Nodo(){
		this->value=NULL;
		next=NULL;
		prev=NULL;
	}
};

template <class T>
class DoubleLinkedList{
	public:
		Nodo<T> *root;
		int count;
		DoubleLinkedList(){
			count=0;
			root=NULL;
		}
		void append(Nodo<T> *toAdd);
		void append(T value);
		void imprimir();
		void insert(T, int pos);
		void insert(Nodo<T> *toAdd, int pos);
		void remove(T value);
		void removePos(int pos);
		void sort();
};

template <class T>
void DoubleLinkedList<T>::append(Nodo<T> *toAdd){
	if(root==NULL){
		root=toAdd;
		count=0;
		return;
	}
	Nodo<T> *temp=root;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=toAdd;
	toAdd->prev=temp;
	count++;
}

template <class T>
void DoubleLinkedList<T>::append(T value){
	Nodo<T> *toAdd=new Nodo<T>(value);
	append(toAdd);
}


template <class T>
void DoubleLinkedList<T>::insert(T value, int pos){
	Nodo<T> *toAdd=new Nodo<T>(value);
	insert(toAdd, pos);
}
	
template <class T>
void DoubleLinkedList<T>::insert(Nodo<T> *toAdd, int pos){
	if(root==NULL || pos>=count){
		append(toAdd);
	}else if(pos==0){
		root->prev=toAdd;
		toAdd->next=root;
		root=toAdd;
		count++;
	}else{
		Nodo<T> *temp=root;
		int c=0;
		while(temp->next!=NULL&&c<pos){
			temp=temp->next;
			c++;
		}
		toAdd->prev=temp->prev;//1
		toAdd->next=temp;//2
		temp->prev->next=toAdd;//3
		temp->prev=toAdd;//4
		count++;
	}
}

template <class T>
void DoubleLinkedList<T>::imprimir(){
	Nodo<T> *temp=root;
	while(temp!=NULL){
		cout<<temp->value<<",";
		temp=temp->next;
	}
	cout<<endl;
}


int main(){
	DoubleLinkedList<int> dll;
	dll.append(2);
	dll.append(3);
	dll.append(1);
	dll.imprimir();
	dll.insert(5, 1);
	dll.insert(6,1);
	dll.imprimir();

	return 0;
}