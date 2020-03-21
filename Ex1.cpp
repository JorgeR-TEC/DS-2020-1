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


class Tienda{
	public:
		int *productos;
		int *cantidad;
		int productosActuales;
		Tienda();
		Tienda(const Tienda& t);
		~Tienda();
		void agregarProducto(int id);
		void stock(int id, int agregar);
		void vender(int id);
};

Tienda::Tienda(){
	productos= new int[1000]();
	cantidad=new int[1000]();
	for(int i=0; i<1000; i++){
		productos[i]=0;
		cantidad[i]=0;
	}
	productosActuales=0;
}

Tienda::Tienda(const Tienda& t){
	productosActuales=t.productosActuales;
	productos= new int[1000]();
	cantidad=new int[1000]();
	for(int i=0; i<1000; i++){
		productos[i]=t.productos[i];
		cantidad[i]=0;
	}
}

Tienda::~Tienda(){
	delete [] productos;
	delete [] cantidad;
}

void Tienda::agregarProducto(int id){
	/*int index=busquedaSecuencial(productos, 0, 1000);
	if (index==-1){
		cout<<"no hay espacio para un nuevo producto"<<endl;
	}else{
		productos[index]=id;
	}*/
	if(productosActuales<1000){
		productos[productosActuales]=id;
		productosActuales++;
	}else{
		cout<<"no hay espacio para un nuevo producto"<<endl;
	}
}

void Tienda::stock(int id, int agregar){
	int index=busquedaSecuencial(productos, id, 1000);
	if(index==-1){
		cout<<"No se puede agregar stock a producto inexistente"<<endl;
	}else{
		cantidad[index]=agregar;
		cout<<"Agregados "<<agregar<<" en stock al producto " <<id<<endl;
	}
}

void Tienda::vender(int id){
	int index=busquedaSecuencial(productos, id, 1000);
	if(index==-1){
		cout<<"No existe ese producto"<<endl;
	}else{
		if(cantidad[index]>0){
			cout<<"vendiendo producto"<<endl;
			cantidad[index]--;
		}else{
			cout<<"producto agotado"<<endl;
		}
	}
}


int main(){
Tienda t;
t.agregarProducto(1001);
t.agregarProducto(1002);
t.agregarProducto(23);
t.stock(1001, 15);
t.stock(1002, 3);
t.stock(1003, 1);//debe imprimir un mensaje de que el producto no existe
t.stock(23, 1);
t.vender(23);
t.vender(1001);
t.vender(1003);//debe indicar que ese producto no existe
t.vender(23);//debe indicar que no hay existencias de ese producto
t.stock(23, 1);
t.vender(23);
t.stock(23, 1);
Tienda otra=t;
otra.vender(23);//debe indicar que no hay existencias de ese producto;
return 0;
}