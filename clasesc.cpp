#include <iostream>

using namespace std;

class Ejemplo{
	public:
		int *a;
		int size;
		
		Ejemplo(int tam){
			size=tam;
			a= new int(size);
			cout<<"Creando arreglo"<<endl;
		}
	

		~Ejemplo(){
			cout<<"Borrando arreglo"<<endl;
			delete [] a;
		}

};


int main(){
	Ejemplo e(10);
	cout<<sizeof(e)<<endl;
	return 0;
}