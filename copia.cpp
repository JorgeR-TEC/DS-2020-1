#include <iostream>

using namespace std;

class Valores{
	public:
		int *a;
		int size;
		
		Valores(int tam){
			size=tam;
			a=new int(size);
		}
		
		Valores(const Valores& deDondeViene){
			size=deDondeViene.size;
			a=new int(size);
			for(int i=0; i<size; i++){
				a[i]=deDondeViene.a[i];
			}
		}
		
};


int main(){
	Valores original(5);
	original.a[0]=10;
	original.a[1]=20;
	original.a[2]=30;
	original.a[3]=40;
	original.a[4]=50;
	cout<<"valor del primer elemento: "<<original.a[0]<<endl;
	Valores copia=original;
	Valores copia2=original;
	original.a[0]=3;
	cout<<"valores despues de copia"<<endl;
	cout<<"valor del primer elemento: "<<original.a[0]<<endl;
	cout<<"valor del primer elemento: "<<copia.a[0]<<endl;
	
}