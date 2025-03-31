#include "spinning.h"

int Spinning::getSpinning()
{
    return this->cantBicicletas;  
}
int Spinning::cupo()
{
    return 6;  
}

void Spinning::setSpinning(int cantBicicletas)
{
    this->cantBicicletas = cantBicicletas;  
}
 
Spinning::Spinning(int id, string name, Turno turno, int cantBicicletas) : Clase(id, name, turno)
{
    this->cantBicicletas = cantBicicletas;
};

 