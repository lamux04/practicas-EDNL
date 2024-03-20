#ifndef PRACTICA1_HPP
#define PRACTICA1_HPP

#include "../Implementaciones/Arbol_binario_celdas_enlazadas.h"

template <typename T> bool SimilaresAbin(const AbinEnla<T>& A, const AbinEnla<T>& B);
template <typename T> bool SimilaresAbin_REC(typename AbinEnla<T>::nodo n1, typename AbinEnla<T>::nodo n2, const AbinEnla<T>& A, const AbinEnla<T>& B);
template <typename T> AbinEnla<T> ReflejadoAbin(const AbinEnla<T>& A);
template <typename T> void ReflejadoAbin_REC(typename AbinEnla<T>::nodo n1, typename AbinEnla<T>::nodo n2, const AbinEnla<T>& A, AbinEnla<T>& B);

template <typename T>
bool SimilaresAbin(const AbinEnla<T>& A, const AbinEnla<T>& B)
{
    return SimilaresAbin_REC(A.raiz(), B.raiz(), A, B);
}

template <typename T>
bool SimilaresAbin_REC(typename AbinEnla<T>::nodo n1, typename AbinEnla<T>::nodo n2, const AbinEnla<T>& A, const AbinEnla<T>& B)
{
    if (n1 == AbinEnla<T>::NODO_NULO || n2 == AbinEnla<T>::NODO_NULO)
        return (n1 == AbinEnla<T>::NODO_NULO && n2 == AbinEnla<T>::NODO_NULO);
    else
        return (SimilaresAbin_REC(A.hijoIzqdo(n1), B.hijoIzqdo(n2), A, B) && SimilaresAbin_REC(A.hijoDrcho(n1), B.hijoDrcho(n2), A, B));
}

template <typename T>
AbinEnla<T> ReflejadoAbin(const AbinEnla<T>& A)
{
    AbinEnla<T> B;

    if (!A.arbolVacio())
    {
        B.insertarRaiz(A.elemento(A.raiz()));
        ReflejadoAbin_REC(A.raiz(), B.raiz(), A, B);
    }

    return B;
}

template <typename T>
void ReflejadoAbin_REC(typename AbinEnla<T>::nodo n1, typename AbinEnla<T>::nodo n2, const AbinEnla<T>& A, AbinEnla<T>& B)
{
    if (A.hijoIzqdo(n1) != AbinEnla<T>::NODO_NULO)
    {
        B.insertarHijoDrcho(n2, A.elemento(A.hijoIzqdo(n1)));
        ReflejadoAbin_REC(A.hijoIzqdo(n1), B.hijoDrcho(n2), A, B);
    }
    if (A.hijoDrcho(n1) != AbinEnla<T>::NODO_NULO)
    {
        B.insertarHijoIzqdo(n2, A.elemento(A.hijoDrcho(n1)));
        ReflejadoAbin_REC(A.hijoDrcho(n1), B.hijoIzqdo(n2), A, B);
    }
}




#endif