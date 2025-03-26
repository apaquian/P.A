#ifndef SOCIO_H
#define SOCIO_H
using namespace std;

#include "Data_Types/dtSocio.h"
#include <iostream> 
class socio
{
    private:
        int CI;
        string name;
    public:
        socio(int CI, string name );
        ~socio();
        int getCi();
        string getName();
        void setId(int);
        void setName(string);
 };

#endif
