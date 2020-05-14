#include <iostream>
#include <vector>
using namespace std;

template <class K, class V>
class KeyPair{
	public:
	K key;
	V value;
	
	KeyPair(){
		key=NULL;
		value=NULL;
	}
	
	KeyPair(K key, V val){
		this->key=key;
		this->value=val;
	}
};

template <class K, class V>
class Dictionary{
	public:
	vector<KeyPair<K,V>> *dict;
	int positions;
	
	Dictionary(){
		positions=10;
		dict=new vector<KeyPair<K,V>>[positions];
	}
	
	Dictionary(int pos){
		positions=pos;
		dict=new vector<KeyPair<K,V>>[positions];
	}
	
	void insert(K key, V value){
		KeyPair<K,V> kp(key, value);
		int hash=key%positions;
		for(int i=0; i<dict[hash].size(); i++){
			if(dict[hash][i].key==key){
				cout<<"llave ya existente"<<endl;
				return;
			}
		}
		dict[hash].push_back(kp);
		//dict//arreglo de vectores keypair
		//dict[hash]//vector de keypair

	}
	
	V checkAtKey(K key){
		int hash=key%positions;
		for(int i=0; i<dict[hash].size(); i++){
			if(dict[hash][i].key==key){
				return dict[hash][i].value;
			}
		}
		return NULL;
	}
	
	void printDictionary(){
	}
};

int main(){
	Dictionary<int, string> a;
	a.insert(5, "perro");
	a.insert(4, "gato");
	cout<<a.checkAtKey(5)<<endl;
}