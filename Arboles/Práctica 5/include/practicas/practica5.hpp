#ifndef PRACTICA4_HPP
#define PRACTICA4_HPP

#include "Implementaciones/Arbol_general_celdas_enlazadas.hpp"
#include <iostream>

template <typename T>
bool EstrictamenteTernario_REC(typename AgenEnla<T>::nodo n, const AgenEnla<T>& A)
{
    if (n == AgenEnla<T>::NODO_NULO)
        return true;
    else
    {
        bool ternario = true;
        typename AgenEnla<T>::nodo nhijo = A.hijoIzqdo(n);
        int hijos = 0;
        while (nhijo != AgenEnla<T>::NODO_NULO && ternario)
        {
            ++hijos;
            ternario = ternario && EstrictamenteTernario_REC(nhijo, A);
            nhijo = A.hermDrcho(nhijo);
        }
        if (hijos != 0 && hijos != 3)
            return false;
        else
            return ternario;
    }
}

template <typename T>
bool EstrictamenteTernario(const AgenEnla<T>& A)
{
    return EstrictamenteTernario_REC(A.raiz(), A);
}

#endif