#include "entrenamiento.h"

bool Entrenamiento::getRambla()
{
    return this->rambla;  
}

int Entrenamiento::cupo()
{
    return 20;  
}

void Entrenamiento::setRambla(bool rambla)
{
    this->rambla = rambla;  
}
Entrenamiento::Entrenamiento(int id, string name, Turno turno, bool rambla) : Clase(id, name, turno)
{
    this->rambla = rambla;
}; 