#ifndef INC_04_COLA_COLAPRIOR_H
#define INC_04_COLA_COLAPRIOR_H

#include "NodoPrior.h"

template<class T>
class ColaPrior {
private:
    NodoPrior<T> *frente;
public:
    ColaPrior();

    ~ColaPrior();

    void encolar(T dato, int prioridad);

    T desencolar();

    bool esVacia();

    void vaciar();

    T verFrente();

    int verPrioridad();
};

template<class T>
ColaPrior<T>::ColaPrior() {
    frente = NULL;
}

template<class T>
ColaPrior<T>::~ColaPrior() {
    vaciar();
}

template<class T>
void ColaPrior<T>::encolar(T dato, int prioridad) {
    if (frente == NULL) {
        frente = new NodoPrior<T>(dato, prioridad);
    } else {
        NodoPrior<T> *aux = frente;
        if (frente->getPrioridad() > prioridad) {
            frente = new NodoPrior<T>(dato, prioridad, aux);
        } else {
            while (aux->getNext() != NULL && aux->getNext()->getPrioridad() <= prioridad)
                aux = aux->getNext();
            aux->setNext(new NodoPrior<T>(dato, prioridad, aux->getNext()));
        }
    }
}

template<class T>
T ColaPrior<T>::desencolar() {
    if (esVacia()) throw 1;
    T tmp;
    NodoPrior<T> *aux = frente;
    frente = frente->getNext();
    tmp = aux->getDato();
    delete aux;
    return tmp;
}

template<class T>
bool ColaPrior<T>::esVacia() {
    return frente == NULL;
}

template<class T>
void ColaPrior<T>::vaciar() {

    while (frente != NULL)
        desencolar();

}

template<class T>
T ColaPrior<T>::verFrente() {
    if (esVacia()) throw 1;
    return frente->getDato();
}

template<class T>
int ColaPrior<T>::verPrioridad() {
    if (esVacia()) throw 1;
    return frente->getPrioridad();
}


#endif //INC_04_COLA_COLAPRIOR_H
