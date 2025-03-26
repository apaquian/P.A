#include "dtSpinning.h"

dtsSpinning::dtsSpinning( int id, string name , Turno turno, int cantBicicletas) : dtClase(id, name, turno, SPINNING)
{
    this->cantBicicletas = cantBicicletas;
}
int dtsSpinning::getCantBicicletas()
{
    return this->cantBicicletas;
}
