all: clase.o spinning.o entrenamiento.o inscripcion.o socio.o  main.o 
	g++ clase.o spinning.o entrenamiento.o inscripcion.o socio.o  main.o -o programa

clase.o:
	g++ -c clase.cpp

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
	rm -f clase.o spinning.o entrenamiento.o inscripcion.o socio.o  main.o  programa

run:
	make clean
	make
	clear
	./programa