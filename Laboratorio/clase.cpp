#include "clase.h"

Clase::Clase(int id, string name, Turno turno) {
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
Turno Clase::getTurno(){
    return this->turno;
}
void Clase::setId(){
    this->id = id;
}
void Clase::setName(){
    this->name = name;
}
Turno Clase::setTurno(){
    return this->turno;
}