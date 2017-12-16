#include "ArrayStack.h"
#include "Archivo.h"
#include "Stach.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[]) {
	//cout<<"#FUERAJOH"<<endl;
	int cont=0;
	int answer;
	string respuesta;

	do {
		do {
			cout<<"Escoja lo que desea hacer: "<<endl;
			cout<<"1. Crear Archivo"<<endl;
			cout<<"2. Modificar"<<endl;
			cin>>respuesta;
			answer=atoi(respuesta.c_str());
		} while(answer<1||answer>2);
		if (answer==1) {
			string filename;
			cout<<"Ingrese el nombre del archivo a crear (con el .txt)"<<endl;
			cin>>filename;
			Archivo afile(filename);

			cout<<afile;
		}else{
			string filename;
			cout<<"Ingrese el nombre del archivo a Modificar (con el .txt)"<<endl;
			cin>>filename;
			Archivo afile(filename);

			cin>>afile;
		}
		cout<<"Desea Continuar en el Programa"<<endl;
		cout<<"1. Si"<<endl;
		cout<<"2. NO"<<endl;
		cin>>respuesta;
		answer=atoi(respuesta.c_str());
	} while(answer<1||answer>2);
  return 0;
}
