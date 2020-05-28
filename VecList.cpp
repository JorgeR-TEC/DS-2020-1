#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
	list<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_front(0);
	
	for(list<int>::iterator i=b.begin(); i!=b.end(); i++){
		cout<<*i<<endl;
	}
	/*vector<int> a;
	//cout<<"size: "<<a.size()<<" capacity: "<<a.capacity()<<endl;
	a.push_back(10);
	a.push_back(29);
	a.push_back(30);
	//cout<<"size: "<<a.size()<<" capacity: "<<a.capacity()<<endl;
	a.push_back(40);
	a.push_back(50);
	//cout<<"size: "<<a.size()<<" capacity: "<<a.capacity()<<endl;
	a[3]=1;
	for(vector<int>::iterator i=a.begin(); i!=a.end(); i++){
		cout<<*i<<endl;
	}*/
	return 0;
}