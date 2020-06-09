#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include "GraphL.cpp"
#include "BST2.cpp"
#include <map>
using namespace std;


struct Data{
    string user1;
    int inter;
    string user2;

    Data(string u1, int i, string u2){
        user1=u1;
        inter=i;
        user2=u2;
    }
};

vector<Data> interacciones;

void leerData(string path){
    ifstream fIn;
    fIn.open(path);
    string temp, line, parts;
    vector<string> valores;
    while(fIn.good()){
        getline(fIn, line); 
        istringstream s(line); 
        while (getline(s, parts, ',')) { 
                valores.push_back(parts);
         }
         if(valores[2].find('\r')!=valores[2].npos){
              interacciones.push_back(Data(valores[0], stoi(valores[1]), valores[2].substr(0, valores[2].size()-1)));
         }else{
            interacciones.push_back(Data(valores[0], stoi(valores[1]), valores[2]));
         }
        
         valores.clear(); 
    }
    fIn.close();
}


class Set1{
    public:
    unordered_set<string> usuarios;
    unordered_map<string, unordered_set<string>> seguidores;

    void obtenerUsuarios(){
        for(Data inter: interacciones){
            usuarios.insert(inter.user1);
            usuarios.insert(inter.user2);
        }
    }

    bool usuarioExistente(string user){
        obtenerUsuarios();
        if(usuarios.find(user)==usuarios.end()){
            return false;
        }else{
            return true;
        }
    }

    void obtenerSeguidores(){
         for(Data inter: interacciones){
             if(seguidores.find(inter.user2)==seguidores.end()){
                 seguidores[inter.user2]=unordered_set<string>();
             } 
             seguidores[inter.user2].insert(inter.user1);
             if(inter.inter==1){
                 if(seguidores.find(inter.user1)==seguidores.end()){
                    seguidores[inter.user1]=unordered_set<string>();
                 } 
                seguidores[inter.user1].insert(inter.user2);
             }      
        }
    }

    bool esSeguidor(string userA, string userB){
        obtenerSeguidores();
        if(seguidores.find(userA)!=seguidores.end()){
            if(seguidores[userA].find(userB)!=seguidores[userA].end()){
                return true;
            }
        }
        return false;
    }

};//Agrega aqui los datos y metodos para resolver los problemas del set 1

class Set2{
public:
    Graph<string> relacion;
    Graph<string> interaccion;

    void generarRelaciones(){
        for(Data inter: interacciones){
            relacion.agregarVertice(inter.user1);
            relacion.agregarVertice(inter.user2);
            relacion.agregarArco(inter.user1, inter.user2, 1);
            relacion.agregarArco(inter.user2, inter.user1,1 );
        }
    }

    void generarInteracciones(){
          for(Data inter: interacciones){
            interaccion.agregarVertice(inter.user1);
            interaccion.agregarVertice(inter.user2);
            if(inter.inter==1){
                interaccion.agregarArco(inter.user2, inter.user1, interaccion.pesoArco(inter.user2, inter.user1)+1);
            }
            interaccion.agregarArco(inter.user1, inter.user2, interaccion.pesoArco(inter.user1, inter.user2)+1);
        }
    }

    bool hayRelacion(string userA, string userB){
        generarRelaciones();
        return relacion.relacion(userA, userB);
    }

    string mayorInteraccion(string userA){
        generarInteracciones();
        interaccion.imprimirGrafo();
        string mayor=interaccion.mayorInteraccion(userA);
        if(mayor==userA){
            return "";
        }else{
            return mayor;
        }
    }



};//Agrega aqui los datos y metodos para resolver los problemas del set 2

class Set3{
    public:
    string mayorSeguidor(){
        unordered_map<string, unordered_set<string>> seguidos;
        for(Data inter: interacciones){
             if(seguidos.find(inter.user1)==seguidos.end()){
                 seguidos[inter.user1]=unordered_set<string>();
             } 
             seguidos[inter.user1].insert(inter.user2);
             if(inter.inter==1){
                 if(seguidos.find(inter.user2)==seguidos.end()){
                    seguidos[inter.user2]=unordered_set<string>();
                 } 
               seguidos[inter.user2].insert(inter.user2);
             }      
        }
        BST2<int, string> cantidadSeguidos;
        for(auto i: seguidos){
            cantidadSeguidos.insertar(i.second.size(), i.first);
        }
        return cantidadSeguidos.masGrande();
    }
    

    string amplificador(){
        unordered_map<string, int> cantidadCompartir;
        for(Data inter: interacciones){
            if(inter.inter==0){
                if(cantidadCompartir.find(inter.user1)==cantidadCompartir.end()){
                    cantidadCompartir[inter.user1]=0;
                }
                cantidadCompartir[inter.user1]++;
            }
        }
        BST2<int, string> compartir;
        for(auto i: cantidadCompartir){
            compartir.insertar(i.second, i.first);
        }
        return compartir.masGrande();
    }

     string callado(){
        unordered_map<string, int> cantidad;
        for(Data inter: interacciones){
            if(inter.inter==1){
                if(cantidad.find(inter.user1)==cantidad.end()){
                    cantidad[inter.user1]=0;
                }
                cantidad[inter.user1]++;
            }
        }
        BST2<int, string> compartir;
        for(auto i: cantidad){
            compartir.insertar(i.second, i.first);
        }
        return compartir.masChico();
    }

};//Agrega aqui los datos y metodos para resolver los problemas del set 3

