#ifndef SOCIO_H
#define SOCIO_H
using namespace std;

#include "Data_Types/dtSocio.h"
#include <iostream> 
class socio
{
    private:
       string CI;
        string name;
    public:
        socio(string CI, string name );
        ~socio();
        string getCi();
        string getName(); 
        void setCI(string);
        void setName(string);
 };

#endif
