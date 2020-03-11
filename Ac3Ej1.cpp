#include <iostream>
using namespace std;
class Figura{
	public:
		double perimetro;
		double area;
		virtual void calcularPerimetro()=0;
		virtual void calcularArea()=0;
};

class Triangulo : public Figura{
	public:
		double base;
		double altura;
		double l1, l2, l3;
		
		Triangulo(int b, int h, int lado1, int lado2, int lado3){
			base=b;
			altura=h;
			l1=lado1;
			l2=lado2;
			l3=lado3;
		}
		
		void calcularPerimetro(){
			perimetro=l1+l2+l3;
		}
		
		void calcularArea(){
			area=(base*altura)/2;
		}
};

class Cuadrado: public Figura{
	public:
		double lado;
		
		Cuadrado(int l){
			lado=l;
		}
		
		void calcularPerimetro(){
			perimetro=lado*4;
		}
		
		void calcularArea(){
			area=lado*lado;
		}
};

int main(){
	Cuadrado c(5);
	c.calcularArea();
	c.calcularPerimetro();
	Triangulo t(10.0, 5.0, 10.0, 10.0, 10.0);
	t.calcularArea();
	t.calcularPerimetro();
	cout<<"Cuadrado perimetro: "<<c.perimetro<<", area "<<c.area<<endl;
	cout<<"Triangulo perimetro: "<<t.perimetro<<", area "<<t.area<<endl;	
}