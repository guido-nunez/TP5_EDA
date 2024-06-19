#include <iostream>
#include <stack>
#include <string>
#include <conio.h>

using namespace std;

struct Auto {
    string placa;
    string propietario;
    int horaEntrada;

    Auto(string p, string prop, int hora) : placa(p), propietario(prop), horaEntrada(hora) {}
};

// Constantes
const int CAPACIDAD_MAXIMA = 10;

// Cocheras
stack<Auto> cochera1;
stack<Auto> cochera2;

// Función para estacionar un auto
void estacionarAuto(stack<Auto>& cochera, const string& placa, const string& propietario, int horaEntrada) {
    if (cochera.size() < CAPACIDAD_MAXIMA) {
        Auto nuevoAuto(placa, propietario, horaEntrada);
        cochera.push(nuevoAuto);
        cout << "Auto estacionado en cochera" << endl;
        cout << "Placa: " << nuevoAuto.placa << ", Propietario: " << nuevoAuto.propietario << ", Hora de Entrada: " << nuevoAuto.horaEntrada << endl;
    } else {
        cout << "La cochera está llena" << endl;
    }
    
    cout << " " << endl;
}

// Función para mostrar una cochera
void mostrarCochera(stack<Auto> cochera) {
    stack<Auto> temp;
    while (!cochera.empty()) {
        Auto a = cochera.top();
        cochera.pop();
        temp.push(a);
    }
    while (!temp.empty()) {
        Auto a = temp.top();
        temp.pop();
        cout << "Placa: " << a.placa << ", Propietario: " << a.propietario << ", Hora de Entrada: " << a.horaEntrada << endl;
    }
}

// Función para mostrar el estado de las cocheras
void mostrarCocheras() {
    cout << "Cochera1 (Orden de salida):" << endl;
    mostrarCochera(cochera1);
    
    cout << " " << endl;

    cout << "Cochera2 (Orden de salida):" << endl;
    mostrarCochera(cochera2);
}

int main(int argc, char** argv) {
    // Estacionar autos en cochera1
    estacionarAuto(cochera1, "ABC123", "Juan Perez", 10);
    estacionarAuto(cochera1, "DEF456", "Maria Lopez", 11);

    // Estacionar autos en cochera2
    estacionarAuto(cochera2, "GHI789", "Carlos Ruiz", 9);
    estacionarAuto(cochera2, "JKL012", "Ana Gomez", 10);

    // Mostrar el estado de las cocheras
    mostrarCocheras();

    getch();
    return 0;
}

