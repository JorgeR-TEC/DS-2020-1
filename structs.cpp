#include <iostream>
using namespace std;

struct Ejemplo{
	int numero1;
	int numero2;
	char char1;
};

struct Estudiante{
	int matricula;
	string nombre;
};


int main(){
	Ejemplo e;
	e.numero1=5;
	e.numero2=20;
	e.char1='a';
	cout<<e.numero1<<endl;
	int *variable=&e.numero1;
	variable++;
	*variable=10;
	cout<<e.numero2<<endl;
	
	


	return 0;
}