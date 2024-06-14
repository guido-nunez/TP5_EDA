#include <iostream>
#include <conio.h>
using namespace std;
const int N = 3;

/*
2. Se tienen pilaA, pilaB, pilaC con enteros, y los procedimientos o funciones son:

a. InvierteConAux, Dada una Pila A con números, una Pila B y una Pila C vacías, 
    pasar los elementos de A a B de manera que queden en el mismo orden que estaban en A. 
    (Se permite utilizar la pila C como auxiliar)
b. InvierteSinAux, que dada una PilaA, una variable X y una Pila Vacía B. Pasar los 
    elementos de pilaA a pilaB de manera tal que en pilaB queden en el mismo orden (original) en pilaA.
c. Dada una pila A con números, buscar si existe en A un entero “X”, y reemplazarlo otro “Y”
*/

struct pila
{
private:
  int tope = -1;
  int elem[N];

public:
  void push(int n)
  {
    if (!pilaLlena())
    {
      tope++;
      elem[tope] = n;
    }
    else
    {
      cout << "La pila esta llenisima!" << endl;
    }
  }

  int verTope()
  {
    if (!pilaVacia())
    {
      return elem[tope];
    }
    else
    {
      cout << "La pila esta vacia!" << endl;
      return -1;
    }
  }

  void pop()
  {
    if (!pilaVacia())
    {
      tope--;
    }
    else
    {
      cout << "La pila ya se encuentra vacia, no se puede eliminar nada mas" << endl;
    }
  }

  // método para verificar si la pila está vacía
  bool pilaVacia()
  {
    return tope < 0;
  }

  // método para verificar si la pila está llena
  bool pilaLlena()
  {
    return tope >= N - 1;
  }

  // método para obtener el valor del tope de la pila
  int getTope()
  {
    return tope;
  }

  // método para imprimir las tres pilas
  static void verPilas(pila &A, pila &B, pila &C)
  {
    for (int i = N - 1; i >= 0; i--)
    {
      cout << "[";
      if (i <= A.getTope())
        cout << A.elem[i];
      else
        cout << " ";
      cout << "][";
      if (i <= B.getTope())
        cout << B.elem[i];
      else
        cout << " ";
      cout << "][";
      if (i <= C.getTope())
        cout << C.elem[i];
      else
        cout << " ";
      cout << "]" << endl;
    }
  }

  // método para imprimir las dos pilas con un elemento adicional
  static void verPilas2(pila &A, pila &B, int &X)
  {
    for (int i = N - 1; i >= 0; i--)
    {
      cout << "[";
      if (i <= A.getTope())
        cout << A.elem[i];
      else
        cout << " ";
      if (i == 0)
      {
        cout << "][";
        if (X != -1 && i <= X)
          cout << X;
        else
          cout << " ";
        cout << "][";
      }
      else
      {
        cout << "]   [";
      }

      if (i <= B.getTope())
        cout << B.elem[i];
      else
        cout << " ";
      cout << "]" << endl;
    }
  }

  // método para imprimir las dos pilas con un elemento adicional
  static void verPilas3(pila &A, pila &aux)
  {
    for (int i = N - 1; i >= 0; i--)
    {
      cout << "[";
      if (i <= A.getTope())
        cout << A.elem[i];
      else
        cout << " ";
      cout << "][";
      if (i <= aux.getTope())
        cout << aux.elem[i];
      else
        cout << " ";
      cout << "]" << endl;
    }
  }

  // Vaciar la pila
  void vaciarPila()
  {
    while (!pilaVacia())
    {
      pop();
    }
  }
};

// ejercicio A
void InvierteConAux(pila &A, pila &B, pila &C)
{
  pila::verPilas(A, B, C);
  cout << endl;
  while (!A.pilaVacia())
  {
    int x = A.verTope();
    A.pop();
    C.push(x);
    pila::verPilas(A, B, C);
    cout << endl;
  }
  while (!C.pilaVacia())
  {
    int x = C.verTope();
    C.pop();
    B.push(x);
    pila::verPilas(A, B, C);
    cout << endl;
  }
}

// ejercicio B
void InvierteSinAux(pila &A, pila &B, int X)
{
  X = -1;
  pila::verPilas2(A, B, X);
  cout << endl;

  while (!A.pilaVacia() && !B.pilaLlena())
  {
    B.push(A.verTope());
    A.pop();
    pila::verPilas2(A, B, X);
    cout << endl;
  }

  X = B.verTope();
  B.pop();
  pila::verPilas2(A, B, X);
  cout << endl;

  while (!B.pilaVacia())
  {
    A.push(B.verTope());
    B.pop();
    pila::verPilas2(A, B, X);
    cout << endl;
  }

  B.push(X);
  X = -1;

  while (!A.pilaVacia() && !B.pilaLlena())
  {
    B.push(A.verTope());
    A.pop();
    pila::verPilas2(A, B, X);
    cout << endl;
  }

  X = B.verTope();
  B.pop();
  pila::verPilas2(A, B, X);
  cout << endl;

  while (!B.pilaVacia())
  {
    if (B.verTope() == X - 1)
    {
      B.push(X);
      break;
    }
    A.push(B.verTope());
    B.pop();
    pila::verPilas2(A, B, X);
    cout << endl;
  }

  B.push(A.verTope());
  A.pop();
  X = -1;

  pila::verPilas2(A, B, X);
  cout << endl;
}

// ejercicio C
void Reemplazar(pila &A, int X, int Y)
{
  pila aux;
  pila::verPilas3(A, aux);
  cout << endl;
  while (!A.pilaVacia())
  {
    int temp = A.verTope();
    A.pop();
    if (temp == X)
    {
      aux.push(Y);
    }
    else
    {
      aux.push(temp);
    }
    pila::verPilas3(A, aux);
    cout << endl;
  }
  while (!aux.pilaVacia())
  {
    int temp = aux.verTope();
    aux.pop();
    A.push(temp);
    pila::verPilas3(A, aux);
    cout << endl;
  }
}

int main()
{
  pila pilaA, pilaB, pilaC;
  int X = -1;

  pilaA.push(1);
  pilaA.push(2);
  pilaA.push(3);
  cout << "A):" << endl
       << endl;
  InvierteConAux(pilaA, pilaB, pilaC);
  cout << "-----------------" << endl
       << endl;

  pilaB.vaciarPila();

  pilaA.push(1);
  pilaA.push(2);
  pilaA.push(3);
  cout << "B):" << endl
       << endl;
  InvierteSinAux(pilaA, pilaB, X);
  cout << "-----------------" << endl
       << endl;

  pilaA.push(1);
  pilaA.push(2);
  pilaA.push(3);

  cout << "C):" << endl
       << endl;

  /*int Y;
    cout << "Ingresa el numero a buscar y reeplazar" << endl;
    cin >> X;
    cout << endl;
    cout << "Ingresa el numero por el cual quieres reemplazarlo si existe" << endl;
    cin >> Y;
    cout << endl; */

  cout << endl;
  Reemplazar(pilaA, 1, 4);
  cout << "-----------------" << endl
       << endl;

  getch();
  return 0;
}
