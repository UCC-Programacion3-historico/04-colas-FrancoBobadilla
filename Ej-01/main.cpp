#include <iostream>
#include "../Cola/Cola.h"

using namespace std;

bool sonIguales(Cola<char> primera, Cola<char> segunda) {
    while (!segunda.esVacia() && !primera.esVacia())
        if (primera.desencolar() != segunda.desencolar())
            return 0;
    if (segunda.esVacia() && primera.esVacia())
        return 1;
    return 0;
}

int main() {
    Cola<char> a, b;
    char x;
    cout << endl << "Ingrese elementos de la primera cola ('$' para terminar):" << endl;
    x = NULL;
    while (x != '$') {
        cin >> x;
        if (x != '$')
            a.encolar(x);
    }
    cout << endl << "Ingrese elementos de la segunda cola ('$' para terminar):" << endl;
    x = NULL;
    while (x != '$') {
        cin >> x;
        if (x != '$')
            b.encolar(x);
    }
    if (sonIguales(a, b))
        cout << endl << "Son iguales" << endl;
    else
        cout << endl << "No son iguales" << endl;
    main();
    return 0;
}