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

int multiplicacion(int a, int b){
	if(b==1){
		return a;
	}else{
		return a+multiplicacion(a, b-1);
	}
}

int vocalesAux(string s, int actual, int cantidad){
	if(s.length()==actual){//ya no hay mas letras por leer
		return cantidad;
	}else{
		if(s[actual]=='a'||s[actual]=='e'||s[actual]=='i'||s[actual]=='o'||s[actual]=='u'){
			return vocalesAux(s, actual+1, cantidad+1);
		}else{
			return vocalesAux(s, actual+1, cantidad);
		}
	}
}

int vocales(string s){
	return vocalesAux(s, 0,0);
}

int main(){
	int res=vocales("perro");
	cout<<res<<endl;
}