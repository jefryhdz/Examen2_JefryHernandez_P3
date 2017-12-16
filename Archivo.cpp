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
ostream& operator<<(ostream& out,Archivo& ar ){
  string filename;
  filename+=ar.getFileName();
  ofstream archivo(ar.getFileName().c_str(), fstream::app | std::ios::out);
  if (archivo.is_open()) {
   cout<<"Archivo creado"<<endl;
  }
}
istream& operator>>(istream& in,Archivo& arv){
  string arc;
  arc=arv.getFileName();

  int validarnuevo= arv.getNumero();
  fstream archivo(arc.c_str(), ios::in);
  int contstack=0;
  if (archivo.eof()) {
    if (validarnuevo==0) {
      string respuesta;
      int answer;
      do {

      cout<<"Ingrese la linea que desea ingresar al archivo"<<endl;
        getline(cin,respuesta);
        //cin>>respuesta;

        archivo<<respuesta.c_str();
        cout<<endl;

        cout<<"Desea ingresar otra linea:"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. NO"<<endl;
        respuesta="";
        cin>>respuesta;
        validarnuevo++;
        answer=atoi(respuesta.c_str());
      } while(answer!=2);
      archivo.close();
    }
  }else{
    ofstream archi(arc.c_str(),fstream::app | std::ios::out);
    if (archivo.is_open()) {
      Stack* stack = new ArrayStack(5);
      string respuesta;
      int answer;
      do {
        cout<<"Ingrese la linea que desea ingresar al archivo"<<endl;
        cin.ignore();
        getline(cin,respuesta);
        //cin>>respuesta;
        archi<<respuesta;
        archi<<"\n";
        cout<<endl;
        if (stack->push(respuesta)) {
          //cout<<"so"<<endl
          contstack++;
        }

        validarnuevo++;

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
            bool game=false;
            do {

              if (cont!=validarnuevo-1) {
                getline(archivo,texto);
                texto2+=texto;

                texto2+="\n";
                cout<<cont+1<<endl;
                cout<<validarnuevo<<endl;
              }else if((cont+1)==validarnuevo){

                cout<<"La linea que se va a borrar es"<<stack->pop()<<endl;
                contstack--;
                validarnuevo--;
                game=true;
            }
            cont++;
            //cout<<"JOH"<<endl;
          } while(!game);
          ofstream archiv(arc.c_str(),std::ios::trunc);
          if (archiv.is_open()) {
            archiv<<texto2;
          //  cout<<"sd"<<endl;
          }
          if (contstack>0) {
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
                bool game=false;
                do {

                  if (cont!=validarnuevo-1) {
                    getline(archivo,texto);
                    texto2+=texto;

                    texto2+="\n";
                    cout<<cont+1<<endl;
                    cout<<validarnuevo<<endl;
                  }else if((cont+1)==validarnuevo){

                    cout<<"La linea que se va a borrar es"<<stack->pop()<<endl;
                    contstack--;
                    validarnuevo--;
                    game=true;
                }
                cont++;
                //cout<<"JOH"<<endl;
              } while(!game||contstack<1);
          }
          //archivo.close();
          ofstream archiv(arc.c_str(),std::ios::trunc);
          if (archiv.is_open()) {
            archiv<<texto2;
          //  cout<<"sd"<<endl;
          }



        }else{

        }
        cout<<"Desea ingresar otra linea:"<<endl;
        cout<<"1. Si"<<endl;
        cout<<"2. NO"<<endl;
        respuesta="";
        cin>>respuesta;
        answer=atoi(respuesta.c_str());
      } while(answer!=2);
      arv.setNumero(validarnuevo);
    }
  }
}
string Archivo::getFileName(){
  return arch;
}
int Archivo::getNumero(){
  return validarnuevo;
}void Archivo::setNumero(int numero){
  this->validarnuevo=numero;
}
Archivo::Archivo(){

}
