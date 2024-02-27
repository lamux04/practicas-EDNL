#ifndef ARBOL_BINARIO_VECTORIAL
#define ARBOL_BINARIO_VECTORIAL

#include <cassert>
#include <stddef.h>

template <typename T>
class AbinVec
{
    struct celda;

public:
    typedef size_t nodo;
    static const nodo NODO_NULO; // Propiedad de la clase
    AbinVec(size_t n);
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
    int altura(nodo n) const;
    int profundidad(nodo n) const;
    AbinVec(const AbinVec<T> &A);
    AbinVec<T> &operator=(const AbinVec<T> &A);
    ~AbinVec();

private:
    struct celda
    {
        T elto;
        nodo padre, hizq, hder;
        celda(const T &x = T(), nodo p = NODO_NULO) : elto(x), padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
    };

    celda *nodos;
    size_t numNodos;
    size_t maxNodos;
};

template <typename T>
const typename AbinVec<T>::nodo AbinVec<T>::NODO_NULO(__SIZE_MAX__);

/* -------------------------------------------------- */
/* Metodos publicos                                   */
/* -------------------------------------------------- */

template <typename T>
inline AbinVec<T>::AbinVec(size_t maxNodos) : numNodos(0), maxNodos(maxNodos), nodos(new celda[maxNodos]) {}

template <typename T>
inline void AbinVec<T>::insertarRaiz(const T &e)
{
    assert(numNodos == 0);
    nodos[0].elto = e;
    nodos[0].padre = NODO_NULO;
    nodos[0].hizq = NODO_NULO;
    nodos[0].hder = NODO_NULO;
    numNodos = 1;
}

template <typename T>
inline void AbinVec<T>::insertarHijoIzqdo(nodo n, const T &e)
{
    assert(n >= 0 && n <= numNodos - 1);
    assert(nodos[n].hizq == NODO_NULO);
    assert(numNodos < maxNodos);

    nodos[n].hizq = numNodos;
    nodos[numNodos].elto = e;
    nodos[numNodos].hizq = NODO_NULO;
    nodos[numNodos].hder = NODO_NULO;
    nodos[numNodos].padre = n;
    ++numNodos;
}

template <typename T>
inline void AbinVec<T>::insertarHijoDrcho(nodo n, const T &e)
{
    assert(n >= 0 && n <= numNodos - 1);
    assert(nodos[n].hder == NODO_NULO);
    assert(numNodos < maxNodos);

    nodos[n].hder = numNodos;
    nodos[numNodos].elto = e;
    nodos[numNodos].hizq = NODO_NULO;
    nodos[numNodos].hder = NODO_NULO;
    nodos[numNodos].padre = n;
    ++numNodos;
}

template <typename T>
void AbinVec<T>::eliminarHijoIzqdo(nodo n)
{
    nodo nodo_eliminar;
    assert(n >= 0 && n <= numNodos - 1);
    assert(nodos[n].hizq != NODO_NULO);
    nodo_eliminar = nodos[n].hizq
                        assert(nodos[nodo_eliminar].hizq == NODO_NULO && nodos[nodo_eliminar].hder == NODO_NULO);

    if (n != numNodos - 1)
    {
        nodos[nodo_eliminar] = nodos[numNodos - 1];

        // Actualizamos el padre de numNodos - 1
        if (nodos[nodos[numNodos - 1].padre].hizq == numNodos - 1)
            nodos[nodos[numNodos - 1].padre].hizq = nodo_eliminar;
        else
            nodos[nodos[numNodos - 1].padre].hder = nodo_eliminar;

        // Actualizamos los hijos de numNodos - 1
        if (nodos[numNodos - 1].hizq != NODO_NULO)
            nodos[nodos[numNodos - 1].hizq].padre = nodo_eliminar;

        if (nodos[numNodos - 1].hder != NODO_NULO)
            nodos[nodos[numNodos - 1].hder].padre = nodo_eliminar;
    }
    nodos[n].hizq = NODO_NULO;
    --numNodos;
}

template <typename T>
void AbinVec<T>::eliminarHijoDrcho(nodo n)
{
    nodo nodo_eliminar;
    assert(n >= 0 && n <= numNodos - 1);
    assert(nodos[n].hder != NODO_NULO);
    nodo_eliminar = nodos[n].hder
                        assert(nodos[nodo_eliminar].hizq == NODO_NULO && nodos[nodo_eliminar].hder == NODO_NULO);

    if (n != numNodos - 1)
    {
        nodos[nodo_eliminar] = nodos[numNodos - 1];

        // Actualizamos el padre de numNodos - 1
        if (nodos[nodos[numNodos - 1].padre].hizq == numNodos - 1)
            nodos[nodos[numNodos - 1].padre].hizq = nodo_eliminar;
        else
            nodos[nodos[numNodos - 1].padre].hder = nodo_eliminar;

        // Actualizamos los hijos de numNodos - 1
        if (nodos[numNodos - 1].hizq != NODO_NULO)
            nodos[nodos[numNodos - 1].hizq].padre = nodo_eliminar;

        if (nodos[numNodos - 1].hder != NODO_NULO)
            nodos[nodos[numNodos - 1].hder].padre = nodo_eliminar;
    }
    nodos[n].hder = NODO_NULO;
    --numNodos;
}

template <typename T>
inline void AbinVec<T>::eliminarRaiz()
{
    assert(numNodos == 1);
    --numNodos;
}

template <typename T>
inline bool AbinVec<T>::arbolVacio() const
{
    return numNodos == 0;
}

template <typename T>
inline const T &AbinVec<T>::elemento(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return nodos[n].elto;
}

template <typename T>
inline T &AbinVec<T>::elemento(nodo n)
{
    assert(n >= 0 && n <= numNodos - 1);
    return nodos[n].elto;
}

template <typename T>
inline
    typename AbinVec<T>::nodo
    AbinVec<T>::raiz() const
{
    return numNodos == 0 ? NODO_NULO : 0;
}

template <typename T>
inline
    typename AbinVec<T>::nodo
    AbinVec<T>::padre(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return nodos[n].padre;
}

template <typename T>
inline
    typename AbinVec<T>::nodo
    AbinVec<T>::hijoIzqdo(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return nodos[n].hizq;
}

template <typename T>
inline
    typename AbinVec<T>::nodo
    AbinVec<T>::hijoDrcho(nodo n) const
{
    assert(n >= 0 && n <= numNodos - 1);
    return nodos[n].hder;
}

template <typename T>
int AbinVec<T>::profundidad(nodo n) const
{
    assert(n != NODO_NULO);
    int i = 0;

    while (n != 0)
    {
        ++i;
        n = nodos[n].padre;
    }

    return i;
}

template <typename T>
int AbinVec<T>::altura(nodo n) const
{
    if (n == NODO_NULO)
        return -1;

    else
    {
        int aizq = altura(nodos[n].hizq),
            ader = altura(nodos[n].hder);

        if (aizq > ader)
            return aizq + 1;
        else
            return ader + 1;
    }
}

template <typename T>
AbinVec<T>::AbinVec(const AbinVec<T> &A) : numNodos(A.numNodos),
                                           maxNodos(A.maxNodos),
                                           nodos(new celda[A.maxNodos])
{
    for (int i = 0; i < A.numNodos; ++i)
        nodos[i] = A.nodos[i];
}

template <typename T>
AbinVec<T>::~AbinVec()
{
    delete[] nodos;
}

template <typename T>
AbinVec<T> &AbinVec<T>::operator=(const AbinVec<T> &A)
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

#endif