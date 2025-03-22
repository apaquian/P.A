#include "Fecha.h"

dtFecha::dtFecha(int d, int m, int a) {
    this->Dia = d;
    this->Mes = m;
    this->Anio = a;
}
int dtFecha::getDia(){
    return this->Dia;
}
int dtFecha::getMes(){
    return this->Mes;
}
int dtFecha::getAnio(){
    return this->Anio;
}