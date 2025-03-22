#ifndef CLASE_H
#define CLASE_H
#include <iostream>
using namespace std;

class Clase 
{
    private:
        int id;
        string name;
        int turno;
    public:
        virtual int cupo() = 0;    
        Clase(int, string, int);
        int getId();
        string getName();
        int getTurno();
        void setId();
        void setName();
        void setTurno();
};
#endif
