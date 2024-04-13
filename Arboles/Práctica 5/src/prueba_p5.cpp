#include "Implementaciones/Arbol_general_celdas_enlazadas.hpp"

#include "practicas/practica5.hpp"
#include "pruebas/pruebas_p5.hpp"

#include <iostream>

void pruebaEstrictamenteTernario()
{
    AgenEnla<int> A;
    A.insertarRaiz(3);
    std::cout << EstrictamenteTernario(A) << " (1)" << std::endl;

    A.insertarHijoIzqdo(A.raiz(), 4);
    std::cout << EstrictamenteTernario(A) << " (0)" << std::endl;

    A.insertarHijoIzqdo(A.raiz(), 3);
    A.insertarHijoIzqdo(A.raiz(), 5);
    std::cout << EstrictamenteTernario(A) << " (1)" << std::endl;

    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 8);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 2);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 9);
    std::cout << EstrictamenteTernario(A) << " (1)" << std::endl;
}