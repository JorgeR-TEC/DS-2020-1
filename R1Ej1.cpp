#include <iostream>

using namespace std;

class Avion{
	public:
		int cantidadAsientos;
		int* asientos;
		Avion(int nA);
		void checkIn(int pasajero, int asiento);
		int verificar(int pasajero);
		~Avion();
};

Avion::Avion(int nA){
	cantidadAsientos=nA;
	asientos=new int[cantidadAsientos]();
	for(int i=0; i<cantidadAsientos; i++){
		asientos[i]=0;
	}
}

Avion::~Avion(){
	delete [] asientos;
}

void Avion::checkIn(int pasajero, int asiento){
	asientos[asiento]=pasajero;
}

int Avion::verificar(int pasajero){
	for(int i=0; i<cantidadAsientos; i++){
		if(asientos[i]==pasajero){
			return 1;
		}
	}
	return -1;
}

int main(){
	Avion amx3045(30);
	amx3045.checkIn(30, 5);
	amx3045.checkIn(1230, 25);
	amx3045.checkIn(2, 12);
	cout<<amx3045.verificar(30)<<endl;
	cout<<amx3045.verificar(10)<<endl;
	return 0;
}