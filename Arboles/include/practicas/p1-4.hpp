#ifndef EJERCICIO4_PRACTICA2
#define EJERCICIO4_PRACTICA2

#include <stddef.h>
#include <cassert>
#include <math.h>

template <typename T>
class AbinVec2
{
    struct celda;
public:
    typedef size_t nodo;
    static const nodo NODO_NULO; // Propiedad de la clase
    AbinVec2(size_t H, T nulo);
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
    AbinVec2(const AbinVec2<T> &A);
    AbinVec2<T> &operator=(const AbinVec2<T> &A);
    ~AbinVec2();
private:
    size_t alturaMax, maxNodos;
    const T ELTO_NULO;
    T *nodos;
    int altura(nodo n);
    int profundidad(nodo n, int inicio, int fin);
};

template <typename T>
const typename AbinVec2<T>::nodo NODO_NULO{ __SIZE_MAX__ };

template <typename T>
AbinVec2<T>::AbinVec2(size_t n, T nulo) : maxNodos(n), ELTO_NULO(nulo), nodos(new T[n])
{
    for (int i = 0; i < n; ++i)
        nodos[i] = ELTO_NULO;
}

template <typename T>
void AbinVec2<T>::insertarRaiz(const T& e)
{
    assert(nodos[maxNodos / 2] == ELTO_NULO);
    nodos[maxNodos / 2] = e;
}

template <typename T>
void AbinVec2<T>::insertarHijoIzqdo(nodo n, const T& e)
{
    assert(n < maxNodos);
    assert(nodos[n] != ELTO_NULO);
    assert(n + pow(2, altura(n)) < maxNodos);
    assert(nodos[n + pow(2, altura(n))] != ELTO_NULO);

    nodos[n + pow(2, altura(n))] = e;
}

template <typename T>
typename AbinVec2<T>::nodo AbinVec2<T>::padre(nodo n) const
{
    assert(n < maxNodos);
    assert(nodos[n] != ELTO_NULO);

    if (n % pow(2, altura(n) + 2) == pow(2, altura(n)) - 1) // hijo izquierdo de su padre
        return n + pow(2, altura(n));
    else
        return n - pow(2, altura(n));
}

template <typename T>
int AbinVec2<T>::altura(nodo n)
{
    return H - profundidad(n, 0, tamMax - 1);
}

template <typename T>
int AbinVec2<T>::profundidad(nodo n, int inicio, int fin)
{
    int centro = (inicio + fin) / 2;

    if (n == centro)
        return 0;
    else
        if (n < centro)
            return 1 + profundidad(n, inicio, centro);
        else
            return 1 + profundidad(n, centro, fin);
}

#endif