#include <iostream>

template <class T>
class Vector{
	private:
		T *a;
	public:
		int size;
		int count;
		Vector(){
			a=new T[1024]();
			count=0;
		}
		
		Vector(int s){
			size=s;
			a=new T[s]();
			count=0;
		}
		
		void append(T elemento){
			
		}
		
		void insert(T elemento, int posicion){
		}
		
		
};

int main(){
	Vector<int> v(20);
}