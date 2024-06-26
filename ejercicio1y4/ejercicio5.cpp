#include <iostream>
#include <cstring>
/*
Aquí tienes un programa en C++ que permite ingresar dos frases por teclado, luego determina si las primeras cinco letras
 coinciden utilizando la función strncasecmp, y luego verifica si ambas frases contienen la subcadena
 "la" utilizando la función strstr:
 EJemplo: “La Vida es Bella” y “la VIRTUD de los grandes” */

int main() {
    const int MAX_LENGTH = 100;
    char frase1[MAX_LENGTH];
    char frase2[MAX_LENGTH];


    std::cout << "Ingrese la primera frase: ";
    std::cin.getline(frase1, MAX_LENGTH);

    std::cout << "Ingrese la segunda frase: ";
    std::cin.getline(frase2, MAX_LENGTH);


    if (strncasecmp(frase1, frase2, 5) == 0) {
        std::cout << "Las primeras cinco letras de las frases coinciden." << std::endl;
    } else {
        std::cout << "Las primeras cinco letras de las frases no coinciden." << std::endl;
    }


    char* subcadena1 = strstr(frase1, "la");
    char* subcadena2 = strstr(frase2, "la");

    if (subcadena1 != nullptr && subcadena2 != nullptr) {
        std::cout << "Ambas frases contienen la subcadena \"la\"." << std::endl;
    } else if (subcadena1 != nullptr || subcadena2 != nullptr) {
        std::cout << "Solo una de las frases contiene la subcadena \"la\"." << std::endl;
    } else {
        std::cout << "Ninguna de las frases contiene la subcadena \"la\"." << std::endl;
    }

    return 0;
}

