#include "spinning.h"

int Spinning::getSpinning()
{
    return this->cantBicicletas;  
}
int Spinning::cupo()
{
    return 1;  
}

void Spinning::setSpinning(int cantBicicletas)
{
    this->cantBicicletas = cantBicicletas;  
}
Spinning::Spinning(int id, string name, int turno, int cantBicicletas) : Clase(id, name, turno)
{
    this->cantBicicletas = cantBicicletas;
};