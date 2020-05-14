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
class Stack{
	public:
	Nodo<T> *top;
	Stack(){
		top=NULL;
	}
	
	void push(T value){
		Nodo<T> *toAdd=new Nodo<T>(value);
		if(top==NULL){
			top=toAdd;
			return;
		}else{
			top->next=toAdd;
			toAdd->prev=top;
			top=toAdd;
		}
	}
	
	T topCheck(){
		if(top!=NULL){
			return top->value;
		}else{
			NULL;
		}
	}
	
	void pop(){
		if(top==NULL){
			return;
		}else{
			Nodo<T> *temp=top;
			top=top->prev;
			if(top!=NULL){
				top->next=NULL;
			}
			delete temp;
		}
	}

};

int main(){
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(5);
	if(s.topCheck()!=NULL){
		cout<<s.topCheck()<<endl;
	}
	s.pop();
	cout<<s.topCheck()<<endl;
	s.pop();
	cout<<s.topCheck()<<endl;
	s.pop();
	if(s.topCheck()!=NULL){
		cout<<s.topCheck()<<endl;
	}else{
		cout<<"el stack esta vacio"<<endl;
	}
	s.pop();

}