#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <list>
using namespace std;

class Objeto{
	public:
	int a;
	double b;
	
	Objeto(){
		a=0;
		b=0.0;
	}
	
	Objeto(int a, double b){
		this->a=a;
		this->b=b;;
	}
};
int main(){
	vector<Objeto> a;
	Objeto b(10, 20.0);
	a.push_back(b);
	cout<<a[0].b<<endl;
	/*int a[]={1,2,3,4,5};
	for(int i: a){
		cout<<i<<endl;
	}*///off by one
	
	/*deque<int> q;
	q.push_back(5);
	q.push_back(3);
	for(int i=0; i<q.size(); i++){
		cout<<q[i]<<endl;
	}*/
	/*for(deque<int>::iterator i=q.begin(); i!=q.end(); i++){
		cout<<*i<<", "<<endl;
	}*/
	/*for(auto i: q){
		cout<<i<<endl;
	}*/

	//stack<int> s;
	//queue<int> s;
	/*s.push(5);
	s.push(4);
	s.push(3);
	cout<<s.front()<<endl;
	cout<<s.back()<<endl;
	s.pop();
	cout<<s.front()<<endl;
	s.pop();
	cout<<s.front()<<endl;
	s.pop();*/
}