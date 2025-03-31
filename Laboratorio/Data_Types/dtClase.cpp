#include "dtClase.h"
 
dtClase::dtClase(int id, string nombre, Turno turno, dtTipoClase tipoClase) : 
id(id), nombre(nombre), turno(turno), tipoClase(tipoClase) {
     
}
 

int dtClase::getId() {
    return id;
}

string dtClase::getNombre() {
    return nombre;
}

Turno dtClase::getTurno() {
    return turno;
}

dtTipoClase dtClase::getTipoClase() {
    return tipoClase;
}
