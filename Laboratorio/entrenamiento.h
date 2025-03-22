#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#include <iostream>
#include "clase.h"
using namespace std;
class Entrenamiento : public Clase
{
    private:    
        bool rambla;
    public:
        int cupo();
        Entrenamiento(int id, string name, int turno, bool rambla);
        ~Entrenamiento();
        bool getRambla();
        void setRambla(bool);
    };
#endif

