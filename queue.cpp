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
class Queue{
	public:
	Nodo<T> *front;
	Nodo<T> *back;
	Queue(){
		front=NULL;
		back=NULL;
	}
	
	void enqueue(T value){
		Nodo<T> *toAdd=new Nodo<T>(value);
		if(back==NULL){
			back=toAdd;
			front=back;//front=toAdd;
		}else{
			back->next=toAdd;
			toAdd->prev=back;
			back=toAdd;
		}
	}
	
	T check(){
		if(front!=NULL){
			return front->value;
		}else{
			return NULL;
		}
	}
	
	void dequeue(){
		if(front==NULL){
			return;
		}else{
			Nodo<T> *temp=front;
			front=front->next;
			if(front!=NULL){
				front->prev=NULL;
			}else{
				back=NULL;
			}
			delete temp;
		}			
	}
};

int main(){
	Queue<int> q;
	q.enqueue(5);
	q.enqueue(3);
	q.enqueue(2);
	cout<<q.check()<<endl;
	q.dequeue();
	cout<<q.check()<<endl;
	q.dequeue();
	cout<<q.check()<<endl;
	q.dequeue();
	if(q.check()!=NULL){
		cout<<q.check()<<endl;
	}else{
		cout<<"la cola esta vacia"<<endl;
	}

}