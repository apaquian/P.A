#ifndef DTSPINNING_H
#define DTSPINNING_H

#include <iostream>
using namespace std;
#include "Tipos.h"
#include "dtClase.h"

class dtsSpinning : public dtClase {
private:
    int cantBicicletas;

public:
    dtsSpinning(int id, string name, Turno turno, dtTipoClase tipoClase, int cantBicicletas)
        : dtClase(id, name, turno, tipoClase), cantBicicletas(cantBicicletas) {}
    ~dtsSpinning() {}
    int getCantBicicletas() const { return cantBicicletas; }
};

#endif
