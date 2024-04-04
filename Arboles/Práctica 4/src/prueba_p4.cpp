#include "Implementaciones/Arbol_binario_busqueda.hpp"
#include "pruebas/pruebas_p4.hpp"
#include "practicas/practica4.hpp"

#include "E-S/Abb_E-S.hpp"

void prueba_podar_abb()
{
    Abb<int> A;
    A.insertar(3);
    A.insertar(4);
    A.insertar(2);
    A.insertar(0);
    A.insertar(1);
    A.insertar(10);
    A.insertar(13);
    A.insertar(-3);
    A.insertar(5);
    A.insertar(0);

    imprimirElementos(A);
}

void prueba_equilibrar_abb()
{
    Abb<int> A;
    A.insertar(3);
    A.insertar(4);
    A.insertar(2);
    A.insertar(0);
    A.insertar(1);
    A.insertar(10);
    A.insertar(13);
    A.insertar(-3);
    A.insertar(5);
    A.insertar(0);

    equilibrarAbb(A);
    imprimirElementos(A);
}

void prueba_union_conjuntos()
{
    Conjunto<int> A;
    A.insertar(3);
    A.insertar(4);
    A.insertar(2);
    A.insertar(0);
    A.insertar(1);
    A.insertar(10);
    A.insertar(13);
    A.insertar(-3);
    A.insertar(5);
    A.insertar(0);

    Conjunto<int> B;
    B.insertar(4);
    B.insertar(10);
    B.insertar(13);
    B.insertar(3);
    B.insertar(7);
    B.insertar(0);

    imprimirElementos(A);
    imprimirElementos(B);

    Conjunto<int> C(UnionConjuntos(A, B));
    imprimirElementos(C);
}