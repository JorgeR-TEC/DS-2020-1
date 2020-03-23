#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

int busquedaBinaria(int *a, int inicio, int fin, int buscado){
	if(fin<inicio){
		return -1;
	}
	int medio=(fin+inicio)/2;
	if(buscado==a[medio]){
		return medio;
	}else if(buscado<a[medio]){
		return busquedaBinaria(a, inicio, medio-1, buscado);
	}else{
		return busquedaBinaria(a, medio+1, fin, buscado);
	}
}


int main(){
	int size=10000;
	int *a=new int[size]();
	for(int i=0; i<size; i++){
		a[i]=i;
	}
	auto inicial=high_resolution_clock::now();
	busquedaBinaria(a, 0, size-1, 1000);
	auto fin=high_resolution_clock::now();
	auto duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"Binaria\t"<<duracion<<endl;
	inicial=high_resolution_clock::now();
	busquedaSecuencial(a, 1000, size);
	fin=high_resolution_clock::now();
	duracion=duration_cast<nanoseconds>(fin-inicial).count();
	cout<<"secuencial\t"<<duracion<<endl;
	return 0;
}
