#ifndef ARRAYSTACK_H  /* code */
#define ARRAYSTACK_H
#include <string>
#include "Stach.h"
using namespace std;
class ArrayStack: public Stack{
	private:
		string* array;
		int size;
		int availPos;
	public:
		ArrayStack(int);
		virtual bool push(string);
		virtual string pop();
		virtual bool isEmpty();

		~ArrayStack();

};
#endif
