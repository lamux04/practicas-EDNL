#ifndef ARBOL_BINARIO_CELDAS_ENLAZADAS
#define ARBOL_BINARIO_CELDAS_ENLAZADAS

#include <cassert>

template <typename T>
class AbinEnla
{
    struct celda;

public:
    typedef celda *nodo;
    static const nodo NODO_NULO;    // Propiedad de la clase
    AbinEnla();
    void insertarRaiz(const T &e);
    void insertarHijoIzqdo(nodo n, const T &e);
    void insertarHijoDrcho(nodo n, const T &e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const T &elemento(nodo n) const;
    T &elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    AbinEnla(const AbinEnla<T> &A);
    AbinEnla<T> &operator=(const AbinEnla<T> &A);
    ~AbinEnla();

private:
    struct celda
    {
        T elto;
        nodo padre, hizq, hder;
        celda(const T &x = T(), nodo p = NODO_NULO) : elto(x), padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
    };

    nodo r;

    void destruirNodos(nodo &n); // Destruye n y todos los nodos descendientes de n
    nodo copiar(nodo n); // Copia n y todos los nodos descendientes de n
};

// Definicion del nodo nulo
template <typename T>
const typename AbinEnla<T>::nodo AbinEnla<T>::NODO_NULO(nullptr);

/*------------------------------------------------*/
/* Metodos publicos                               */
/*------------------------------------------------*/

template <typename T>
inline AbinEnla<T>::AbinEnla() : r(NODO_NULO) {}

template <typename T>
inline void AbinEnla<T>::insertarRaiz(const T& e)
{
    assert(r == NODO_NULO);
    r = new celda(e);
}

template <typename T>
inline void AbinEnla<T>::insertarHijoDrcho(nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n->hder == NODO_NULO);
    n->hder = new celda(e, n);
}

template <typename T>
inline void AbinEnla<T>::insertarHijoIzqdo(nodo n, const T& e)
{
    assert(n != NODO_NULO);
    assert(n->hizq == NODO_NULO);
    n->hizq = new celda(e, n);
}

template <typename T>
inline void AbinEnla<T>::eliminarHijoIzqdo(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hizq != NODO_NULO);
    assert(n->hizq->hder == NODO_NULO && n->hizq->hder == NODO_NULO);
    delete n->hizq;
    n->hizq = NODO_NULO;
}

template <typename T>
inline void AbinEnla<T>::eliminarHijoDrcho(nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hder != NODO_NULO);
    assert(n->hder->hder == NODO_NULO && n->hder->hder == NODO_NULO);
    delete n->hder;
    n->hder = NODO_NULO;
}

template <typename T>
inline void AbinEnla<T>::eliminarRaiz()
{
    assert(r != NODO_NULO);
    assert(r->hder == NODO_NULO && r->hizq == NODO_NULO);
    
    delete r;
    r = NODO_NULO;
}

template <typename T>
inline bool AbinEnla<T>::arbolVacio() const
{
    return r == NODO_NULO;
}

template <typename T>
inline const T& AbinEnla<T>::elemento(nodo n) const
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename T>
inline T& AbinEnla<T>::elemento(nodo n)
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename T> inline
typename AbinEnla<T>::nodo AbinEnla<T>::raiz() const
{
    return r;
}

template <typename T> inline 
typename AbinEnla<T>::nodo AbinEnla<T>::padre(nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}

template <typename T> inline
typename AbinEnla<T>::nodo AbinEnla<T>::hijoIzqdo(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hizq;
}

template <typename T> inline
typename AbinEnla<T>::nodo AbinEnla<T>::hijoDrcho(nodo n) const
{
    assert(n != NODO_NULO);
    return n->hder;
}


template <typename T>
AbinEnla<T>::AbinEnla(const AbinEnla<T>& A)
{
    r = copiar(A.r);
}

template <typename T>
AbinEnla<T>& AbinEnla<T>::operator=(const AbinEnla<T>& A)
{
    if (this != &A)
    {
        destruirNodos(r);
        r = copiar(A.r);
    }

    return *this;
}

template <typename T>
AbinEnla<T>::~AbinEnla()
{
    destruirNodos(r);
}

/*------------------------------------------------*/
/* Metodos privados                               */
/*------------------------------------------------*/

template <typename T>
typename AbinEnla<T>::nodo AbinEnla<T>::copiar(nodo n)
{
    nodo m = NODO_NULO;
    if (n != NODO_NULO)
    {
        m = new celda(n->elto);
        m->hizq = copiar(n->hizq);
        if (m->hizq != NODO_NULO)
            m->hizq->padre = m;
        m->hder = copiar(n->hder);
        if (m->hder != NODO_NULO)
            m->hder->padre = m;
    }
    return m;
}

template <typename T>
void AbinEnla<T>::destruirNodos(nodo& n)
{
    if (n != NODO_NULO)
    {
        destruirNodos(n->hizq);
        destruirNodos(n->hder);
        delete n;
        n = NODO_NULO;
    }
}

#endif