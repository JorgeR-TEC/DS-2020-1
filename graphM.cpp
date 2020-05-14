#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

template <class T>
class Graph{
	public:
	vector<vector<int>> edges; 
	unordered_map<T, int> vertex;
	vector<T> ids;
	int currentPos;
	
	Graph(){
		currentPos=0;
	}
	void agregarVertice(T id){
		vertex[id]=currentPos;
		currentPos++;
		ids.push_back(id);
		for(int i=0; i<edges.size(); i++){
			edges[i].push_back(0);
		}
		edges.push_back(vector<int>());
		for(int i=0; i<edges.size(); i++){
			edges[edges.size()-1].push_back(0);
		}
	}
	
	void agregarArco(T id1, T id2){
		edges[vertex[id1]][vertex[id2]]=1;
		edges[vertex[id2]][vertex[id1]]=1;
	}
	
	void print(){
		for(int i=0; i<edges.size(); i++){
			cout<<ids[i]<<": ";
			for(int j=0; j<edges.size(); j++){
				cout<<edges[i][j]<<",";
			}
			cout<<endl;
		}
	}
};

int main(){
	Graph<string> g;
	g.agregarVertice("tlaxcala");
	g.agregarVertice("cdmx");
	g.agregarArco("tlaxcala", "cdmx");
	g.print();
	return 0;
}