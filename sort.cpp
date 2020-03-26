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

int main(){
	int size=5;
	int a[size]={5,4,3,2,1};
	LuckySort<int> s;
	s.imprimirArreglo(a, size);
	s.sort(a, size);
	s.imprimirArreglo(a,size);
	return 0;
}