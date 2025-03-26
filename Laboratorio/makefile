all: clase.o Data_Types/dtClase.o spinning.o entrenamiento.o inscripcion.o socio.o main.o
	g++ clase.o Data_Types/dtClase.o spinning.o entrenamiento.o inscripcion.o socio.o main.o -o programa

clase.o:
	g++ -c clase.cpp

dtClase.o:
	g++ -c Data_Types/dtClase.cpp

spinning.o:
	g++ -c spinning.cpp

entrenamiento.o:
	g++ -c entrenamiento.cpp

socio.o:
	g++ -c socio.cpp

inscripcion.o:
	g++ -c inscripcion.cpp

main.o: 
	g++ -c main.cpp

clean:
	rm -f clase.o Data_Types/dtClase.o entrenamiento.o spinning.o inscripcion.o socio.o main.o programa

run:
	make clean
	make
	clear
	./programa
