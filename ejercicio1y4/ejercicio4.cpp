/*
En el programa trabajamos ahora con objetos de la clase Queue,
a. Dada una fila A, Invertirla. Mostrar ambas filas. (usar fila auxiliar si lo necesita)
b. Utilizando las operaciones de pila y de Fila, COPIE el contenido de una pila P, a una
Fila C, de tal manera que el primer elemento de la Fila ser� el elemento �F� que se
encuentra en el fondo de la pila, el segundo de la Fila el que est� apilado sobre �F�,
y as� siguiendo. De esta forma el elemento del tope de la pila quedar� en el �ltimo
lugar de la Fila. (Para resolver este ejercicio, use pila auxiliar)
c. Ahora queremos buscar si el n�mero entero X determinar est� en la Fila A. La Fila A
deber� quedar en su estado original al finalizar el algoritmo.
d. Adem�s de la Fila A cree la fila B, vac�e la fila A y cargue A y B con elementos
ordenados, realice un algoritmo que inserte los elementos de la fila A y B en otra
fila C de manera tal que queden ordenados.
e. Dada una fila C que contiene elementos repetidos consecutivos. Formar otra con
los elementos de la fila dada eliminando los repetidos. */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 100;

struct Queue {
private:
    int items[MAX];
    int front, rear, count;

public:
    // Constructor
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Verifica si la cola est� vac�a
    bool ColaVacia() {
        return count == 0;
    }

    // Verifica si la cola est� llena
    bool ColaLlena() {
        return count == MAX;
    }

    // A�ade un elemento a la cola
    void Encolar(int elem) {
        if (!ColaLlena()) {
            rear = (rear + 1) % MAX;
            items[rear] = elem;
            count++;
        } else {
            cout << "No se puede encolar. La cola est� llena." << endl;
        }
    }

    // Elimina el primer elemento de la cola
    void Desencolar() {
        if (!ColaVacia()) {
            front = (front + 1) % MAX;
            count--;
        } else {
            cout << "No se puede desencolar. La cola est� vac�a." << endl;
        }
    }

    // Devuelve el primer elemento de la cola
    int VerPrimero() {
        if (!ColaVacia()) {
            return items[front];
        } else {
            cout << "La cola est� vac�a." << endl;
            return -1;
        }
    }

    // Devuelve la cantidad de elementos en la cola
    int getCantidad() {
        return count;
    }
};

void mostrarCola(Queue &cola) {
    Queue aux = cola;
    while (!aux.ColaVacia()) {
        cout << aux.VerPrimero() << " ";
        aux.Desencolar();
    }
    cout << endl;
}


void invertirFila(Queue &A) {
    stack<int> pilaAux;
    Queue aux = A; // Crear una copia para mostrar la fila original

    while (!A.ColaVacia()) {
        pilaAux.push(A.VerPrimero());
        A.Desencolar();
    }

    while (!pilaAux.empty()) {
        A.Encolar(pilaAux.top());
        pilaAux.pop();
    }

    // Mostrar ambas filas
    cout << "Fila Original: ";
    mostrarCola(aux);
    cout << "Fila Invertida: ";
    mostrarCola(A);
}

//copia el contenido de una pila
void copiarPilaAFila(stack<int> &P, Queue &C) {
    stack<int> pilaAux;

    //PASA los elementos
    while (!P.empty()) {
        pilaAux.push(P.top());
        P.pop();
    }

    while (!pilaAux.empty()) {
        C.Encolar(pilaAux.top());
        pilaAux.pop();
    }
}

bool buscarEnFila(Queue &A, int X) {
    bool encontrado = false;
    Queue aux;
    while (!A.ColaVacia()) {
        if (A.VerPrimero() == X) {
            encontrado = true;
        }
        aux.Encolar(A.VerPrimero());
        A.Desencolar();
    }
    while (!aux.ColaVacia()) {
        A.Encolar(aux.VerPrimero());
        aux.Desencolar();
    }
    return encontrado;
}


void fusionarFilasOrdenadas(Queue &A, Queue &B, Queue &C) {
    while (!A.ColaVacia() && !B.ColaVacia()) {
        if (A.VerPrimero() <= B.VerPrimero()) {
            C.Encolar(A.VerPrimero());
            A.Desencolar();
        } else {
            C.Encolar(B.VerPrimero());
            B.Desencolar();
        }
    }
    while (!A.ColaVacia()) {
        C.Encolar(A.VerPrimero());
        A.Desencolar();
    }
    while (!B.ColaVacia()) {
        C.Encolar(B.VerPrimero());
        B.Desencolar();
    }
}


void eliminarRepetidosConsecutivos(Queue &C) {
    if (C.ColaVacia()) return;

    Queue aux;


    int prev = C.VerPrimero();
    aux.Encolar(prev);

    C.Desencolar();

    while (!C.ColaVacia()) {
        int current = C.VerPrimero();
        if (current != prev) {
            aux.Encolar(current);
        }
        prev = current;
        C.Desencolar();
    }

    while (!aux.ColaVacia()) {
        C.Encolar(aux.VerPrimero());
        aux.Desencolar();
    }
}

int main() {
    Queue A, B, C;
    stack<int> P;
    int op, num;

    do {

        cout << "\nMENU DE OPCIONES--" << endl;

        cout << "1 - Cargar Cola" << endl;


        cout << "2 - Invertir Fila A" << endl;

        cout << "3 - Copiar Pila a Fila" << endl;
        cout << "4 - Buscar en Fila A" << endl;

        cout << "5 - Fusionar Filas Ordenadas" << endl;
        cout << "6 - Eliminar Repetidos Consecutivos en Fila C" << endl;

        cout << "0 - SALIR" << endl;

        cin >> op;
        switch (op) {
            case 1:
                cout << "Ingrese el numero para encolar: ";
                cin >> num;
                cout << "Seleccione Cola (1-A, 2-B, 3-C): ";
                cin >> op;
                if (op == 1) {
                    A.Encolar(num);
                } else if (op == 2) {
                    B.Encolar(num);
                } else if (op == 3) {
                    C.Encolar(num);
                } else {
                    cout << "Opcio no valida." << endl;
                }
                break;
            case 2:
                invertirFila(A);
                break;
            case 3:
                cout << "Ingrese los nuemeros para apilar (0 para terminar): ";
                while (true) {
                    cin >> num;
                    if (num == 0) break;


                    P.push(num);
                }


                copiarPilaAFila(P, C);
                break;
            case 4:
                cout << "Ingrese el n�mero a buscar en la fila A: ";

                cin >> num;
                
                
                if (buscarEnFila(A, num)) {
                
                
                    cout << "El n�mero " << num << " est� en la fila A." << endl;
                } else {
                
                    cout << "El n�mero " << num << " no est� en la fila A." << endl;
                }
                break;
            case 5:
                fusionarFilasOrdenadas(A, B, C);
                cout << "Fila fusionada: ";
                mostrarCola(C);
                break;
            case 6:
                eliminarRepetidosConsecutivos(C);
                cout << "Fila sin repetidos consecutivos: ";


                mostrarCola(C);
                break;
            case 0:
                
                cout << "Saliendo..." << endl;
                
                break;
            default:
                cout << "Opci�n no v�lida." << endl;
        }

    } while (op != 0);

    return 0;
}
