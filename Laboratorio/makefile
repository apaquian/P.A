all: inscripcion.o  clase.o Data_Types/dtClase.o Data_Types/Fecha.o spinning.o entrenamiento.o socio.o main.o
	g++ inscripcion.o clase.o Data_Types/dtClase.o Data_Types/Fecha.o spinning.o entrenamiento.o socio.o main.o -o programa

inscripcion.o:
	g++ -c inscripcion.cpp

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


main.o: 
	g++ -c main.cpp

clean:
	rm -f clase.o Data_Types/dtClase.o Data_Types/Fecha.o entrenamiento.o spinning.o inscripcion.o socio.o main.o programa

run:
	make clean
	make
	clear
	./programa
