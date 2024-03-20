#include <iostream>
#include <fstream>
#include "Implementaciones/Arbol_binario_celdas_enlazadas.h"
#include "E-S/abinEnla_E-S.h"
#include "pruebas/AbinEnla_Prueba.h"

void prueba_abin_enla()
{
    using namespace std;
    AbinEnla<char> A, B;
    cout << "*** Lectura del arbol binario A de abin.dat ***" << endl;

    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    B = A;
    
    imprimirAbin(B);                 // Mostramos el arbol
}