#ifndef NODOPRIOR_H
#define NODOPRIOR_H

#include <iostream>

template<class T>

class NodoPrior {
private:
    T dato;
    NodoPrior<T> *next;
    int prioridad;

public:
    NodoPrior(T dato, int prioridad, NodoPrior<T> *next) : dato(dato), prioridad(prioridad), next(next) {}

    NodoPrior(T dato, int prioridad) : dato(dato), prioridad(prioridad) {
        this->next = NULL;
    }

    T getDato() const {
        return dato;
    }

    int getPrioridad() const {
        return prioridad;
    }

    void setDato(T dato) {
        NodoPrior::dato = dato;
    }

    void setPrioridad(int prioridad) {
        NodoPrior::prioridad = prioridad;
    }

    NodoPrior<T> *getNext() const {
        return next;
    }

    void setNext(NodoPrior<T> *next) {
        NodoPrior::next = next;
    }

};

#endif //NODOPRIOR_H