#include "entrenamiento.h"

bool Entrenamiento::getRambla()
{
    return this->rambla;  
}
void Entrenamiento::setRambla(bool rambla)
{
    this->rambla = rambla;  
}
Entrenamiento::Entrenamiento(int id, string name, int turno, bool rambla) : Clase(id, name, turno)
{
    this->rambla = rambla;
}; 