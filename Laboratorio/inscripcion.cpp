#include "inscripcion.h"

Inscripcion::Inscripcion(int id, string name, int turno, socio * CI , Clase * idClase, dtFecha * fecha)
{
    this->clase = idClase;
    this->socios = CI;
    this->fecha = fecha;
}