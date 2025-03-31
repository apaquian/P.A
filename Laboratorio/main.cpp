#include <iostream>
#include "clase.h"
#include "socio.h"
#include "inscripcion.h"
#include "entrenamiento.h"
#include "spinning.h"  
#include "Data_Types/Tipos.h" 
#include "Data_Types/dtClase.h" 

using namespace std;


Inscripcion ** Inscriptos = new Inscripcion *[MAX_INSCRIPCIONES] ;
socio* socios[MAX_SOCIOS] = {nullptr};  
Clase* clases[MAX_CLASES] = {nullptr};  



int cantClases = 0;
int cantInscripciones = 0;
int cantSocios = 0;

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


void agregarSocio(string ci, string nombre){
      
    for (int i = 0; i < cantSocios ; i++){
         if (socios[i]->getCi() == ci){
            
            throw invalid_argument("El socio ya existe");
        }
    }
    if (cantSocios < MAX_SOCIOS){
        socio *s = new socio(ci, nombre);
        socios[cantSocios] = s;
        cantSocios++;
    }else{
        cout << "No hay mas espacio para socios" << endl;
    }  
}

 void agregarClase(dtClase clase){
    for (int i = 0; i < cantClases ; i++){
        if (clases[i]->getId() == clase.getId()){
            throw invalid_argument("La clase ya existe");
        }
    } 
    Clase *c;
    if (clase.getTipoClase() == SPINNING){
        c = new Spinning(clase.getId(), clase.getNombre(), clase.getTurno(), clase.getCantBicicletas());
    }
    else if (clase.getTipoClase() == ENTRENAMIENTO){
        c = new Entrenamiento(clase.getId(), clase.getNombre(), clase.getTurno(), clase.getEnRambla());
    }
    
    clases[cantClases] = c;
    cantClases++;


    }  

void agregarInscripcion(string ciSocio, int idClase, dtFecha fecha) {
    socio* socioEncontrado = nullptr;
    Clase * claseEncontrada = nullptr;

    // Buscar el socio por su CI
    for (int i = 0; i < cantSocios; i++) {
        if (socios[i] != nullptr && socios[i]->getCi() == ciSocio) {
            socioEncontrado = socios[i];
            break;
        }
    } 
    for (int i = 0; i < cantClases; i++) {
        cout << "Clase: " << clases[i]->getName() << " (ID: " << clases[i]->getId() << ")" << endl;
    }

    // Buscar la clase por su ID
    for (int i = 0; i < cantClases; i++) {
        if (clases[i] != nullptr && clases[i]->getId() == idClase) {
            claseEncontrada = clases[i];
         
            break;
        }  
  
    }
 
    Inscripcion * nuevaInscripcion = new Inscripcion(idClase , claseEncontrada->getName(), claseEncontrada->getTurno(), socioEncontrado, claseEncontrada, &fecha);
     Inscriptos[cantInscripciones] = nuevaInscripcion;
    cantInscripciones++;
    }
 

 /* 
    void borrarInscripcion(string ciSocio, int idClase) {
        bool inscripcionEncontrada = false;

        for (int i = 0; i < cantInscripciones; i++) {
            if (Inscriptos[i] != nullptr &&
                Inscriptos[i]->getSocios()->getCi() == ciSocio &&
                Inscriptos[i]->getClase()->getId() == idClase) {
                
                delete Inscriptos[i];
                Inscriptos[i] = nullptr;
                inscripcionEncontrada = true;
                break; 
            }
        }

        if (!inscripcionEncontrada) {
            throw invalid_argument("No existe una inscripción de ese socio para esa clase.");
        }
    }*/
 
// dtSocio ** obtenerInfoSociosPorClase (int idClase, int & cantSocios);
// dtClase obtenerClase(int idClase);
int main() {
   
    // Ejemplo de uso de las funciones
    try {
        agregarSocio("12345678", "Juan Perez");
        agregarSocio("87654321", "Maria Lopez");

        dtClase clase1(1, "Spinning", Manana, SPINNING);
        agregarClase(clase1);

        dtClase clase2(2, "Entrenamiento", Tarde, ENTRENAMIENTO);
        agregarClase(clase2);

        dtFecha fecha(2023, 10, 15);
        agregarInscripcion("12345678", 1, fecha);
        agregarInscripcion("87654321", 2, fecha);

    } catch (const std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    // Imprimir los socios y clases para verificar que se hayan agregado correctamente
    for (int i = 0; i < cantSocios; i++) {
        cout << "Socio: " << socios[i]->getName() << " (CI: " << socios[i]->getCi() << ")" << endl;
    }
    for (int i = 0; i < cantClases; i++) {
        cout << "Clase: " << clases[i]->getName() << " (ID: " << clases[i]->getId() << ")" << endl;
    }
    cout << "Inscripciones: "<< cantInscripciones << endl;
    for (int i = 0; i < cantInscripciones; i++) {
       

        cout << "Inscripcion: " << Inscriptos[i]->getSocios()->getName() << " a la clase " << Inscriptos[i]->getClase()->getName() << Inscriptos[i]->getFecha()->getAnio()<< endl;
    }
    



    return 0;
}