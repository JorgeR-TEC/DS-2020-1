#include <iostream>
#include <map>
#include <set>
using namespace std;

class Estudiante{
	public:
	int matricula;
	string nombre;
	double promedio;
	
	Estudiante(){
		matricula=0;
		nombre="";
		promedio=0.0;
	}
	Estudiante(int m, string n, double p){
		matricula=m;
		nombre=n;
		promedio=p;
	}
};

struct comp{
	bool operator()(const Estudiante& a, const Estudiante& b){
		return a.matricula < b.matricula;
	}
};


int main(){
	/*set<Estudiante, comp> s;
	Estudiante a(965439, "jorge", 92.5);
	s.insert(a);*/
	
	/*set<int> s;
	s.insert(5);
	s.insert(3);
	s.insert(1);
	for(set<int>::iterator i=s.begin(); i!=s.end(); i++){
		cout<<"Key: "<<*i<<endl;
	}
	set<int>::iterator i=s.find(2);
	if(i==s.end()){
		cout<<"valor no existe"<<endl;
	}
	*/
	map<Estudiante,string, comp> estudiantes;
	string b="reprobado";
	Estudiante a(965439, "jorge", 92.5);
	estudiantes.insert({a, b});
	
	/*map<int, string> m;
	m.insert(pair<int, string>(1,"a"));
	m.insert({2, "b"});
	m[965439]="jorge";
	for(map<int, string>::iterator i=m.begin(); i!=m.end(); i++){
		cout<<"Key: "<<(*i).first<<" Value: "<<i->second<<endl;
	}
	map<int, string>::iterator pos=m.find(965440);
	if(pos!=m.end()){
		cout<<"Key: "<<(*pos).first<<" Value: "<<pos->second<<endl;
	}else{
		cout<<"la llave no existe"<<endl;
	}*/
	
	//map[5]="d";
	return 0;

}