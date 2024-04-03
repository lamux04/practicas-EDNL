#ifndef ABB_E_S_HPP
#define ABB_E_S_HPP

#include <iostream>

#include "Implementaciones/Arbol_binario_busqueda.hpp"

template <typename T>
void imprimirElementos(const Abb<T>& A);

template <typename T>
void imprimirElementos_REC(const Abb<T>& A);

template <typename T>
void imprimirElementos(const Abb<T>& A)
{
    std::cout << "ABB -> ";
    imprimirElementos_REC(A);
    std::cout << std::endl;
}

template <typename T>
void imprimirElementos_REC(const Abb<T>& A)
{
    if (!A.vacio())
    {
        imprimirElementos_REC(A.izqdo());
        std::cout << A.elemento() << " ";
        imprimirElementos_REC(A.drcho());
    }
}

#endif