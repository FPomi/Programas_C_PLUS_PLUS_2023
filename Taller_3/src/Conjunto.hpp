//--------------------------------------------------------------------------------------------------------------------//

template <class T>
Conjunto<T>::Conjunto() : _raiz(nullptr), _cardinal(0) {
}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
Conjunto<T>::~Conjunto() {

    while (this->_raiz) {
        remover(this->_raiz->valor);
    }
}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {

    bool respuesta = false;

    if (this->_cardinal >= 1){

        Nodo* actual = this->_raiz;

        while  ((actual->valor != clave) &&
               ((clave > actual->valor && actual->der)  ||
               (clave < actual->valor && actual->izq))  ){

            if (clave > actual->valor){
                actual = actual->der;
            }else{
                actual = actual->izq;
            }
        }

        if (actual->valor == clave){
            respuesta = true;
        }

    }

    return respuesta;
}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
void Conjunto<T>::insertar(const T& clave) {

    if (!(pertenece(clave))){

        Nodo* nuevo_Nodo = new Nodo (clave);

        if (this->_cardinal < 1){

            this->_raiz = nuevo_Nodo;

        }else{

            Nodo* actual = this->_raiz;

            while (((clave > actual->valor) && (actual->der)) ||
                   ((clave < actual->valor) && (actual->izq)) ){

                if (clave > actual->valor){
                    actual = actual->der;
                }else{
                    actual = actual->izq;
                }
            }

            if (clave > actual->valor){
                actual->der = nuevo_Nodo;
            }else{
                actual->izq = nuevo_Nodo;
            }

        }

        this->_cardinal ++;
    }

}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
void Conjunto<T>::remover(const T& clave) {

    if (pertenece(clave)){

        Nodo* actual = this->_raiz;
        Nodo* previo = this->_raiz;

        //BUSCA EL VALOR A ELIMINAR
        while (actual->valor != clave){

            previo = actual;

            if (clave > actual->valor){
                actual = actual->der;
            }else{
                actual = actual->izq;
            }
        }

        //SI TIENE 2 HIJOS
        if (actual->der && actual->izq){

            Nodo* auxiliar = actual->der;
            Nodo* previo_auxiliar = auxiliar;

            while (auxiliar->izq) {
                previo_auxiliar = auxiliar;
                auxiliar = auxiliar->izq;
            }

            previo_auxiliar->izq = auxiliar->der;
            auxiliar->izq = actual->izq;

            if (actual->der != auxiliar){
                auxiliar->der = actual->der;
            }

            if (actual == this->_raiz){
                this->_raiz = auxiliar;
            }else{
                if (previo->izq == actual){
                    previo->izq = auxiliar;
                }else{
                    previo->der = auxiliar;
                }
            }

        }else{
            //SI SOLO TINE UN HIJO
            if (actual->der || actual->izq) {

                //SI SOLO TIENE HIJO MENOR
                if (actual->izq) {
                    if (actual == this->_raiz) {
                        this->_raiz = actual->izq;
                    } else {
                        if (previo->izq == actual) {
                            previo->izq = actual->izq;
                        } else {
                            previo->der = actual->izq;
                        }
                    }
                }

                //SI SOLO TIENE HIJO MAYOR
                if (actual->der) {
                    if (actual == this->_raiz) {
                        this->_raiz = actual->der;
                    } else {
                        if (previo->izq == actual) {
                            previo->izq = actual->der;
                        } else {
                            previo->der = actual->der;
                        }
                    }
                }

                //SI NO TIENE HIJO
            }else{

                if (actual == this->_raiz){
                    this->_raiz = nullptr;
                }else {
                    if (previo->izq == actual) {
                        previo->izq = nullptr;
                    } else {
                        previo->der = nullptr;
                    }
                }
            }
        }

        actual->izq = nullptr;
        actual->der = nullptr;

        delete (actual);
        this->_cardinal--;
    }

}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {

    Nodo* actual = this->_raiz;
    Nodo* siguiente = this->_raiz;

    while (actual->valor != clave){

        if (clave > actual->valor){
            actual = actual->der;
        }else{
            actual = actual->izq;
        }

    }

    if (actual->der) {

        siguiente = actual->der;

        while (siguiente->izq) {
            siguiente = siguiente->izq;
        }

    }else{

        while ((siguiente->izq != actual) && (siguiente->der != actual))  {

            if (clave > siguiente->valor) {
                siguiente = siguiente->der;
            } else {
                siguiente = siguiente->izq;
            }

        }

        if (siguiente->der == actual){
            siguiente = this->_raiz;
        }

    }

    return (siguiente->valor);

}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
const T& Conjunto<T>::minimo() const {

    Nodo* actual = this->_raiz;

    while (actual->izq){
            actual = actual->izq;
        }

    return actual->valor;

}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
const T& Conjunto<T>::maximo() const {

    Nodo* actual = this->_raiz;

    while (actual->der){
        actual = actual->der;
    }

    return actual->valor;
}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

//--------------------------------------------------------------------------------------------------------------------//

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

//--------------------------------------------------------------------------------------------------------------------//

