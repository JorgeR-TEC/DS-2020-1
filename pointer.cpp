#include <iostream>
using namespace std;
int main(){
    int a=56;
    int *b=&a;
    int c[5]={10,20,30,40,50};
	int *d=c;
    int *e=new int(5);
	cout<<*d<<endl;
	//cout<<c[2]<<endl;
    cout<<*--d<<endl;
	cout<<*++d<<endl;
}