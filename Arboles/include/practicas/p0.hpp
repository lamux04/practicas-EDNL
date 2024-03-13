#ifndef PROBLEMAS_P0
#define PROBLEMAS_P0

#include "Implementaciones/Arbol_binario_celdas_enlazadas.h"

template <typename T>
int NumNodosAbin(const AbinEnla<T> &A);
template <typename T>
int NumNodosAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A);
template <typename T>
int AlturaAbin(const AbinEnla<T> &A);
template <typename T>
int AlturaAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A);
template <typename T>
int ProfundidadAbin(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A);
template <typename T>
int DesequilibroAbin(const AbinEnla<T> &A);
template <typename T>
int DesequilibrioAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A);
template <typename T>
bool PseudocompletoAbin(const AbinEnla<T> &A);
template <typename T>
bool PseudocompletoAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A, int p_nivel, int nivel);

template <typename T>
int NumNodosAbin(const AbinEnla<T> &A)
{
    return NumNodosAbin_REC(A.raiz(), A);
}

template <typename T>
int NumNodosAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A)
{
    if (n == AbinEnla<T>::NODO_NULO)
        return 0;
    else
        return (NumNodosAbin_REC(A.hijoIzqdo(n), A) + NumNodosAbin_REC(A.hijoDrcho(n), A) + 1);
}

template <typename T>
int AlturaAbin(const AbinEnla<T> &A)
{
    return AlturaAbin_REC(A.raiz(), A);
}

template <typename T>
int AlturaAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A)
{
    if (n == AbinEnla<T>::NODO_NULO)
        return -1;
    else
    {
        int aizq = AlturaAbin_REC(A.hijoIzqdo(n), A),
            ader = AlturaAbin_REC(A.hijoDrcho(n), A);

        if (aizq > ader)
            return aizq + 1;
        else
            return ader + 1;
    }
}

template <typename T>
int ProfundidadAbin(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A)
{
    return ProfundidadAbinF(n, A, 0);
}

template <typename T>
int ProfundidadAbinF(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A, int p)
{
    if (n == A.raiz())
        return p;
    else
        return ProfundidadAbinF(A.padre(n), A, p + 1);
}

template <typename T>
int DesequilibroAbin(const AbinEnla<T> &A)
{
    return DesequilibrioAbin_REC(A.raiz(), A);
}

template <typename T>
int DesequilibrioAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A)
{
    if (n == AbinEnla<T>::NODO_NULO)
        return 0;

    else
    {
        int altura_izq = A.altura(A.hijoIzqdo(n));
        int altura_der = A.altura(A.hijoDrcho(n));
        int desequilibrio_n = (altura_izq > altura_der) ? altura_izq - altura_der : altura_der - altura_izq;
        int desequilibrio_izq = DesequilibrioAbin_REC(A.hijoIzqdo(n), A);
        int desequilibrio_der = DesequilibrioAbin_REC(A.hijoDrcho(n), A);

        if (desequilibrio_n > desequilibrio_izq && desequilibrio_n > desequilibrio_der)
            return desequilibrio_n;
        if (desequilibrio_der > desequilibrio_izq)
            return desequilibrio_der;
        return desequilibrio_izq;
    }
}

template <typename T>
bool PseudocompletoAbin(const AbinEnla<T> &A)
{
    return PseudocompletoAbin_REC(A.raiz(), A, AlturaAbin(A) - 1, 0);
}

template <typename T>
bool PseudocompletoAbin_REC(typename AbinEnla<T>::nodo n, const AbinEnla<T> &A, int p_nivel, int nivel)
{
    if (n == AbinEnla<T>::NODO_NULO)
        return true;
    else
    {
        if (nivel == p_nivel)
        {
            if ((A.hijoIzqdo(n) == AbinEnla<T>::NODO_NULO) == (A.hijoDrcho(n) == AbinEnla<T>::NODO_NULO))
                return true;
            else
                return false;
        }

        return (PseudocompletoAbin_REC(A.hijoIzqdo(n), A, p_nivel, nivel + 1) && PseudocompletoAbin_REC(A.hijoDrcho(n), A, p_nivel, nivel + 1));
    }
}

#endif