#include "Lista.h"
#include <cassert>
#include <iostream>

//-------------------------------------------------------------------------------------------------------------------//

Lista::Lista(): _primero(nullptr), _tamanio(0){}

//-------------------------------------------------------------------------------------------------------------------//

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

//-------------------------------------------------------------------------------------------------------------------//

Lista::~Lista() {
    destruirNodos();
}

//-------------------------------------------------------------------------------------------------------------------//

void Lista:: destruirNodos () {

    if (_tamanio > 0) {
        Nodo *actual = _primero;

        while (_primero != nullptr) {
            _primero = actual->siguiente;
            delete (actual);
            actual = _primero;
            _tamanio --;
        }

    }

    _primero = nullptr;
}

//-------------------------------------------------------------------------------------------------------------------//

void Lista::copiarNodos(const Lista &o){

    if (o._tamanio > 0){
        Nodo* actualCopia = o._primero;

        for(int i = 1; i <= o._tamanio; i++){
            this->agregarAtras(actualCopia->valor);
            actualCopia = actualCopia->siguiente;
        }

        delete actualCopia;
    }
}


//-------------------------------------------------------------------------------------------------------------------//

Lista& Lista::operator=(const Lista& aCopiar) {

    this->destruirNodos();
    this->copiarNodos(aCopiar);

    return *this;
}

//-------------------------------------------------------------------------------------------------------------------//

void Lista::agregarAdelante(const int& elem) {

    Nodo* nuevoPrimero = new Nodo(nullptr, elem, _primero);
    Nodo* actualPrimero = _primero;

    if(_tamanio > 0){
        actualPrimero->anterior = nuevoPrimero;
    }

    this->_primero = nuevoPrimero;
    _tamanio ++;

}

//-------------------------------------------------------------------------------------------------------------------//

void Lista::agregarAtras(const int& elem) {

    Nodo *nuevo = new Nodo(nullptr, elem, nullptr);

    if (_tamanio > 0) {

        Nodo *actual = _primero;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        nuevo->anterior = actual;
        actual->siguiente = nuevo;

    } else {
        _primero = nuevo;
    }

    _tamanio++;

}

//-------------------------------------------------------------------------------------------------------------------//

void Lista::eliminar(Nat i) {

    Nodo* actual = _primero;

    for (i; i != 0; i--) {
        actual = actual -> siguiente;
    }

    if (actual -> anterior){
        actual -> anterior -> siguiente = actual -> siguiente;
    }else{
        this -> _primero = actual -> siguiente;
    }

    if (actual -> siguiente){
        actual -> siguiente -> anterior = actual -> anterior;
    }

    this -> _tamanio --;
    delete actual;
}

//-------------------------------------------------------------------------------------------------------------------//

int Lista::longitud() const {
    return _tamanio;
}

//-------------------------------------------------------------------------------------------------------------------//

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = _primero;

    for (i; i != 0; i--){
        actual = actual->siguiente;
    }

    return actual->valor;
}

//-------------------------------------------------------------------------------------------------------------------//

int& Lista::iesimo(Nat i) {

    Nodo* actual = _primero;

    for (i; i != 0; i--){
        actual = actual->siguiente;
    }

    return actual->valor;
}

//-------------------------------------------------------------------------------------------------------------------//

void Lista::mostrar(ostream& o) {

    Nodo* actual = _primero;

    o << "[";

    for (int i = this->_tamanio; i != 0; i--){

        /*if (actual->anterior == nullptr && actual->siguiente == nullptr){
            o << "[NULL, " << actual->valor << ", NULL]";
        }else{
            if(actual->anterior == nullptr){
                o << "[NULL, " << actual->valor << ", " << actual->siguiente->valor << "]";
            }else {
                if (actual->siguiente == nullptr) {
                    o  << "[" << actual->anterior->valor << ", " << actual->valor<< ", NULL]";
                } else {
                    o << "[" << actual->anterior->valor << ", " << actual->valor << ", " << actual->siguiente->valor << "]";
                }
            }
        }*/

        o << actual->valor;
        actual = actual->siguiente;

        if(actual != nullptr) {
            o << ", ";
        }
    }

    o << "]";
}

//-------------------------------------------------------------------------------------------------------------------//