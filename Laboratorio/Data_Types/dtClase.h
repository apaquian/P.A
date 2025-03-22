#ifndef DTCLASE_H
#define DTCLASE_H
#include <iostream>
using namespace std;

class dtClase 
{
    private:
        int id;
        string name;
        int turno;
    public:
        dtClase(int, string, int);
        int getId();
        string getName();
        int getTurno();
};
#endif
