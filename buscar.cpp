#include <iostream>
#include <string>
using namespace std;
int main(){
    string frase="";
    string palabra="";
    getline(cin, frase);
    getline(cin, palabra);
    int count=0;
    int pos=0;
    pos=frase.find(palabra);
    while(pos!=-1){
        count++;
        pos=frase.find(palabra, pos+1);
    }
    cout<<"Encontrada la palabra "<<count<<" veces"<<endl;

    
}