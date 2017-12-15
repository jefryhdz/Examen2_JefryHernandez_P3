main:    main.cpp Archivo.o ArrayStack.o Stach.o 
	g++ main.cpp Archivo.o ArrayStack.o Stach.o -o main
main.o:	main.cpp Archivo.h ArrayStack.h Stach.h 
	g++ -c main.cpp
Archivo:	Archivo.cpp Archivo.h
	g++ -c Archivo.cppArrayStack:	ArrayStack.cpp ArrayStack.h
	g++ -c ArrayStack.cppStach:	Stach.cpp Stach.h
	g++ -c Stach.cpp
	
clean:
	rm  *.o main 
