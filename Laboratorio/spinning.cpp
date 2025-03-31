#include "spinning.h"

int Spinning::getBicicleta()
{
    return this->cantBicicletas;  
}
int Spinning::cupo()
{
    return this->cantBicicletas;  
}
void Spinning::setBicicleta(int cantBicicletas)
{
    this->cantBicicletas = cantBicicletas;  
}
Spinning::Spinning(int id, string name, Turno turno, int cantBicicletas) : Clase(id, name, turno)
{
    this->cantBicicletas = cantBicicletas;
};