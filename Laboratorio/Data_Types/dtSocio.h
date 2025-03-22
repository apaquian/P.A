#ifndef DTSOCIO_H
#define DTSOCIO_H
#include <iostream>
using namespace std;

class dtSocio 
{
    private:
        int Ci;
        string name;
    public:
        dtSocio(int, string);
        int getCi();
        string getName();
};
#endif