#include <iostream>

using namespace std;

int busquedaSecuencial(int *a, int buscado, int size){
	for(int i=0; i<size; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaOrdenada1(int *a, int buscado, int size){
	if (buscado>a[size-1]){
		return -1;
	}
	for(int i=0; i<size; i++){
		if(a[i]>buscado){
			return -1;
		}
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}

int busquedaAux(int *a, int inicio, int fin, int buscado){
	for(int i=inicio; i<fin; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}


int busquedaOrdenada2(int *a, int size, int buscado, int paso){
	for(int i=paso; i<size; i+=paso){
		cout<<"fin del bloque es "<<i-1<<endl;
		if(a[i-1]>=buscado){
				return busquedaAux(a, i-paso, i,buscado);
		}
	}
	return -1;

}


int main(){
	int size=6;
	int *a=new int[size]();
	a[0]=1;
	a[1]=3;
	a[2]=5;
	a[3]=7;
	a[4]=9;
	a[5]=11;
	cout<<busquedaOrdenada2(a, size, 7, 2)<<endl;
	return 0;
}