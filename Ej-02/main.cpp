#include <iostream>
#include "../Cola/Cola.h"
#include "../Cola/Pila.h"

using namespace std;

bool esPalindromo(string x) {
    Cola<char> cola;
    Pila<char> pila;
    long fin = x.length();
    for (int i = 0; i < fin; i++) {
        if ((x[i] >= 48 && x[i] <= 57) || (x[i] >= 65 && x[i] <= 90) || (x[i] >= 97 && x[i] <= 122)) {
            cola.encolar(x[i]);
            pila.push(x[i]);
        }
    }
    while (!cola.esVacia())
        if (cola.desencolar() != pila.pop())
            return 0;
    return 1;
}

int main() {
    string texto;
    cout << endl << "Ingrese texto" << endl;
    getline(cin, texto);
    if (esPalindromo(texto))
        cout << endl << "Es palindromo" << endl;
    else
        cout << endl << "No es palindromo" << endl;
    main();
    return 0;
}