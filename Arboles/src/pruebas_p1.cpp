#include "Implementaciones/Arbol_binario_celdas_enlazadas.h"
#include "pruebas/pruebas_p1.hpp"
#include "E-S/abinEnla_E-S.h"

#include "practicas/p1.hpp"

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