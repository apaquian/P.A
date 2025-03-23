#include <iostream>
#include "clase.h"
#include "socio.h"
#include "inscripcion.h"
#include "entrenamiento.h"
#include "spinning.h"
#include "Data_Types/Fecha.h"
#include "Data_Types/dtSocio.h"
#include "Data_Types/dtClase.h"
#include "Data_Types/dtEntrenamiento.h"
#include "Data_Types/dtSpinning.h"
using namespace std;

/*

a) void agregarSocio(string ci, string nombre)
Crea un nuevo socio en el sistema. En caso de ya existir, levanta la excepción
std::invalid_argument.
b) void agregarClase(DtClase clase)
Crea una nueva clase en el sistema. En caso de ya existir, levanta una excepción
std::invalid_argument.
c) void agregarInscripcion(String ciSocio, int idClase,
Fecha fecha)
Crea una inscripción de un socio a una clase. La inscripción tiene lugar siempre y
cuando el socio y la clase existan, de lo contrario se levanta una excepción
std::invalid_argument. Si ya existe una inscripción de ese usuario para esa clase, o si
el cupo de esa clase ya fue alcanzado, también se levanta una excepción
std::invalid_argument.
d) void borrarInscripcion(string ciSocio, int idClase)
Borra la inscripción de un socio a una clase. Si no existe una inscripción de ese
usuario para esa clase, se levanta una excepción std::invalid_argument.
e) DtSocio ** obtenerInfoSociosPorClase (id idClase,
int & cantSocios)
Retorna un arreglo con los socios que están inscriptos a determinada clase. El largo
del arreglo de socios deberá ser cargado en el parámetro cantSocios.
f) DtClase obtenerClase(int idClase)
Retorna la información de la clase identificada por idClase.

*/

enum Turno {
    Maniana,
    Tarde,
    Noche
};

void agregarSocio(int ci, string nombre){
    socio ** socios = new socio *[50];
    int cantSocios = 0;
    for (int i = 0; i < cantSocios; i++){
        if (socios[i]->getCi() == ci){
            throw invalid_argument("El socio ya existe");
        }
    }
    socios[cantSocios++] = new socio(ci, nombre);
    cout << socios[0] << endl;
};
void agregarClase(dtClase clase);
void agregarInscripcion(string ciSocio, int idClase, dtFecha fecha);
void borrarInscripcion(string ciSocio, int idClase);
dtSocio ** obtenerInfoSociosPorClase (int idClase, int & cantSocios);
dtClase obtenerClase(int idClase);

int main(){
    
    int ci = 12345678;
    string nombre = "Juan";
    agregarSocio(ci, nombre);
    


    return 0; 
}