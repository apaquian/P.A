#include "Direccion.h"

Direccion::Direccion(){
    this->CP = 11600;
    this->calle = "Artigas";
    this->numero = 452;
}

Direccion::Direccion(int cp, string c, int n) {
    this->CP = cp;
    this->calle = c;
    this->numero = n;
}
int Direccion::getCP(){
    return this->CP;
}
string Direccion::getCalle(){
    return this->calle;
}
int Direccion::getNumero(){
    return this->numero;
}