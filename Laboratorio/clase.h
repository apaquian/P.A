#ifndef CLASE_H
#define CLASE_H
#include <iostream>
#include "Data_Types/dtClase.h"
#include "Data_Types/Tipos.h"
#include "inscripcion.h"
using namespace std;
class Inscripcion;

class Clase 
{
    private:
        int id;
        string name;
        int turno; 
        Inscripcion * inscripto;
    public:
      
        virtual  int cupo() = 0;    
        Clase(int, string, int);
        int getId();
        string getName();
        int getTurno();
        void setId();
        void setName();
        void setTurno(); 
        dtClase * getDtClase();
        Inscripcion * getInscripciones();
};
#endif
