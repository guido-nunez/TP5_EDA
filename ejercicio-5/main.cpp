#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Estructura para representar a una persona
struct Persona {
    string dni;
    char operacion; // 'D' para depositos, 'E' para extracciones, 'O' para otras operaciones
};

// Declaración de las colas para cada tipo de operacion
queue<Persona> colaDepositos;
queue<Persona> colaExtracciones;
queue<Persona> colaOtrasOperaciones;

// Funcion para encolar a una persona en la cola correspondiente segun la operacion
void encolarPersona(const Persona &persona) {
    switch (persona.operacion) {
        case 'D':
            colaDepositos.push(persona);
            break;
        case 'E':
            colaExtracciones.push(persona);
            break;
        case 'O':
            colaOtrasOperaciones.push(persona);
            break;
        default:
            cout << "Operacion desconocida!" << endl;
    }
}

// Funcion para atender a la primera persona en la cola correspondiente segun la operacion
void atender(char tipoOperacion) {
    switch (tipoOperacion) {
        case 'D':
            if (!colaDepositos.empty()) {
                cout << "Atendiendo a: " << colaDepositos.front().dni << " para Deposito" << endl;
                colaDepositos.pop();
            } else {
                cout << "No hay personas en la cola de Depositos" << endl;
            }
            break;
        case 'E':
            if (!colaExtracciones.empty()) {
                cout << "Atendiendo a: " << colaExtracciones.front().dni << " para Extraccion" << endl;
                colaExtracciones.pop();
            } else {
                cout << "No hay personas en la cola de Extracciones" << endl;
            }
            break;
        case 'O':
            if (!colaOtrasOperaciones.empty()) {
                cout << "Atendiendo a: " << colaOtrasOperaciones.front().dni << " para Otra Operacion" << endl;
                colaOtrasOperaciones.pop();
            } else {
                cout << "No hay personas en la cola de Otras Operaciones" << endl;
            }
            break;
        default:
            cout << "Operacion desconocida!" << endl;
    }
}

// Funcion para obtener el último DNI en la cola correspondiente
string obtenerUltimoDNI(char tipoOperacion) {
    switch (tipoOperacion) {
        case 'D':
            if (!colaDepositos.empty()) {
                return colaDepositos.back().dni;
            } else {
                return "No hay personas en la cola de Depositos";
            }
        case 'E':
            if (!colaExtracciones.empty()) {
                return colaExtracciones.back().dni;
            } else {
                return "No hay personas en la cola de Extracciones";
            }
        case 'O':
            if (!colaOtrasOperaciones.empty()) {
                return colaOtrasOperaciones.back().dni;
            } else {
                return "No hay personas en la cola de Otras Operaciones";
            }
        default:
            return "Operacion desconocida!";
    }
}

int main() {
    // simulacion de turno
    Persona p1 = {"3566677", 'D'};
    Persona p2 = {"44236581", 'E'};
    Persona p3 = {"25870410", 'O'};
    Persona p4 = {"28184893", 'D'};
    Persona p5 = {"6806292", 'O'};
    
    encolarPersona(p1);
    encolarPersona(p2);
    encolarPersona(p3);
    encolarPersona(p4);
    encolarPersona(p5);

    // Atender a las personas segun la cola
    atender('D');
    atender('E');
    atender('O');
    
    // Obtener el ultimo DNI en la cola de extracciones
    cout << "Ultimo DNI en la cola de Extracciones: " << obtenerUltimoDNI('E') << endl;

    return 0;
}

