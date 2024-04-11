#ifndef ARBOL_PARCIALMENTE_ORDENADO
#define ARBOL_PARCIALMENTE_ORDENADO

#include <cstddef>
#include <cassert>
#include <algorithm>

template <typename T>
class Apo
{
public:
    explicit Apo(size_t maxNodos);
    void insertar(const T& e);
    void suprimir();
    const T& cima() const;
    bool vacio() const { return numNodos == 0; }
    Apo(const Apo<T>& A);
    Apo<T>& operator=(const Apo<T>& A);
    ~Apo() { delete[] nodos; }

private:
    typedef size_t nodo;
    T *nodos;
    size_t numNodos;
    size_t maxNodos;
    nodo padre(nodo i) const { return (i - 1) / 2; }
    nodo hIzq(nodo i) const { return 2 * i + 1; }
    nodo hDer(nodo i) const { return 2 * i + 2; }
    void flotar(nodo i);
    void hundir(nodo i);
};

template <typename T>
inline Apo<T>::Apo(size_t maxNodos) : nodos(new T[maxNodos]), numNodos(0), maxNodos(max) {}

template <typename T>
inline const T& Apo<T>::cima() const
{
    assert(numNodos != 0);
    return nodos[0];
}

template <typename T>
void Apo<T>::insertar(const T& e)
{
    assert(numNodos < maxNodos);
    nodos[numNodos] = e;
    numNodos++;
    if (numNodos > 1)
        flotar(numNodos - 1);
}

template <typename T>
void Apo<T>::flotar(nodo i)
{
    while (i != 0 && nodos[padre(i)] > nodos[i])
    {
        T aux = nodos[padre(i)];
        nodos[padre(i)] = nodos[i];
        nodos[i] = aux;
    }
}

template <typename T>
void Apo<T>::suprimir()
{
    assert(numNodos > 0);
    numNodos--;
    if (numNodos > 0)
    {
        nodos[0] = nodos[numNodos - 1];
        if (numNodos > 1)
            hundir(0);
    }
}

template <typename T>
void Apo<T>::hundir(nodo i)
{
    bool fin = false;
    T e = nodos[i];
    while (hIzq(i) < numNodos && !fin)
    {
        nodo hMin;
        if (hDer(i) < numNodos && nodos[hDer(i)] < nodos[hIzq(i)])
            hMin = hDer(i);
        else
            hMin = hIzq(i);
        if (nodos[hMin] < e)
        {
            nodos[i] = nodos[hMin];
            i = hMin;
        }
        else
            fin = true;
    }
    nodos[i] = e;
}

template <typename T>
Apo<T>::Apo(const Apo<T>& A) :
    nodos(new T[A.maxNodos]),
    maxNodos(A.maxNodos),
    numNodos(A.numNodos)
{
    // Copiar el vector.
    for (nodo n = 0; n < numNodos; n++)
        nodos[n] = A.nodos[n];
}

template <typename T>
Apo<T>& Apo<T>::operator =(const Apo<T>& A)
{
    if (this != &A) // Evitar autoasignación.
    { // Destruir el vector y crear uno nuevo si es necesario.
        if (maxNodos != A.maxNodos)
        {
            delete[] nodos;
            maxNodos = A.maxNodos;
            nodos = new T[maxNodos];
        }
        numNodos = A.numNodos;
        // Copiar el vector
        for (nodo n = 0; n < numNodos; n++)
            nodos[n] = a.nodos[n];
    }
    return *this;
}

#endif