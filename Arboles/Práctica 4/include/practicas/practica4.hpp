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

    if (inicio > fin)
    {
        if (inicio == fin)
            A.insertar(v[centro]);
        else
        {
            std::cout << "Inserta el centro " << v[centro] << std::endl;
            A.insertar(v[centro]);
            deVectorAAbb(inicio, centro - 1, A, v);
            deVectorAAbb(centro + 1, fin, A, v);
        }
    }
}


#endif