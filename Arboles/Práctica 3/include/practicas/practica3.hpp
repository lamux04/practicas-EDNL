#ifndef PRACTICA3_HPP
#define PRACTICA3_HPP

#include <algorithm>
#include "Implementaciones/Arbol_general_celdas_enlazadas.hpp"
#include "Implementaciones/cola-dinamica.h"

template <typename T>
int gradoAgen(AgenEnla<T> A);
template <typename T>
int gradoAgen_REC(typename AgenEnla<T>::nodo n, AgenEnla<T> A);
template <typename T>
int profundidadAgen(typename AgenEnla<T>::nodo n, const AgenEnla<T>& A);
template <typename T>
int alturaAgen(const AgenEnla<T>& A);
template <typename T>
int alturaAgen_REC(typename AgenEnla<T>::nodo n, const AgenEnla<T>& A);
template <typename T>
int desequilibrioAgen(const AgenEnla<T>& A);
template <typename T>
void podarEnteroAgen(T x, AgenEnla<T>& A);
template <typename T>
typename AgenEnla<T>::nodo buscarAgen_REC(typename AgenEnla<T>::nodo n, T x, const AgenEnla<T>& A);
template <typename T>
void podarNodoAgen(typename AgenEnla<T>::nodo n, AgenEnla<T>& A);
template <typename T>
void podarNodoAgen_REC(typename AgenEnla<T>::nodo n, AgenEnla<T>& A);


template <typename T>
int gradoAgen(AgenEnla<T> A)
{
    return gradoAgen_REC(A.raiz(), A);
}

template <typename T>
int gradoAgen_REC(typename AgenEnla<T>::nodo n, AgenEnla<T> A)
{
    if (n == AgenEnla<T>::NODO_NULO)
        return 0;
    else
    {
        int num_hijos = 0, grado = 0;
        typename AgenEnla<T>::nodo hijo = A.hijoIzqdo(n);

        while (hijo != AgenEnla<T>::NODO_NULO)
        {
            num_hijos++;
            grado = std::max(grado, gradoAgen_REC(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return std::max(num_hijos, grado);
    }
}

template <typename T>
int profundidadAgen(typename AgenEnla<T>::nodo n, const AgenEnla<T>& A)
{
    int p = 0;
    while (n != A.raiz())
    {
        ++p;
        n = A.padre(n);
    }
    return p;
}

template <typename T>
int alturaAgen(const AgenEnla<T>& A)
{
    return alturaAgen_REC(A.raiz(), A);
}

template <typename T>
int alturaAgen_REC(typename AgenEnla<T>::nodo n, const AgenEnla<T>& A)
{
    if (n == AgenEnla<T>::NODO_NULO)
        return -1;
    else
    {
        typename AgenEnla<T>::nodo hijo = A.hijoIzqdo(n);
        int max = -1;
        while (hijo != AgenEnla<T>::NODO_NULO)
        {
            max = std::max(max, alturaAgen_REC(hijo, A));
            hijo = A.hermDrcho(hijo);
        }

        return max + 1;
    }
}

template <typename T>
int desequilibrioAgen(const AgenEnla<T>& A)
{
    ColaDinamica<typename AgenEnla<T>::nodo> C;
    typename AgenEnla<T>::nodo n = A.raiz();
    int maxDes = 0, min = -1, max = 3, nivel = 0, altura;

    if (n == AgenEnla<T>::NODO_NULO)
        return 0;
    else
    {
        do
        {
            if (!C.vacia())
            {
                n = C.frente(); C.pop();
            }
            if (n != A.raiz())
            {
                if (profundidadAgen(n, A) == 1 && nivel == 0)
                {
                    nivel++;
                    maxDes = 0;
                    max = min = alturaAgen_REC(n, A);
                }
                else if (profundidadAgen(n, A) > nivel)
                {
                    nivel++;
                    maxDes = std::max(std::abs(max - min), maxDes);
                    max = min = alturaAgen_REC(n, A);
                }
                else
                {
                    altura = alturaAgen_REC(n, A);
                    max = std::max(altura, max);
                    if (min > altura)
                        min = altura;
                }
            }
            typename AgenEnla<T>::nodo hijo = A.hijoIzqdo(n);
            while (hijo != AgenEnla<T>::NODO_NULO)
            {
                C.push(hijo);
                hijo = A.hermDrcho(hijo);
            }
        } while (!C.vacia());
    }
    return std::max(std::abs(max - min), maxDes);
}

template <typename T>
void podarEnteroAgen(T x, AgenEnla<T>& A)
{
    typename AgenEnla<T>::nodo n = buscarAgen_REC(A.raiz(), x, A);
    podarNodoAgen(n, A);
}

template <typename T>
typename AgenEnla<T>::nodo buscarAgen_REC(typename AgenEnla<T>::nodo n, T x, const AgenEnla<T>& A)
{
    if (n == AgenEnla<T>::NODO_NULO || A.elemento(n) == x)
        return n;
    else
    {
        typename AgenEnla<T>::nodo hijo = A.hijoIzqdo(n), n_res = AgenEnla<T>::NODO_NULO;
        while (hijo != AgenEnla<T>::NODO_NULO && n_res == AgenEnla<T>::NODO_NULO)
        {
            n_res = buscarAgen_REC(hijo, x, A);
            hijo = A.hermDrcho(hijo);
        }
        return n_res;
    }
}

template <typename T>
void podarNodoAgen(typename AgenEnla<T>::nodo n, AgenEnla<T>& A)
{
    podarNodoAgen_REC(n, A);
    if (n == A.raiz())
        A.eliminarRaiz();
    else
    {
        typename AgenEnla<T>::nodo hijo = A.hijoIzqdo(A.padre(n));
        if (hijo == n)
            A.eliminarHijoIzqdo(A.padre(n));
        else
        {
            while (A.hermDrcho(hijo) != n)
                hijo = A.hermDrcho(hijo);
            A.eliminarHermDrcho(hijo);
        }
    }
}

template <typename T>
void podarNodoAgen_REC(typename AgenEnla<T>::nodo n, AgenEnla<T>& A)
{
    if (n != AgenEnla<T>::NODO_NULO && A.hijoIzqdo(n) != AgenEnla<T>::NODO_NULO)
    {
        while (A.hijoIzqdo(n) != AgenEnla<T>::NODO_NULO)
        {
            podarNodoAgen_REC(A.hijoIzqdo(n), A);
            A.eliminarHijoIzqdo(n);
        }
    }
}

#endif