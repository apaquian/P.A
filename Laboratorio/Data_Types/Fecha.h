#ifndef FECHA_H
#define FECHA_H
#include <iostream>
using namespace std;

class dtFecha 
{
    private:
        int Dia;
        int Mes;
        int Anio;
    public:
        dtFecha(int, int, int);
        int getDia();
        int getMes();
        int getAnio();
};
#endif
