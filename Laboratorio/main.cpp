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


void agregarInscripcion( string ciSocio , int idClase ,  dtFecha fecha ){
    socio *socioInscribir = nullptr;
    Clase *claseInscribir = nullptr;
    Inscripcion *inscripcionInscribir = nullptr;  
    bool inscripcionExistente = false;
    bool cupoAlcanzado = false;
    for (int i = 0; i < cantSocios ; i++){
        if (socios[i]->getCi() == ciSocio){
            socioInscribir = socios[i];
            break;
        }
    }
    for (int i = 0; i < cantClases ; i++){
        if (clases[i]->getId() == idClase){
            claseInscribir = clases[i];
            break;
        }
    }
 
    inscripcionInscribir = new Inscripcion(idClase, claseInscribir->getName(), claseInscribir->getTurno(), socioInscribir, claseInscribir, &fecha);
    Inscriptos[cantInscripciones] = inscripcionInscribir;
    cantInscripciones++;
    }
void borrarInscripcion(string cisocio , int idClase){
        Clase *ClaseSocio = nullptr;

    for (int i = 0; i < cantClases ; i++){
        if (clases[i]->getId() == idClase){
            ClaseSocio = clases[i];
            break;
        }    
    } 
    cout << "ClaseSocio: " << ClaseSocio->getName() << endl;
    for (int j = 0; j <  cantInscripciones ; j++)
        { 
            cout << "Inscriptos[j]->getClase(): " << Inscriptos[j]->getClase()->getName() << endl;
            cout << "Inscriptos[j]->getSocios()->getCi(): " << Inscriptos[j]->getSocios()->getCi() << endl;
            if (Inscriptos[j]->getClase() == ClaseSocio && Inscriptos[j]->getSocios()->getCi() == cisocio){
            cout << "Inscriptos[j]->getSocios()->getCi(): " << Inscriptos[j]->getSocios()->getCi() << endl;
                delete Inscriptos[j];
                Inscriptos[j] = nullptr;
                cantInscripciones--;
                break;
 } 
}
 
}  

 
// dtSocio ** obtenerInfoSociosPorClase (int idClase, int & cantSocios);
// dtClase obtenerClase(int idClase);
int main() {

 
    try {
          
        agregarSocio("67890", "Maria Lopez");
     
        // Intentar agregar un socio existente
        try {
            agregarSocio("12345", "Juan Perez");
        } catch (const invalid_argument &e) {
            cout << "Excepción capturada: " << e.what() << endl;
        }

        try {
            agregarClase(dtClase(1, "Spinning", Manana, SPINNING));
        } catch (const invalid_argument &e) {
            cout << "Excepción capturada: " << e.what() << endl;
        }

        cout << "Pruebas completadas exitosamente." << endl;
    } catch (const exception &e) {
        cout << "Error inesperado: " << e.what() << endl;
    }
    
    // Agregar Inscripcion 
    cout << "Pruebas completadas exitosamente.2" << endl;

    try {
        agregarInscripcion("67890", 1, dtFecha(1, 1, 2021));
    } catch (const invalid_argument &e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }        cout << "Pruebas completadas exitosamente.3" << endl;

     
    try {
        agregarInscripcion("12345", 1, dtFecha(1, 1, 2021));
    } catch (const invalid_argument &e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }        cout << "Pruebas completadas exitosamente.7" << endl;

    // Imprimir socios existentes
    cout << "Socios existentes:" << endl;
    for (int i = 0; i < cantSocios; i++) {
        if (socios[i] != nullptr) {
            cout << "CI: " << socios[i]->getCi() << ", Nombre: " << socios[i]->getName() << endl;
        }
    }

    // Imprimir clases existentes
    cout << "Clases existentes:" << endl;
    for (int i = 0; i < cantClases; i++) {
        if (clases[i] != nullptr) {
            cout << "ID: " << clases[i]->getId() << ", Nombre: " << clases[i]->getName() 
                 << ", Turno: " << clases[i]->getTurno() << endl;
        }
    }
  
    // Imprimir inscripciones existentes
    cout << "Inscripciones existentes:" << endl;
    for (int i = 0; i < cantInscripciones; i++) {
        if (Inscriptos[i] != nullptr) {
            cout << "ID Clase: " << Inscriptos[i]->getClase()->getId() << ", Nombre Clase: " << Inscriptos[i]->getClase()->getName() 
                 << ", CI Socio: " << Inscriptos[i]->getSocios()->getCi() << ", Nombre Socio: " << Inscriptos[i]->getSocios()->getName() << endl;
        }
    }
  // Borrar Inscripcion
    cout << "Pruebas completadas exitosamente.4" << endl;

    try {
        borrarInscripcion("67890", 1);
    } catch (const invalid_argument &e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }
    cout << "Pruebas completadas exitosamente.5" << endl;

    // Imprimir inscripciones existentes
    cout << "Inscripciones existentes:" << endl;

    for (int i = 0; i < cantInscripciones; i++) {
        if (Inscriptos[i] != nullptr) {
            cout << "ID Clase: " << Inscriptos[i]->getClase()->getId() << ", Nombre Clase: " << Inscriptos[i]->getClase()->getName() 
                 << ", CI Socio: " << Inscriptos[i]->getSocios()->getCi() << ", Nombre Socio: " << Inscriptos[i]->getSocios()->getName() << endl;
        }
    } 



    return 0;
}