#include <iostream>
#include "../Cola/Cola.h"
#include "../Ej-03/ColaPrior.h"

using namespace std;

typedef struct {
    int codigo;
    float precio;
} producto;

ColaPrior<Cola<producto> *> fila;

int embarazadas = 0;

void cobrar();

Cola<producto> *ingresarClien();

int main() {
    int n = 0;
    cout << endl << "Seleccione una opcion:"
         << endl << " 1)Ingresar cliente en la cola"
         << endl << " 2)Ingresar cliente embarazada en la cola"
         << endl << " 3)Cobrar un cliente"
         << endl << " 4)Cobrar a todos los clientes"
         << endl << " 5)Salir" << endl;
    cin >> n;
    switch (n) {
        case 1: {
            Cola<producto> * cliente=ingresarClien();
            if(!cliente->esVacia())
            fila.encolar(cliente, 1);
            break;
        }
        case 2: {
            Cola<producto> * cliente=ingresarClien();
            if(!cliente->esVacia())
                fila.encolar(cliente, 0);
            break;
        }
        case 3: {
            if (!fila.esVacia()) {
                if (!fila.verPrioridad())
                    embarazadas++;
                cobrar();
            }
            cout << endl << "Cantidad de embarazadas: " << embarazadas << endl;
        }
            break;
        case 4: {
            while (!fila.esVacia()) {
                if (!fila.verPrioridad())
                    embarazadas++;
                cobrar();
            }
            cout << endl << "Cantidad de embarazadas: " << embarazadas << endl;
            break;
        }
        case 5: {
            return 1;
        }
        default: {
            cout << endl << "Opcion invalida" << endl;
            break;
        }
    }

    main();

    return 0;
}

Cola<producto> *ingresarClien() {
    int cod = 1;
    float precio;
    producto prod;
    auto cliente = new Cola<producto>();

    while (cod > 0) {
        cout << endl << " Ingrese codigo de producto (0 para terminar):" << endl;
        cin >> cod;
        if (cod > 0) {
            cout << endl << " Ingrese precio de producto:" << endl;
            cin >> precio;
            if (precio > 0) {
                prod.codigo = cod;
                prod.precio = precio;
                cliente->encolar(prod);
            } else {
                cout << endl << " Ingresar precio positivo" << endl;
            }
        }
    }
    return cliente;
}

void cobrar() {
    float precio = 0;
    int cantidad = 0;
    Cola<producto> *cliente = fila.desencolar();
    producto prod;

    while (!cliente->esVacia()) {
        prod = cliente->desencolar();

        cout << endl << " Codigo de producto: " << prod.codigo
             << endl << " Precio de producto: $" << prod.precio << endl;
        cantidad++;
        precio += prod.precio;
    }
        cout << endl << " TOTAL: $" << precio << endl;
    delete cliente;
}