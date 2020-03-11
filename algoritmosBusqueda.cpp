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
	for(int i=inicio; i<=fin; i++){
		if(a[i]==buscado){
			return i;
		}
	}
	return -1;
}


int busquedaOrdenada2(int *a, int size, int buscado, int paso){
	int i=0;
	for(i=0; i<size; i+=paso){
		int finBloque=i+paso-1;
		
		if(size-1<finBloque){
			finBloque=size-1;
		}
		cout<<"fin bloque: "<<finBloque<<endl;
		if(a[finBloque]>=buscado){
				return busquedaAux(a, i, finBloque,buscado);
		}
	}
	return -1;
}


int main(){
	int size=7;
	int *a=new int[size]();
	a[0]=1;
	a[1]=3;
	a[2]=5;
	a[3]=7;
	a[4]=9;
	a[5]=11;
	a[6]=13;



	cout<<busquedaOrdenada2(a, size, 15, 30)<<endl;
	return 0;
}
