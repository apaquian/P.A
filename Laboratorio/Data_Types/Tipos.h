#ifndef DTTIPOS_H
#define DTTIPOS_H

#include <stdexcept>
#include <string>

enum Turno {
    Manana,
    Tarde,
    Noche
};

enum dtTipoClase {
    SPINNING,
    ENTRENAMIENTO
};

const int MAX_SOCIOS = 50;
const int MAX_CLASES = 50;
const int MAX_INSCRIPCIONES = 200; 

#endif