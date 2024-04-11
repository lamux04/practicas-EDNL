#ifndef PRACTICA4_HPP
#define PRACTICA4_HPP

#include "Implementaciones/Arbol_binario_busqueda.hpp"
#include <iostream>

template <typename T>
void podarAbb(T x, Abb<T>& A);

template <typename T>
void equilibrarAbb(Abb<T>& A);

template <typename T>
int numNodosAbb(const Abb<T>& A);

template <typename T>
void deAbbAVector(const Abb<T>& A, T v[], int& i);

template <typename T>
void deVectorAAbb(int inicio, int fin, Abb<T>& A, T v[]);

template <typename T>
using Conjunto = Abb<T>;


template <typename T>
void podarAbb(T x, Abb<T>& A)
{
    Abb<T>& subarbol = A.buscar(x);
    while (!subarbol.vacio())
        subarbol.eliminar(subarbol.elemento());
}

template <typename T>
int numNodosAbb(const Abb<T>& A)
{
    if (A.vacio())
        return 0;
    else
    {
        return 1 + numNodosAbb(A.izqdo()) + numNodosAbb(A.drcho());
    }
}

template <typename T>
void equilibrarAbb(Abb<T>& A)
{
    Abb<T> B;
    int n = numNodosAbb(A);
    T *v = new T[n];
    int i = 0;
    deAbbAVector(A, v, i);
    deVectorAAbb(0, n - 1, B, v);
    delete[] v;
    A = B;
}

template <typename T>
void deAbbAVector(const Abb<T>& A, T v[], int& i)
{
    if (!A.vacio())
    {
        deAbbAVector(A.izqdo(), v, i);
        v[i] = A.elemento();
        i++;
        deAbbAVector(A.drcho(), v, i);
    }
}

template <typename T>
void deVectorAAbb(int inicio, int fin, Abb<T>& A, T v[])
{
    int centro = (inicio + fin) / 2;

    if (inicio <= fin)
    {
        if (inicio == fin)
            A.insertar(v[centro]);
        else
        {
            A.insertar(v[centro]);
            deVectorAAbb(inicio, centro - 1, A, v);
            deVectorAAbb(centro + 1, fin, A, v);
        }
    }
}

template <typename T>
void AgregarElementos_REC(const Conjunto<T>& A, Conjunto<T>& C)
{
    if (!A.vacio())
    {
        C.insertar(A.elemento());
        AgregarElementos_REC(A.izqdo(), C);
        AgregarElementos_REC(A.drcho(), C);
    }
}

template <typename T>
Conjunto<T> UnionConjuntos(const Conjunto<T>& A, const Conjunto<T>& B)
{
    Conjunto<T> C = A;
    AgregarElementos_REC(B, C);
    equilibrarAbb(C);
    return C;
}

template <typename T>
bool perteneceConjunto(const Conjunto<T>& A, const T& x)
{
    return !A.buscar(x).vacio();
}

template <typename T>
void InterseccionConjuntos_REC(const Conjunto<T>& A, const Conjunto<T>& B, Conjunto<T>& C)
{
    if (!A.vacio())
    {
        if (perteneceConjunto(B, A.elemento()))
            C.insertar(A.elemento());
        InterseccionConjuntos_REC(A.izqdo(), B, C);
        InterseccionConjuntos_REC(A.drcho(), B, C);
    }
}

template <typename T>
Conjunto<T> InterseccionConjuntos(const Conjunto<T>& A, const Conjunto<T>& B)
{
    Conjunto<T> C;
    InterseccionConjuntos_REC(A, B, C);
    equilibrarAbb(C);
    return C;
}

template <typename T>
void diferenciaConjuntos_REC(const Conjunto<T>& A, const Conjunto<T>& B, Conjunto<T>& C)
{
    if (!A.vacio())
    {
        if (!perteneceConjunto(B, A.elemento()))
            C.insertar(A.elemento());
        diferenciaConjuntos_REC(A.izqdo(), B, C);
        diferenciaConjuntos_REC(A.drcho(), B, C);
    }
}

template <typename T>
Conjunto<T> diferenciaConjuntos(const Conjunto<T>& A, const Conjunto<T>& B)
{
    Conjunto<T> C;
    diferenciaConjuntos_REC(A, B, C);
    equilibrarAbb(C);
    return C;
}

template <typename T>
Conjunto<T> OperadorEspecial(const Conjunto<T>& A, const Conjunto<T>& B)
{
    return diferenciaConjuntos(UnionConjuntos(A, B), InterseccionConjuntos(A, B));
}

#endif