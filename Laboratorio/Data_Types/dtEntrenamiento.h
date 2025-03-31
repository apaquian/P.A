#ifndef DTENTRENAMIENTO_H
#define DTENTRENAMIENTO_H
#include <iostream>
using namespace std;
#include "Tipos.h"
#include "dtClase.h"

class dtEntrenamiento  : public dtClase
{
    private:   
        bool Rambla;
    public:
        dtEntrenamiento( int id, string name, Turno turno , bool Rambla);
        ~dtEntrenamiento(){};
         int getId() ;       
         string getNombre(); 
         Turno getTurno(); 
         dtTipoClase getTipoClase();  // Devuelve si es SPINNING o ENTRENAMIENTO
         virtual bool getEnRambla();     
};
#endif
