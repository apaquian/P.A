#include "inscripcion.h"

Inscripcion::Inscripcion(int id, string name, int turno, socio * CI , Clase * idClase, dtFecha * fecha)
{
    this->clase = idClase;
    this->socios = CI;
    this->fecha = fecha;
}

Clase * Inscripcion::getClase()
{
    return this->clase;
}

Inscripcion::~Inscripcion()
{
    delete this->clase;
    delete this->socios;
    delete this->fecha;
}
 
socio * Inscripcion::getSocios()
{
    return this->socios;
}

dtFecha * Inscripcion::getFecha()
{
    return this->fecha;
}

void Inscripcion::setClase(Clase * clase)
{
    this->clase = clase;
}

void Inscripcion::setSocios(socio * socios)
{
    this->socios = socios;
}

void Inscripcion::setFecha(dtFecha * fecha)
{
    this->fecha = fecha;
}

