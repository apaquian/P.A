#ifndef DIRECCION_H
#define DIRECCION_H

#include <iostream>
using namespace std;

class Direccion {
    private:
        int CP;
        string calle;
        int numero;
    public:
        Direccion();
        Direccion(int, string, int);
        int getCP();
        string getCalle();
        int getNumero();
};

#endif
