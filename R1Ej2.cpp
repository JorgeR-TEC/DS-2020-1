#include <iostream>

using namespace std;

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
		//cout<<"fin bloque: "<<finBloque<<endl;
		if(a[finBloque]>=buscado){
				return busquedaAux(a, i, finBloque,buscado);
		}
	}
	return -1;
}



class Biblioteca{
	public:
		int cantidadLibros;
		int* libros;
		int* prestado;
		
		Biblioteca(int cL);
		Biblioteca(const Biblioteca& original);
		~Biblioteca();
		void prestar(int libro);
		void devolver(int libro);
};

Biblioteca::Biblioteca(int cL){
	cantidadLibros=cL;
	libros=new int[cantidadLibros]();
	prestado=new int[cantidadLibros]();
	for(int i=0; i<cantidadLibros; i++){
		libros[i]=100000+i;
		prestado[i]=0;
	}
}

Biblioteca::Biblioteca(const Biblioteca& original){
	cantidadLibros=original.cantidadLibros;
	libros=new int[cantidadLibros]();
	prestado=new int[cantidadLibros]();
	for(int i=0; i<cantidadLibros; i++){
		libros[i]=original.libros[i];
		prestado[i]=0;
	}
}

Biblioteca::~Biblioteca(){
	delete [] libros;
	delete [] prestado;
}

void Biblioteca::prestar(int libro){
	int index=busquedaOrdenada2(libros, cantidadLibros, libro, 3);
	if(index==-1){
		cout<<"No contamos con ese libro"<<endl;
		return;
	}
	if(prestado[index]==1){
		cout<<"el libro ya esta prestado"<<endl;
	}else{
		cout<<"libro "<<libro<<" prestado"<<endl;
		prestado[index]=1;//el error es que estaba indicando 0 en vez de 1
	}
}

void Biblioteca::devolver(int libro){
	int index=busquedaOrdenada2(libros, cantidadLibros, libro, 3);
	if(index==-1){
		cout<<"El libro no es de esta biblioteca"<<endl;
		return;
	}
	cout<<"libro "<<libro<<" devuelto"<<endl;
	prestado[index]=0;
}
int main(){
	Biblioteca b(50);
	b.prestar(50);
	b.prestar(100010);
	b.prestar(100010);
	b.devolver(100010);
	b.prestar(100010);
	b.devolver(50);
	return 0;
}