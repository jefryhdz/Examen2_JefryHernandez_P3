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
    FILE operator<<(string&);
		bool operator>>(string&);


};
#endif
