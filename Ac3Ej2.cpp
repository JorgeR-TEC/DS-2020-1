#include <iostream>
using namespace std;
class Estudiante{
	public:
		int matricula;
		string nombre;
		Estudiante(int m, string n);
		Estudiante(const Estudiante& original);
		~Estudiante();
		void crearHorario(int c);
		void cambiarMateria(int i, int valor);
		void imprimirHorario();
	private:
		int cantidad;
		int *horario;
};

Estudiante::Estudiante(int m, string n){
	matricula=m;
	nombre=n;
}

void Estudiante::cambiarMateria(int i, int valor){
	horario[i]=valor;
}

void Estudiante::crearHorario(int c){
	cantidad=c;
	horario=new int[cantidad]();
	for(int i=0; i<cantidad; i++){
		cout<<"Dame una materia: ";
		cin>>horario[i];
	}
}

Estudiante::~Estudiante(){
	delete [] horario;
}

void Estudiante::imprimirHorario(){
	for(int i=0; i<cantidad; i++){
		cout<<"Materia "<<i<<": "<<horario[i]<<endl;
	}
}

Estudiante::Estudiante(const Estudiante& original){
	nombre=original.nombre;
	matricula=original.matricula;
	cantidad=original.cantidad;
	horario=new int[cantidad]();
	for(int i=0; i<cantidad; i++){
		horario[i]=original.horario[i];
	}
}

int main(){
	Estudiante jorge(20, "Jorge");
	jorge.crearHorario(3);
	jorge.imprimirHorario();
	Estudiante erika=jorge;
	erika.nombre="erika";
	erika.matricula=30;
	erika.imprimirHorario();
	erika.cambiarMateria(2, 10);
	erika.imprimirHorario();
	jorge.imprimirHorario();
	
}