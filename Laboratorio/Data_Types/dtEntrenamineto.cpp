#include "dtEntrenamiento.h"
 
dtEntrenamiento::dtEntrenamiento( int id, string nombre, Turno turno , bool Rambla) : dtClase(id, nombre, turno, ENTRENAMIENTO)
{
    this->Rambla = Rambla;
} 

bool dtEntrenamiento::getEnRambla()
{
    return this->Rambla;
}
int dtEntrenamiento::getId()
{
    return this->id;
}
string dtEntrenamiento::getNombre()
{
    return this->nombre;
}
Turno dtEntrenamiento::getTurno()
{
    return this->turno;
}
dtTipoClase dtEntrenamiento::getTipoClase()
{
    return this->tipoClase;
}
