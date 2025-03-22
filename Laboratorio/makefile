all: clase.o main.o 
	g++ clase.o main.o -o programa

entreno.o:
	g++ -c clase.cpp

main.o: 
	g++ -c main.cpp

clean:
	rm -f main.o clase.o programa

run:
	make clean
	make
	clear
	./programa