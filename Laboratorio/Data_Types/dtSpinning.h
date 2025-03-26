#ifndef DTSPINNING_H
#define DTSPINNING_H
#include <iostream>
using namespace std;
#include "Tipos.h"
#include "dtClase.h"


class dtsSpinning   : public dtClase
{
    private: 
        int cantBicicletas;  
     public:
        dtsSpinning( int id, string name , Turno turno, int cantBicicletas); 
        virtual int getCantBicicletas() ;
 };
#endif
