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
        Turno turno; 
        Inscripcion ** inscripto;
    public:
      
        virtual  int cupo() = 0;    
        Clase(int, string, Turno);
        int getId();
        string getName();
        Turno getTurno();
        void setId();
        void setName();
        Turno setTurno();  
        
};
#endif
