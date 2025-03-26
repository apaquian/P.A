#ifndef SPINNING_H
#define SPINNING_H
#include <iostream>
#include "clase.h"
#include "Data_Types/dtSpinning.h"
using namespace std;
class Spinning  : public Clase
{
    private:    
        int cantBicicletas;
    public:
        int cupo();
        Spinning(int id, string name, int turno, int cantBicicletas);
        ~Spinning();
        int getSpinning();
        void setSpinning(int);
        dtsSpinning * getDtsSpinning();
    }; 
#endif
