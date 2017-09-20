#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

template<class T>
class Pila {
private:
    Nodo<T> *inicio;
public:
    Pila();

    ~Pila();

    void push(T dato);

    T pop();

    bool esVacia();

    T peek();

    bool insertAfter(T newDato, int n, T oldDato);
};


template<class T>
Pila<T>::Pila() {
    inicio = NULL;
}


template<class T>
Pila<T>::~Pila() {
    while (!esVacia())pop();
}


template<class T>
void Pila<T>::push(T dato) {
    Nodo<T> *aux = new Nodo<T>(dato, inicio);
    inicio = aux;
}


template<class T>
T Pila<T>::pop() {
    if (inicio == NULL) throw 1;
    T dato = inicio->getDato();
    Nodo<T> *aux = inicio;
    inicio = inicio->getNext();
    delete aux;
    return dato;
}


template<class T>
bool Pila<T>::esVacia() {
    return inicio == NULL;
}


template<class T>
T Pila<T>::peek() {
    if (inicio == NULL) throw 1;
    return inicio->getDato();
}

template<class T>
bool Pila<T>::insertAfter(T newValue, int n, T oldValue) {
    if (n == 0)push(newValue);
    Nodo<T> *aux = inicio;
    while (aux != NULL) {
        if (aux->getDato() == oldValue)n--;
        if (n == 0) {
            aux->setNext(new Nodo<T>(newValue, aux->getNext()));
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}


#endif //PILA_H