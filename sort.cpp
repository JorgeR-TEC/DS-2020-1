#include <iostream>

using namespace std;

template <class T>
class Sort{
	public:
	virtual void sort(T *a, int size)=0;

	void intercambiar(T *a, int p1, int p2){
        T x= a[p1];
        a[p1] = a[p2];
        a[p2] = x;
    }

	void imprimirArreglo(T *a, int size){
		cout<<a[0];
		for(int i=1; i<size; i++){
			cout<<", "<<a[i];
		}
		cout<<endl;
	}
};

template <class T>
class LuckySort: public Sort<T>{
	public:
	void sort(T *a, int size){
		this->intercambiar(a, 0, size-1);
	}
};

template <class T>
class SelectionSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		for(int i=0; i<size-1; i++){
			int p=i;
			for(int j=i+1; j<size; j++){
				if(a[j]<a[p]){
					p=j;
				}
			}
			this->intercambiar(a, i, p);
		}
	}
};

template <class T>
class BubbleSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		int it=0;
		for(int i=0; i<size-1; i++){
			bool ordenado=true;
			for(int j=0; j<size-1-i; j++){
				it++;
				if(a[j]>a[j+1]){
					this->intercambiar(a, j+1, j);
					ordenado=false;
				}
			}
			if(ordenado==true){
				break;
			}
		}
		cout<<"vueltas: "<<it<<endl;
	}
};


template <class T>
class InsertionSort: public Sort<T>{
	public:
	void sort(T *a, int size){
		for(int i=1; i<size; i++){
			for(int j=i; j>0; j--){
				if(a[j]<a[j-1]){
					this->intercambiar(a, j, j-1);
				}else{
					break;
				}
			}
		}
	}
};

template <class T>
class MergeSort: public Sort<T>{
	public:
	void sort(T *a, int size){
	}
	void merge(T *a, int inicio, int medio, int fin){
		//Tam de la copia
		int tamIzq=medio-inicio+1;
		int tamDer=fin-medio;

		//Crear espacio para copia
		T *copiaIzq=new T[tamIzq]();
		T *copiaDer=new T[tamDer]();
		//Copiando los elementos
		for(int i=0; i<tamIzq; i++){
			copiaIzq[i]=a[inicio+i];
		}
		for(int i=0; i<tamDer; i++){
			copiaDer[i]=a[medio+1+i];
		}
		//Indices
		int I=0;
		int D=0;
		int x=inicio;
		//Comparaciones
		while(I<tamIzq&&D<tamDer){
			if(copiaIzq[I]<copiaDer[D]){
				a[x]=copiaIzq[I];
				I++;
			}else{
				a[x]=copiaDer[D];
				D++;
			}
			x++;
		}
		if(I==tamIzq){
			while(D<tamDer){
				a[x]=copiaDer[D];
				D++;
				x++;
			}
		}else{
			while(I<tamIzq){
				a[x]=copiaIzq[I];
				I++;
				x++;
			}
		}	
	}
};


int main(){
	int size=10;
	int a[size]={10,0,0,1,3,5,2,4,0,10};
	MergeSort<int> s;
	s.imprimirArreglo(a, size);
	s.merge(a, 3, 5, 7);
	s.imprimirArreglo(a,size);
	return 0;
}