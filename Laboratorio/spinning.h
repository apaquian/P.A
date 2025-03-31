#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>
#include "clase.h"
#include "Data_Types/Tipos.h"
#include "Data_Types/dtSpinning.h"
using namespace std;
class Spinning  : public Clase
{
    private:    
        int cantBicicletas;
    public:
        int cupo();
        Spinning(int id, string name, Turno turno, int cantBicicletas);
        ~Spinning();
        int getBicicleta();
        void setBicicleta(int);
        dtsSpinning * getDtsSpinning();
    }; 
#endif
