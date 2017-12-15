#include "Archivo.h"
#include <stdio.h>
#include "ArrayStack.h"
#include <iostream>
#include <fstream>

using namespace std;

Archivo::Archivo(string filename){
  this->arch=filename;
  this->validarnuevo=0;
}
FILE Archivo::operator<<(string& filename ){

}
bool Archivo::operator>>(string& arc){
  arc+=".txt";
  ofstream archivo(arc.c_str(), ios::app);
  if (archivo.is_open()) {
    if (validarnuevo==0) {
      string respuesta;
      int answer;
      do {
        cout<<"Ingrese la linea que desea ingresar al archivo"<<endl;
        cin.getline((char*)respuesta.c_str(),256);
        archivo<<respuesta.c_str();
        cout<<endl;
        cout<<"Desea ingresar otra linea:"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. NO"<<endl;
        respuesta="";
        cin>>respuesta;
        this->validarnuevo++;
        answer=atoi(respuesta.c_str());
      } while(answer!=2);
      archivo.close();
    }
  }else{
    ofstream archi(arc.c_str(), ios::app);

    if (archivo.is_open()) {
      Stack* stack = new ArrayStack(5);
      string respuesta;
      int answer;
      do {
        cout<<"Ingrese la linea que desea ingresar al archivo"<<endl;
        cin.getline((char*)respuesta.c_str(),256);
        archivo<<respuesta.c_str();
        cout<<endl;
        stack->push(respuesta);
        cout<<"Desea ingresar otra linea:"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. NO"<<endl;
        respuesta="";
        cin>>respuesta;
        this->validarnuevo++;
        answer=atoi(respuesta.c_str());
        string delet;
        int borrar;
        do {
          cout<<endl;
          cout<<"Desea borrar la ultima linea:"<<endl;
          cout<<"1. Si"<<endl;
          cout<<"2. NO"<<endl;
          delet="";
          cin>>delet;
          borrar=atoi(delet.c_str());
        } while(borrar<1||borrar>2);
        if (borrar==1) {
          int cont=0;
          string texto;
          string texto2;
          do {
            if (cont!=validarnuevo) {
            //  getline(archivo,texto);
              texto2+=texto;
              texto2+="\n";
            }else{
              cout<<"La linea que se va a borrar es"<<stack->pop();
                this->validarnuevo--;
            }
          } while(cont!=validarnuevo);
          archivo<<texto2;
        }else{

        }
      } while(answer!=2);
    }
  }
}
