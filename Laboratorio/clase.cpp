#include "clase.h"

Clase::Clase(int id, string name, int turno) {
    this-> id = id;
    this->name = name;
    this->turno = turno;
}
int Clase::getId(){
    return this->id;
}
string Clase::getName(){
    return this->name;
}
int Clase::getTurno(){
    return this->turno;
}