class infoUser{
    public:
    string id;
    unordered_set<string> seguidos;
    unordered_set<string> seguidores;
    int comentariosHechos;
    int comentariosRecibidos;
    int compartirHechos;
    int compartirRecibidos;
     
    infoUser(){
        comentariosHechos=0;
        comentariosRecibidos=0;
        compartirHechos=0;
        compartirRecibidos=0;
    } 
    infoUser(string id){
        this->id=id;
        comentariosHechos=0;
        comentariosRecibidos=0;
        compartirHechos=0;
        compartirRecibidos=0;
    }

};

class Set4{
    public:
    unordered_map<string, unordered_set<string>> amigos;
    unordered_map<string, infoUser> users;
    
    void calcularAmigos(){
        for(Data inter: interacciones){
            if(inter.inter==1){
                if(amigos.find(inter.user1)==amigos.end()){
                    amigos[inter.user1]=unordered_set<string>();
                }
                amigos[inter.user1].insert(inter.user2);
            }
        }
    }

    void llenarInfo(){
        for(Data inter: interacciones){
             if(users.find(inter.user1)==users.end()){
                users[inter.user1]=infoUser(inter.user1);
            }
            if(users.find(inter.user2)==users.end()){
                users[inter.user2]=infoUser(inter.user2);
            }
            users[inter.user1].seguidos.insert(inter.user2);
            users[inter.user2].seguidores.insert(inter.user1);
            if(inter.inter==0){
                users[inter.user1].compartirHechos++;
                users[inter.user2].compartirRecibidos++;
            }else{
                users[inter.user2].seguidos.insert(inter.user1);
                users[inter.user1].seguidores.insert(inter.user2);
                users[inter.user1].comentariosHechos++;
                users[inter.user2].comentariosRecibidos++;
            }

        }
    }

    bool sonAmigos(string user1, string user2){
        calcularAmigos();
        if(amigos.find(user1)!=amigos.end()){
            if(amigos[user1].find(user2)!=amigos[user1].end()){
                return true;
            }
        }
        return false;
    }

    void listarAmigos(string user1){
         calcularAmigos();
        if(amigos.find(user1)!=amigos.end()){
            for(auto amigo: amigos[user1]){
                cout<<amigo<<",";
            }
            cout<<endl;
        {}
        }
    }

    bool conexion(string user1, string user2){
        Set2 s2;
        s2.generarInteracciones();
        return s2.interaccion.BFS(user1, user2);
    }

    double FFR(string user1){
        
        double ffr=users[user1].seguidores.size();
        if(users[user1].seguidos.size()>0){
            ffr=users[user1].seguidores.size()/users[user1].seguidos.size();
        }
        return ffr;
    }

    double CSR(string user1){
        llenarInfo();
        double csr=users[user1].compartirHechos;
        if(users[user1].comentariosHechos){
            csr=users[user1].compartirHechos/users[user1].comentariosHechos;
        }
        return csr;
    }
    
    void influencers(){
        llenarInfo();
        map<double, vector<string>> ffrMap;
        for(auto u: users){
            double value=FFR(u.second.id);
            cout<<value<<endl;
            if(ffrMap.find(value)==ffrMap.end()){
                ffrMap[value]=vector<string>();
            }
            ffrMap[value].push_back(u.second.id);
        }
        int count=0;
        cout<<"Influencers: ";
        for(auto i=ffrMap.rbegin(); i!=ffrMap.rend(); i++){
                for(string valor: i->second){
                    cout<<valor<<",";
                    count++;
                    if(count==5){
                        cout<<endl;
                        return;
                    }
                    
                }
        }
    }

    void bots(){
        llenarInfo();
        map<double, vector<string>> ffrMap;
        for(auto u: users){
            double value=FFR(u.second.id);
            if(ffrMap.find(value)==ffrMap.end()){
                ffrMap[value]=vector<string>();
            }
            ffrMap[value].push_back(u.second.id);
        }
        int count=0;
        cout<<"Bots: ";
        for(auto i=ffrMap.begin(); i!=ffrMap.end(); i++){
                for(string valor: i->second){
                    cout<<valor<<",";
                    count++;
                    if(count==5){
                        cout<<endl;
                        return;
                    }
                    
                }
        }
    }

    string masCompartido(){
        llenarInfo();
        string usuario;
        int cantidad=0;
        for(auto u: users){
            if(cantidad<u.second.compartirRecibidos){
                cantidad=u.second.compartirRecibidos;
                usuario=u.second.id;
            }
        }
        return usuario;
    }

    string masComentado(){
        llenarInfo();
        string usuario;
        int cantidad=0;
        for(auto u: users){
            if(cantidad<u.second.comentariosRecibidos){
                cantidad=u.second.comentariosRecibidos;
                usuario=u.second.id;
            }
        }
        return usuario;
    }

     string masInteracciones(){
        Set2 s2;
        s2.generarInteracciones();
        return s2.interaccion.mayorInteraccionPar();
    }


};//Agrega aqui los datos y metodos para resolver los problemas del set 4

int main(){
    //Cambia la ruta a donde se encuentra el archivo
    //Ejemplo windows en WSL: /mnt/c/Users/Jorge/Desktop/file.txt
    //Ejemplo Mac: /Users/Jorge/Desktop/file.txt
    //En la misma carpeta: file.txt
    string path="file.txt";
    leerData(path);
    /*for(auto i: interacciones){
        cout<<i.user1<<":"<<i.inter<<":"<<i.user2<<endl;
    }*/
    Set4 s4;
    cout<<s4.masInteracciones()<<endl;
    
    return 0;
}