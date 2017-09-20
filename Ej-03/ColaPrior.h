#ifndef INC_04_COLA_COLAPRIOR_H
#define INC_04_COLA_COLAPRIOR_H

#include "NodoPrior.h"

template<class T>
class Cola {
private:
    NodoPrior<T> *frente;
public:
    Cola();

    ~Cola();

    void encolar(T dato, int prioridad);

    T desencolar();

    bool esVacia();

    void vaciar();

    T verFrente();
};

template<class T>
Cola<T>::Cola() {
    frente = NULL;
}

template<class T>
Cola<T>::~Cola() {
    vaciar();
}

template<class T>
void Cola<T>::encolar(T dato, int prioridad) {
    if (frente == NULL) {
        frente = new NodoPrior<T>(dato, prioridad);
    } else {
        NodoPrior<T> *aux = frente;
        if (frente->getPrioridad() > prioridad) {
            frente = new NodoPrior(dato, prioridad, aux);
        } else {
            while (aux->getNext() != NULL && aux->getNext()->getPrioridad() <= prioridad)
                aux = aux->getNext();
            aux->setNext(new NodoPrior<T>(dato, prioridad, aux->getNext()));
        }
    }
}

template<class T>
T Cola<T>::desencolar() {
    if (esVacia()) throw 1;
    T tmp;
    NodoPrior<T> *aux = frente;
    frente = frente->getNext();
    tmp = aux->getDato();
    delete aux;
    return tmp;
}

template<class T>
bool Cola<T>::esVacia() {
    return frente == NULL;
}

template<class T>
void Cola<T>::vaciar() {

    while (frente != NULL)
        desencolar();

}

template<class T>
T Cola<T>::verFrente() {
    if (esVacia()) throw 1;
    return frente->getDato();
}


#endif //INC_04_COLA_COLAPRIOR_H
