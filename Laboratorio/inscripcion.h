#ifndef INSCRIPCION_H
#define INSCRIPCION_H
#include <iostream>
#include "clase.h"
#include "socio.h"
#include "Data_Types/Fecha.h"
using namespace std; 
class socio;
class Clase;

class Inscripcion
{
    private:
        Clase * clase;
        socio * socios;
        dtFecha * fecha;
    public:
    Inscripcion(int id, string name, int turno, socio * CI , Clase * idClase, dtFecha * fecha);
    ~Inscripcion();
    
};

#endif

