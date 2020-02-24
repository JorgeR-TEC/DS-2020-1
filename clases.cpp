#include <iostream>
using namespace std;

class Ejemplo{
	protected:
		int b;
	
	public:
		int a;

		Ejemplo(){
			a=10;
			b=20;
		}
		
		Ejemplo(int valor1, int valor2){
			a=valor1;
			b=valor2;
		}
		
		int getB(){
			return b;
		}
	
		void setB(int valor){
			b=valor;
		}
};

class Hijo: public Ejemplo{
	public:
		Hijo(int valor){
			a=valor;
			b=20;
		}
};
/*public
public->public
protected->protected
private->private

protected
public->protected
protected->protected
private->private

private
public->private
protected->private
private->private
*/



int main(){
	Hijo h(10);
	cout<<h.getB()<<endl;
	return 0;
}