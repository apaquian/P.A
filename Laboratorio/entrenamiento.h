#ifndef ENTRENAMIENTO_H
#define ENTRENAMIENTO_H
#include <iostream>
#include "clase.h"
#include "Data_Types/Tipos.h"
#include "Data_Types/dtEntrenamiento.h"
using namespace std;
class Entrenamiento : public Clase
{
    private:    
        bool rambla;
    public:
        int cupo();
        Entrenamiento(int id, string name, Turno turno, bool rambla);
        
        ~Entrenamiento();
        bool getRambla();
        void setRambla(bool);
        dtEntrenamiento * getDtEntrenamiento();
    };
#endif  

