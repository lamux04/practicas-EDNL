#ifndef ARBOL_GENERAL_VECTORIAL_HPP
#define ARBOL_GENERAL_VECTORIAL_HPP

#include "lista_dinamica.h"
#include <cassert>

template <typename T>
class AgenVec
{
    struct celda;

public:
    typedef size_t nodo;
    static const nodo NODO_NULO;

    AgenVec(size_t n);
    void insertarRaiz(const T &e);
    void insertarHijoIzqdo(nodo n, const T &e);
    void insertarHermDrcho(nodo n, const T &e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHermDrcho(nodo n);
    void eliminarRaiz();
    const T &elemento(nodo n) const;
    T &elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hermDrcho(nodo n) const;
    AgenVec(const AgenVec<T> &A);
    AgenVec<T> &operator=(const AgenVec<T> &A);
    ~AgenVec();

private:
    struct celda
    {
        T elto;
        nodo padre;
        ListaDinamica<nodo> hijos;
    };

    celda *nodos;
    size_t maxNodos;
    size_t numNodos;
};

template <typename T>
const typename AgenVec<T>::nodo AgenVec<T>::NODO_NULO{ __SIZE_MAX__ };

template <typename T>
inline AgenVec<T>::AgenVec(size_t n) : nodos(new celda[n]), maxNodos(n), numNodos(0)
{
    for (nodo i = 0; i < maxNodos; ++i)
        nodos[i].padre = NODO_NULO;
}

template <typename T>
void AgenVec<T>::insertarRaiz(const T &e)
{
    assert(numNodos == 0); // Árbol vacío.
    numNodos = 1;
    nodos[0].elto = e;
    // La lista de hijos está vacía.
}

template <typename T>
inline void AgenVec<T>::insertarHijoIzqdo(nodo n, const T &e)
{
    assert(n < numNodos);
    assert(nodos[n].padre != NODO_NULO || n == 0);
    assert(numNodos < maxNodos);

    nodo hijoizq;
    for (hijoizq = 1; nodos[hijoizq].padre != NODO_NULO; hijoizq++);
    nodos[hijoizq].elto = e;
    nodos[hijoizq].padre = n;
    nodos[n].hijos.insertar(hijoizq, nodos[n].hijos.primera());
    ++numNodos;
}

template <typename T>
inline void AgenVec<T>::insertarHermDrcho(nodo n, const T & e)
{
    assert(n < numNodos);
    assert(nodos[n].padre != NODO_NULO);
    assert(numNodos < maxNodos);

    nodo hermDrcho;
    for (hermDrcho = 1; nodos[hermDrcho].padre != NODO_NULO; hermDrcho++);

    nodos[hermDrcho].padre = nodos[n].padre;
    nodos[hermDrcho].elto = e;

    ListaDinamica<T>& lis = nodos[nodos[n].padre].hijos;
    ListaDinamica<T>::posicion pos;
    for (pos = lis.primera(); lis.elemento(pos) != n; pos = lis.siguiente(pos));
    lis.insertar(hermDrcho, lis.siguiente(pos));

    numNodos++;
}

template <typename T>
inline void AgenVec<T>::eliminarHijoIzqdo(nodo n)
{
    assert(n < numNodos);
    assert(nodos[n].padre != NODO_NULO || n == 0);
    assert(!nodos[n].hijos.vacia());

    nodo hijoIzqdo = nodos[n].hijos.elemento(nodos[n].hijos.primera());
    assert(nodos[hijoIzqdo].hijos.vacia());

    nodos[hijoIzqdo].padre = NODO_NULO;
    nodos[n].hijos.eliminar(nodos[n].hijos.primera());
    numNodos--;
}

template <typename T>
inline void AgenVec<T>::eliminarHermDrcho(nodo n)
{
    assert(n < numNodos);
    assert(nodos[n].padre != NODO_NULO || n == 0);

    ListaDinamica<nodo>& lis = nodos[nodos[n].padre].hijos;
    assert(lis.tama() >= 2);

    ListaDinamica<nodo>::posicion pos = lis.primera();
    for (pos; lis.elemento(pos) != n; pos = lis.siguiente(pos));
    assert(lis.siguiente(pos) != lis.fin());

    nodo hermDrcho = lis.elemento(lis.siguiente(pos));
    assert(nodos[hermDrcho].hijos.vacia());

    lis.eliminar(lis.siguiente(pos));
    nodos[hermDrcho].padre = NODO_NULO;
    numNodos--;
}

template <typename T>
inline void AgenVec<T>::eliminarRaiz()
{
    assert(numNodos == 1);
    numNodos = 0;
}

template <typename T>
inline const T &AgenVec<T>::elemento(nodo n) const
{
    assert(numNodos > 0); // Árbol no vacío.
    assert(n >= 0 && n <= maxNodos - 1); // n es una celda del vector
    assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada
    return nodos[n].elto;
}

template <typename T>
inline T &AgenVec<T>::elemento(nodo n)
{
    assert(numNodos > 0); // Árbol no vacío.
    assert(n >= 0 && n <= maxNodos - 1); // n es una celda del vector
    assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada
    return nodos[n].elto;
}

template <typename T>
inline typename AgenVec<T>::nodo AgenVec<T>::raiz() const
{
    return numNodos == 0 ? NODO_NULO : 0;
}

template <typename T>
inline typename AgenVec<T>::nodo AgenVec<T>::padre(nodo n) const
{
    assert(numNodos > 0); // Árbol no vacío.
    assert(n >= 0 && n <= maxNodos - 1); // n es una celda del vector
    assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada

    return nodos[n].padre;
}

template <typename T>
inline typename AgenVec<T>::nodo AgenVec<T>::hijoIzqdo(nodo n) const
{
    assert(numNodos > 0); // Árbol no vacío.
    assert(n >= 0 && n <= maxNodos - 1); // n es una celda del vector
    assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada

    ListaDinamica<nodo>& Lh = nodos[n].hijos;
    if (Lh.primera() != Lh.fin()) // Lista no vacía.
        return Lh.elemento(Lh.primera());
    else
        return NODO_NULO;
}

template <typename T>
inline typename AgenVec<T>::nodo AgenVec<T>::hermDrcho(nodo n) const
{
    ListaDinamica<nodo>::posicion p;
    assert(numNodos > 0); // Árbol no vacío.
    assert(n >= 0 && n <= maxNodos - 1); // n es una celda del vector
    assert(n == 0 || nodos[n].padre != NODO_NULO); // que está ocupada.
    if (n == 0) // n es la raíz.
        return NODO_NULO;
    else
    {
        ListaDinamica<nodo>& Lhp = nodos[nodos[n].padre].hijos; // Lista de hijos
        // del padre.
        ListaDinamica<nodo>::posicion p = Lhp.primera();
        while (n != Lhp.elemento(p)) p = Lhp.siguiente(p);
        p = Lhp.siguiente(p);
        return p != Lhp.fin() ? // n tiene hermano drcho.
            Lhp.elemento(p) : NODO_NULO;
    }
}

template <typename T>
AgenVec<T>::AgenVec(const AgenVec<T> &A) :
    numNodos(A.numNodos),
    maxNodos(A.maxNodos),
    nodos(new celda[A.maxNodos])
{
    for (int i = 0; i < A.numNodos; ++i)
        nodos[i] = A.nodos[i];
}

template <typename T>
AgenVec<T> &AgenVec<T>::operator=(const AgenVec<T> &A)
{
    if (this != &A)
    {
        if (maxNodos != A.maxNodos)
        {
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new celda[maxNodos];
        }

        numNodos = A.numNodos;
        for (int i = 0; i < A.numNodos; ++i)
            nodos[i] = A.nodos[i];
    }

    return *this;
}

template <typename T>
AgenVec<T>::~AgenVec()
{
    delete[] nodos;
}

#endif