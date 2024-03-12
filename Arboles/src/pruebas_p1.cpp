#include "Implementaciones/Arbol_binario_celdas_enlazadas.h"
#include "pruebas/pruebas_p1.hpp"
#include "E-S/abinEnla_E-S.h"

#include "practicas/p1.hpp"
#include "practicas/p1-3.hpp"

void prueba_similares_abin()
{
    using namespace std;
    AbinEnla<char> A, B, C;

    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    ifstream fich2("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich2, B);
    fich2.close();                    // Cerramos fichero

    cout << "Similares (true) -> " << SimilaresAbin(A, B) << endl;
    cout << "Similares (false) -> " << SimilaresAbin(A, C) << endl;

}

void prueba_reflejado_abin()
{
    using namespace std;
    AbinEnla<char> A, B, C;

    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    imprimirAbin(A);

    cout << "####################" << endl;

    B = ReflejadoAbin(A);
    imprimirAbin(B);

}

void prueba_expresion_aritmetica()
{
    using namespace std;
    AbinEnla<elem> A;

    A.insertarRaiz(elem(SUMA));
    A.insertarHijoIzqdo(A.raiz(), elem(5));
    A.insertarHijoDrcho(A.raiz(), elem(PROD));
    A.insertarHijoIzqdo(A.hijoDrcho(A.raiz()), elem(4));
    A.insertarHijoDrcho(A.hijoDrcho(A.raiz()), elem(2));



    cout << "Expresion aritmetica (11) -> " << ExpresionInfija(A) << endl;

}
