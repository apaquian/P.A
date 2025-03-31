#ifndef DTCLASE_H
#define DTCLASE_H

#include <iostream>
using namespace std;
#include "Tipos.h"

class dtClase {
protected:
    int id;
    string nombre;
    Turno turno;
    dtTipoClase tipoClase;

public:
    dtClase(int id, string nombre, Turno turno, dtTipoClase tipoClase)
        : id(id), nombre(nombre), turno(turno), tipoClase(tipoClase) {}

    virtual ~dtClase() {}

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    Turno getTurno() const { return turno; }
    dtTipoClase getTipoClase() const { return tipoClase; }
};

#endif
