#include <iostream>
using namespace std;
int factorial(int num){
	int res=1;
	for(int i=num; i>0; i--){
		res=res*i;
	}
	return res;
}

int factorialR(int n){
	if(n==0){
		return 1;
	}else{
		return n*factorialR(n-1);
	}
}

int main(){
	int res=factorialR(5);
	cout<<res<<endl;
}