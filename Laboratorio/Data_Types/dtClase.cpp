#include "dtClase.h"

dtClase::dtClase(int i, string name, int t) {
    this->id = i;
    this->name = name;
    this->turno = t;
}
int dtClase::getId(){
    return this->id;
}
string dtClase::getName(){
    return this->name;
}
int dtClase::getTurno(){
    return this->turno;
}