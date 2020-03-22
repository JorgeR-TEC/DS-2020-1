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
		return a+multiplicacion(a,b-1);
	}
}

int potencia(int a, int b){
	if(b==0){
		return 1;
	}else{
		return multiplicacion(a, potencia(a, b-1));
	}
}
int maximoAux(int *arreglo, int size, int actual, int max){
	if(actual==size){
		return max;
	}else{
		if(max<arreglo[actual]){
			return maximoAux(arreglo, size, actual+1, arreglo[actual]);
		}else{
			return maximoAux(arreglo, size, actual+1, max);
		}
	}
}

						
int maximo(int *arreglo, int size){
	return maximoAux(arreglo, size, 0, arreglo[0]);
}

int vocalesAux(string s, int actual, int cantidad){
	if(actual==s.length()){
		return cantidad;
	}else{
		if(s[actual]=='a'||s[actual]=='e'||s[actual]=='i'||s[actual]=='o'||s[actual]=='u'){
			vocalesAux(s, actual+1, cantidad+1);
		}else{
			vocalesAux(s, actual+1, cantidad);
		}
	}
}

int vocales(string s){
	vocalesAux(s, 0, 0);
}

int main(){
	int size=5;
	int a[size]={1,3,2,5,4};
	int res=vocales("perro grande");
	cout<<res<<endl;
}