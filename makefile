main.exe : main.o
	g++ main.o -o add-nbo
main.o : main.cpp
	g++ -c main.cpp
clean : 
	rm -f  add-nbo main.o
