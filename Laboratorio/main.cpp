#include <iostream>
#include "clase.h"
#include "socio.h"
#include "inscripcion.h"
#include "entrenamiento.h"
#include "spinning.h"  
#include "Data_Types/Tipos.h" 
#include "Data_Types/dtClase.h" 
#include "Data_Types/dtSpinning.h" 
#include "Data_Types/dtEntrenamiento.h" 

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
/*
void agregarClase(dtClase* clase) {
    cout << clase->getCantBicicletas() << endl;
    for (int i = 0; i < cantClases ; i++){
        if (clases[i]->getId() == clase->getId()){
            throw invalid_argument("La clase ya existe");
        }
    } 
    Clase *c;
    if (clase->getTipoClase() == SPINNING){
        c = new Spinning(clase->getId(), clase->getNombre(), clase->getTurno(), clase->getCantBicicletas());
    }
    else if (clase->getTipoClase() == ENTRENAMIENTO){
        c = new Entrenamiento(clase->getId(), clase->getNombre(), clase->getTurno(), clase->getEnRambla());
    }
    clases[cantClases] = c;
    cantClases++;
}  
*/
void agregarClase(dtClase* clase) {
    for (int i = 0; i < cantClases; i++) {
        if (clases[i]->getId() == clase->getId()) {
            throw std::invalid_argument("La clase ya existe");
        }
    }
    if (cantClases >= MAX_CLASES) {
        throw std::invalid_argument("No hay espacio para agregar más clases");
    }
    if (clase->getTipoClase() == SPINNING) {
        dtsSpinning* spinning = (dtsSpinning*) clase;
        clases[cantClases] = new Spinning(spinning->getId(), spinning->getNombre(), spinning->getTurno(), spinning->getCantBicicletas());
    } 
    else if (clase->getTipoClase() == ENTRENAMIENTO) {
        dtEntrenamiento* entrenamiento = (dtEntrenamiento*) clase;  // Casteamos a tipo dtEntrenamiento
        clases[cantClases] = new Entrenamiento(entrenamiento->getId(), entrenamiento->getNombre(), entrenamiento->getTurno(), entrenamiento->getEnRambla());
    }
    cantClases++;
    cout << "Clase agregada correctamente: " << clase->getNombre() << endl;
    if (clase->getTipoClase() == SPINNING) {
        dtsSpinning* spinning = (dtsSpinning*) clase; 
        cout << "Cantidad de bicicletas en la clase de Spinning: " << spinning->getCantBicicletas() << endl;
    }
}
int cantInscripcionesPorClase(int idClase) {
    int inscripciones = 0;
    for (int i = 0; i < cantInscripciones; i++) {
        if (Inscriptos[i] != nullptr && Inscriptos[i]->getClase()->getId() == idClase) {
            inscripciones++;
        }
    }
    return inscripciones;
}
void agregarInscripcion(string ciSocio, int idClase, dtFecha fecha) {
    socio* socioEncontrado = nullptr;
    Clase * claseEncontrada = nullptr;
    int i;
    // Buscar el socio por su CI
    for (int i = 0; i < cantSocios; i++) {
        if (socios[i] != nullptr && socios[i]->getCi() == ciSocio) {
            socioEncontrado = socios[i];
            break;
        }
    } 
    // Buscar la clase por su ID
    for (int i = 0; i < cantClases; i++) {
        if (clases[i] != nullptr && clases[i]->getId() == idClase) {
            claseEncontrada = clases[i];
            break;
        }  
    }
    if (claseEncontrada == nullptr || socioEncontrado == nullptr) {
        throw invalid_argument("El socio y la clase no existen.");   
    }
    for (i = 0; i < claseEncontrada->cupo(); i++)
    {
        if (Inscriptos[i] != nullptr && Inscriptos[i]->getClase()->getId() == idClase && Inscriptos[i]->getSocios()->getCi() == ciSocio) {
            throw invalid_argument("El socio ya está inscripto en esta clase.");
        }
        if (Inscriptos[i] == nullptr)
        {
            break;
        }
        
    }
    int cupoRestante = claseEncontrada->cupo() - cantInscripcionesPorClase(idClase);
    if (cupoRestante > 0) {    
        Inscripcion * nuevaInscripcion = new Inscripcion(idClase , claseEncontrada->getName(), claseEncontrada->getTurno(), socioEncontrado, claseEncontrada, &fecha);
        Inscriptos[cantInscripciones] = nuevaInscripcion;
        cantInscripciones++;
        cout << cupoRestante << endl;
    } else {
        throw invalid_argument("No hay cupo disponible para esta clase.");
    }
    cout << "Cupo restante: " << claseEncontrada->cupo() - cantInscripcionesPorClase(idClase) << endl;
}
void borrarInscripcion(string ciSocio, int idClase) {
    socio* socioEncontrado = nullptr;
    Clase* claseEncontrada = nullptr;
    Inscripcion* inscripcionEncontrada = nullptr;

    // Buscar el socio por su CI
    for (int i = 0; i < cantSocios; i++) {
        if (socios[i] != nullptr && socios[i]->getCi() == ciSocio) {
            socioEncontrado = socios[i];
            break;
        }
    }

    // Buscar la clase por su ID
    for (int i = 0; i < cantClases; i++) {
        if (clases[i] != nullptr && clases[i]->getId() == idClase) {
            claseEncontrada = clases[i];
            break;
        }
    }

    if (claseEncontrada == nullptr || socioEncontrado == nullptr) {
        throw invalid_argument("El socio o la clase no existen.");
    }

    // Buscar la inscripción del socio en la clase
    for (int i = 0; i < cantInscripciones; i++) {
        if (Inscriptos[i] != nullptr && Inscriptos[i]->getClase()->getId() == idClase && Inscriptos[i]->getSocios()->getCi() == ciSocio) {
            inscripcionEncontrada = Inscriptos[i];
            break;
        }
    }

    if (inscripcionEncontrada == nullptr) {
        throw invalid_argument("No existe una inscripción para este socio en esta clase.");
    }

    // Eliminar la inscripción
    delete inscripcionEncontrada;

    // Desplazar las inscripciones posteriores
    for (int i = 0; i < cantInscripciones - 1; i++) {
        if (Inscriptos[i] == inscripcionEncontrada) {
            for (int j = i; j < cantInscripciones - 1; j++) {
                Inscriptos[j] = Inscriptos[j + 1];
            }
            Inscriptos[cantInscripciones - 1] = nullptr;
            break;
        }
    }

    // Reducir el contador de inscripciones
    cantInscripciones--;

    cout << "Inscripción borrada correctamente." << endl;
}
int main() {
    agregarSocio("12345678", "Juan Perez");
    agregarSocio("87654321", "Maria Lopez");
    agregarClase(new dtsSpinning(1, "Spinning", Manana, SPINNING, 50));
    agregarInscripcion("12345678", 1, dtFecha(2023, 10, 15));
    agregarInscripcion("87654321", 1, dtFecha(2023, 10, 15));
    cout << "hola" << cantInscripcionesPorClase(1);
    borrarInscripcion("12345678", 1);
    cout << "adios" << cantInscripcionesPorClase(1);
    
    /*
    agregarSocio("12345678", "Juan Perez");
    agregarSocio("87654321", "Maria Lopez");

    dtClase* clase1 = new dtsSpinning(1, "Spinning", Manana, SPINNING, 50);
    agregarClase(clase1);
    agregarInscripcion("12345678", 1, dtFecha(2023, 10, 15));   
    
    // Ejemplo de uso de las funciones
    try {
        
    dtFecha fecha(2023, 10, 15);
    agregarInscripcion("12345678", 1, fecha);
    for (int i = 0; i < cantSocios; i++) {
        cout << "Socio: " << socios[i]->getName() << " (CI: " << socios[i]->getCi() << ")" << endl;
    }
    for (int i = 0; i < cantClases; i++) {
        cout << "Clase: " << clases[i]->getName() << " (ID: " << clases[i]->getId() << ")" << endl;
    }
    cout << "Inscripciones: "<< cantInscripciones << endl;
    for (int i = 0; i < cantInscripciones; i++) {  
        cout << "Inscripcion: " << Inscriptos[i]->getSocios()->getName() << " a la clase " << Inscriptos[i]->getClase()->getName() << endl;
    }
} catch (const std::invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
}
*/
    return 0;
}