#ifndef PRACTICA3_HPP
#define PRACTICA3_HPP

#include <algorithm>
#include "Implementaciones/Arbol_general_celdas_enlazadas.hpp"

template <typename T>
int gradoAgen(AgenEnla<T> A);
template <typename T>
int gradoAgen_REC(typename AgenEnla<T>::nodo n, AgenEnla<T> A);
template <typename T>
int profundidadAgen(typename AgenEnla<T>::nodo n, const AgenEnla<T>& A);


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

#endif