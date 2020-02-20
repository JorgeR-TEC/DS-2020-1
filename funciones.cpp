#include <iostream>
using namespace std;
void function(int a, int& b, int* c){
	a++;
	b++;
	*c=*c+1;
	//c[0]=20;

}

int main(){
	int a=1;
	int b=2;
	int c=3;
	//int *c=new int(5);
	//c[0]=1;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c[0]<<endl;
	function(a,b, &c);
	cout<<"despues"<<endl;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	//cout<<c[0]<<endl;
	return 0;
}