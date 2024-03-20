#ifndef ARBOL_BINARIO_POS_RELATIVAS
#define ARBOL_BINARIO_POS_RELATIVAS

#include <stddef.h>
#include <cassert>

template <typename T>
class AbinRel
{
    struct celda;

public:
    typedef size_t nodo;
    static const nodo NODO_NULO;    // Propiqedad de la clase
    AbinRel(size_t maxNodos, T el_nulo);
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
    AbinRel(const AbinRel<T> &A);
    AbinRel<T> &operator=(const AbinRel<T> &A);
    ~AbinRel();

private:
    size_t maxNodos;
    T ELTO_NULO;
    T* nodos;
};

template <typename T>
const typename AbinRel<T>::nodo AbinRel<T>::NODO_NULO{__SIZE_MAX__};

template <typename T>
AbinRel<T>::AbinRel(size_t maxNodos, T el_nulo) : 
    maxNodos(maxNodos), 
    ELTO_NULO(el_nulo), 
    nodos(new T[maxNodos]) 
{
    for (nodo n = 0; n <= maxNodos - 1; ++n)
        nodos[n] = ELTO_NULO;
}

template <typename T>
inline void AbinRel<T>::insertarRaiz(const T& e)
{
    assert(nodos[0] == ELTO_NULO);
    nodos[0] = e;
}

template <typename T>
inline void AbinRel<T>::insertarHijoIzqdo(nodo n, const T& e)
{
    assert(n <= maxNodos);
    assert(nodos[n] != ELTO_NULO);
    assert(maxNodos - 1 >= 2 * n + 1);
    assert(nodos[2 * n + 1] == ELTO_NULO);
    nodos[2*n + 1] = e;
}

template <typename T>
inline void AbinRel<T>::insertarHijoDrcho(nodo n, const T& e)
{
    assert(n <= maxNodos);
    assert(nodos[n] != ELTO_NULO);
    assert(maxNodos - 1 >= 2 * n + 2);
    assert(nodos[2 * n + 2] == ELTO_NULO);
    nodos[2*n + 2] = e;
}

template <typename T>
inline void AbinRel<T>::eliminarHijoIzqdo(nodo n)
{
    assert(n <= maxNodos);
    assert(nodos[n] != ELTO_NULO);
    assert(maxNodos - 1 >= 2 * n + 1);
    assert(nodos[2 * n + 1] != ELTO_NULO);
    if (maxNodos - 1 >= 4 * n + 4)
        assert(nodos[4 * n + 3] == ELTO_NULO && nodos[4 * n + 4] == ELTO_NULO);
    else if (maxNodos - 1 >= 4 * n + 3)
        assert(nodos[4 * n + 3] == ELTO_NULO);

    nodos[2*n + 1] = ELTO_NULO;
}

template <typename T>
inline void AbinRel<T>::eliminarHijoDrcho(nodo n)
{
    assert(n <= maxNodos);
    assert(nodos[n] != ELTO_NULO);
    assert(maxNodos - 1 >= 2 * n + 2);
    assert(nodos[2 * n + 2] != ELTO_NULO);
    if (maxNodos - 1 >= 4 * n + 6)
        assert(nodos[4 * n + 5] == ELTO_NULO && nodos[4 * n + 6] == ELTO_NULO);
    else if (maxNodos - 1 >= 4 * n + 5)
        assert(nodos[4 * n + 5] == ELTO_NULO);

    nodos[2*n + 2] = ELTO_NULO;
}

template <typename T>
inline void AbinRel<T>::eliminarRaiz()
{
    assert(nodos[0] != ELTO_NULO);
    assert(nodos[1] == ELTO_NULO && nodos[2] == ELTO_NULO);

    nodos[0] = ELTO_NULO;
}

template <typename T>
inline bool AbinRel<T>::arbolVacio() const
{
    return nodos[0] == ELTO_NULO;
}

template <typename T>
inline const T& AbinRel<T>::elemento(nodo n) const
{
    assert(n <= maxNodos - 1);
    assert(nodos[n] != ELTO_NULO);
    return nodos[n];
}

template <typename T>
inline T& AbinRel<T>::elemento(nodo n) 
{
    assert(n <= maxNodos - 1);
    assert(nodos[n] != ELTO_NULO);
    return nodos[n];
}

template <typename T> inline
typename AbinRel<T>::nodo AbinRel<T>::raiz() const
{
    return (nodos[0] == ELTO_NULO) ? NODO_NULO : 0;
}

template <typename T> inline
typename AbinRel<T>::nodo AbinRel<T>::padre(nodo n) const
{
    assert(n <= maxNodos - 1);
    assert(nodos[n] != ELTO_NULO);
    return (n == 0) ? NODO_NULO : (n - 1)/2;
}

template <typename T> inline
typename AbinRel<T>::nodo AbinRel<T>::hijoIzqdo(nodo n) const
{
    assert(n <= maxNodos - 1);
    assert(nodos[n] != ELTO_NULO);
    return (maxNodos - 1 <= 2 * n + 1 || nodos[2 * n + 1] == ELTO_NULO) ? NODO_NULO : 2 * n + 1;
}

template <typename T> inline
typename AbinRel<T>::nodo AbinRel<T>::hijoDrcho(nodo n) const
{
    assert(n <= maxNodos - 1);
    assert(nodos[n] != ELTO_NULO);
    return (maxNodos - 1 <= 2 * n + 2 || nodos[2 * n + 2] == ELTO_NULO) ? NODO_NULO : 2 * n + 2;
}

template <typename T>
AbinRel<T>::AbinRel(const AbinRel<T>& A) : 
    maxNodos(A.maxNodos),
    ELTO_NULO(A.ELTO_NULO),
    nodos(new T[maxNodos])
{
    for (nodo i = 0; i < maxNodos; ++i)
        nodos[i] = A.nodos[i];
}

template <typename T>
AbinRel<T>::~AbinRel()
{
    delete[] nodos;
}

template <typename T>
AbinRel<T>& AbinRel<T>::operator=(const AbinRel<T>& A)
{
    if (this != &A)
    {
        if (maxNodos != A.maxNodos)
        {
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new T[maxNodos];
        }

        ELTO_NULO = A.ELTO_NULO;

        for (nodo i = 0; i < maxNodos; ++i)
            nodos[i] = A.nodos[i];
    }
    return *this;
}

#endif