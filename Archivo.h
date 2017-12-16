#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <fstream>
#include <string>
#include "Stach.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Archivo{
	private:
		 string arch;
     int validarnuevo;
	public:
    Archivo(string);
    Archivo();
    friend ostream& operator<<(ostream&,Archivo&);
		friend istream& operator>>(istream&,Archivo&);
		string getFileName();
		void setNumero(int);
		int getNumero();


};
#endif
