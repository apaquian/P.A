#include "dtEntrenamiento.h"
 
dtEntrenamiento::dtEntrenamiento( int id, string nombre, Turno turno , bool Rambla) : dtClase(id, nombre, turno, ENTRENAMIENTO)
{
    this->Rambla = Rambla;
} 

bool dtEntrenamiento::getRambla() {
    return Rambla;
}