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

	}
	
	V checkAtKey(K key){
	}
	
	void printDictionary(){
	}
};

int main(){
	Dictionary<int, string> a;
}