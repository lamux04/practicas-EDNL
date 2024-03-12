#include "Implementaciones/Arbol_binario_celdas_enlazadas.h"
#include "practicas/p1-3.hpp"

int ExpresionInfija(const AbinEnla<elem>& A)
{
    return ExpresionInfija_REC(A.raiz(), A);
}

int ExpresionInfija_REC(AbinEnla<elem>::nodo n, const AbinEnla<elem>& A)
{
    if (A.hijoIzqdo(n) == AbinEnla<elem>::NODO_NULO && A.hijoDrcho(n) == AbinEnla<elem>::NODO_NULO)
        return A.elemento(n).n;
    else
    {
        int a = ExpresionInfija_REC(A.hijoIzqdo(n), A),
            b = ExpresionInfija_REC(A.hijoDrcho(n), A);

        if (A.elemento(n).o == SUMA)
            return a + b;
        if (A.elemento(n).o == RESTA)
            return a - b;
        if (A.elemento(n).o == PROD)
            return a * b;
        return a / b;
    }
}