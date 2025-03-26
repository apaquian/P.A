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
        dtClase(int id, string nombre, Turno turno, dtTipoClase tipoClase);
        virtual ~dtClase() {}
    
        int getId() ;
        string getNombre() ;
        Turno getTurno() ;
        dtTipoClase getTipoClase() ; // Devuelve si es SPINNING o ENTRENAMIENTO
    
        // Métodos virtuales "de relleno" que las subclases pueden sobreescribir
        virtual int getCantBicicletas() const { return -1; }
        virtual bool getEnRambla() const { return false; }
     };

#endif
