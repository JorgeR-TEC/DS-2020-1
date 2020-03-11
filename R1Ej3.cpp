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

class Paciente{
	public:
		int id;
		string nombre;
		int edad;
		string enfermedad;
};

class Hospital{
	public:
		int numeroCamas;
		Hospital(int nC);
		void ingresarPaciente(int id, string nombre, int edad);
		void altaPaciente(int id);
		void asignarEnfermedad(int id, string enfermedad);
		~Hospital();
		void imprimirPacientes();
		
	private:
		int *camas;
		Paciente *pacientes;

};

Hospital::Hospital(int nC){
	numeroCamas=nC;
	camas=new int[numeroCamas]();
	pacientes=new Paciente[numeroCamas]();
	for(int i=0; i<numeroCamas; i++){
		camas[i]=0;
	}
}

Hospital::~Hospital(){
	delete [] camas;
	delete [] pacientes;
}

void Hospital::ingresarPaciente(int id, string nombre, int edad){
	int index=busquedaSecuencial(camas, 0, numeroCamas);
	if(index==-1){
		cout<<"No hay camas disponibles para "<<nombre<<endl;
		return;
	}
	camas[index]=id;
	pacientes[index].id=id;
	pacientes[index].nombre=nombre;
	pacientes[index].edad=edad;
	pacientes[index].enfermedad="";
	cout<<nombre<<" admitido en la cama "<<index<<endl;
}

void Hospital::altaPaciente(int id){
	int index=busquedaSecuencial(camas, id, numeroCamas);
	if(index==-1){
		cout<<"El paciente no esta en el hospital"<<endl;
		return;
	}
	cout<<"Dando de alta a "<<pacientes[index].nombre<<" de la cama "<<index<<endl;
	camas[index]=0;
	pacientes[index].id=0;
	pacientes[index].nombre="";
	pacientes[index].edad=0;
	pacientes[index].enfermedad="";
}

void Hospital::asignarEnfermedad(int id, string enfermedad){
	int index=busquedaSecuencial(camas, id, numeroCamas);
	if(index==-1){
		cout<<"El paciente no esta en el hospital"<<endl;
		return;
	}
	pacientes[index].enfermedad=enfermedad;
}

void Hospital::imprimirPacientes(){
	for(int i=0; i<numeroCamas; i++){
		if(camas[i]!=0){
			cout<<"Cama: "<<i<<",Paciente: "<<pacientes[i].nombre;
			cout<<", edad: "<<pacientes[i].edad<<", id: "<<pacientes[i].id;
			cout<<", enfermedad: "<<pacientes[i].enfermedad<<endl;
		}
	}
}

int main(){
	Hospital h(3);
	h.ingresarPaciente(20, "juan", 20);
	h.ingresarPaciente(21, "jorge", 30);
	h.ingresarPaciente(30, "ana", 31);
	h.imprimirPacientes();
	h.ingresarPaciente(40, "erika", 39);
	h.altaPaciente(20);
	h.ingresarPaciente(40, "erika", 39);
	h.asignarEnfermedad(30, "coronavirus");
	h.imprimirPacientes();
	return 0;
}

