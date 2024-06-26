
/*
. En el menú principal, se cuenta con las siguientes pilas: Tubo1, Tubo2, Tubo3.
a. cargaTubo, que permita introducir datos en el cada uno de los tubos
b. pasarPelota, pasa todos los elementos de Tubo1 a Tubo2
c. hayColor, que recibe un color “rojo” y determina si está en la Tubo1, todos los
elementos deben quedar nuevamente en Tubo1
d. colorear, que tome pelotitas en Tubo1 y las coloca en Tubo2 solo rojas, y en Tubo3 las demás
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

struct Pila {
private:
    string Pelota[MAX];  // Arreglo para almacenar los elementos de la pila
    int tope;            // Índice del último elemento de la pila

public:
    // Constructor
    Pila() {
        tope = -1;
    }

    // Verifica si la pila está vacía
    bool PilaVacia() {
        return tope == -1;
    }

    // Verifica si la pila está llena
    bool PilaLlena() {
        return tope == MAX - 1;
    }

    // Añade un elemento a la pila
    void Apilar(string elem) {
        if (!PilaLlena()) {
            Pelota[++tope] = elem;
        } else {
            cout << "No se puede apilar. La pila está llena." << endl;
        }
    }

    // Elimina el último elemento de la pila
    void Desapilar() {
        if (!PilaVacia()) {
            tope--;
        } else {
            cout << "No se puede desapilar. La pila está vacía." << endl;
        }
    }

    // Devuelve el último elemento de la pila
    string VerTope() {
        if (!PilaVacia()) {
            return Pelota[tope];
        } else {
            cout << "La pila está vacía." << endl;
            return "";
        }
    }

    // Devuelve la cantidad de elementos en la pila
    int getCantidad() {
        return tope + 1;
    }
};

// Función para cargar un tubo con pelotas
void cargaTubo(Pila &tubo) {
    string color;
    cout << "Ingrese el color de la pelota: ";
    cin >> color;
    tubo.Apilar(color);
}

// Función para pasar todas las pelotas de Tubo1 a Tubo2
void pasarPelota(Pila &Tubo1, Pila &Tubo2) {
    while (!Tubo1.PilaVacia()) {
        Tubo2.Apilar(Tubo1.VerTope());
        Tubo1.Desapilar();
    }
}

// Función para verificar si un color específico está en Tubo1
bool hayColor(Pila &Tubo1, string color) {
    bool encontrado = false;
    Pila auxiliar;
    while (!Tubo1.PilaVacia()) {
        if (Tubo1.VerTope() == color) {
            encontrado = true;
        }
        auxiliar.Apilar(Tubo1.VerTope());
        Tubo1.Desapilar();
    }
    while (!auxiliar.PilaVacia()) {
        Tubo1.Apilar(auxiliar.VerTope());
        auxiliar.Desapilar();
    }
    return encontrado;
}

// Función para colorear las pelotas de Tubo1 a Tubo2 (rojas) y Tubo3 (otras)
void colorear(Pila &Tubo1, Pila &Tubo2, Pila &Tubo3) {
    while (!Tubo1.PilaVacia()) {
        if (Tubo1.VerTope() == "rojo") {
            Tubo2.Apilar(Tubo1.VerTope());
        } else {
            Tubo3.Apilar(Tubo1.VerTope());
        }
        Tubo1.Desapilar();
    }
}

int main() {
    Pila Tubo1, Tubo2, Tubo3;
    int op;
    string color;
    do {
        // system("cls");
        cout << "\nMENU DE OPCIONES--" << endl;
        cout << "1 - Cargar Tubo" << endl;
        cout << "2 - Pasar Pelota de Tubo1 a Tubo2" << endl;
        cout << "3 - Verificar si hay color en Tubo1" << endl;
        cout << "4 - Colorear Tubo1 (rojas a Tubo2, otras a Tubo3)" << endl;
        cout << "0 - SALIR" << endl;
        cin >> op;
        switch (op) {
            case 1:
                int tubo;
                cout << "Seleccione Tubo (1, 2, 3): ";
                cin >> tubo;
                if (tubo == 1) {
                    cargaTubo(Tubo1);
                } else if (tubo == 2) {
                    cargaTubo(Tubo2);
                } else if (tubo == 3) {
                    cargaTubo(Tubo3);
                } else {
                    cout << "Tubo no válido." << endl;
                }
                break;
            case 2:
                pasarPelota(Tubo1, Tubo2);
                break;
            case 3:
                cout << "Ingrese el color a buscar: ";
                cin >> color;
                if (hayColor(Tubo1, color)) {
                    cout << "El color " << color << " está en el Tubo1." << endl;
                } else {
                    cout << "El color " << color << " no está en el Tubo1." << endl;
                }
                break;
            case 4:
                colorear(Tubo1, Tubo2, Tubo3);
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
        // system("PAUSE");
    } while (op != 0);
    return 0;
}

















/*
#include <iostream>
using namespace std;
const int MAX=?;

struct cola{
  private:
	? Fila[MAX];  // struct de enteros
    ?
    ?
    ?

  public:
	bool ColaVacia (){  //EMPTY
		...
	}
	bool ColaLlena (){   //FULL
		...
	}
	void Encolar(int elem){  //ENQUEUE
		if (cant...){
		  //NUEVO ULTIMO
		  //hay +1 elemento
		}else
			cout<<"No se puede encolar"<<endl;
	}
	void Desencolar (){   //DEQUEUE
		if (cant...){
	     	// nuevo primero
		    // descuento
		}else
			cout<<"No se puede eliminar";
	}
	int verPrimero (){   // FRONT
		...
	}
	int verUltimo (){    // BACK
		...
	}
	int getCantidad(){
	    ...
	}
}cola;

int main(){
	cola c1, c2;
	int dato, op;
	do{
		//system("cls");
		cout<<"\nMENU DE OPCIONES--"<<endl;
		cout<<"1 -Insertar / Encolar"<<endl;
		cout<<"2 -Suprimir / Desencolar"<<endl;
		cout<<"3 -Ver el primero"<<endl;
		cout<<"4 -Ver el ultimo"<<endl;
		cout<<"5 -Cola Vacia?"<<endl;
		cout<<"6 -Cola Llena?"<<endl;
		cout<<"7 -VACIADO"<<endl;
		cout<<"8 -Cuantos elementos hay??"<<endl;
		cout<<"0 -SALIR"<<endl;
		cin>>op;
		switch(op){

			}
			system("PAUSE");
	}while(op!=0);
	return 0;
}
*/
