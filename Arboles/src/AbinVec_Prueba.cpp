#include <iostream>
#include <fstream>
#include "Implementaciones/Arbol_binario_vectorial.h"
#include "E-S/abinVec_E-S.h"
#include "pruebas/AbinVec_Prueba.h"

void prueba_abin_vec()
{
    using namespace std;
    AbinVec<char> A(50), B(50);
    cout << "*** Lectura del arbol binario A de abin.dat ***" << endl;

    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    B = A;
    
    imprimirAbin(B);                 // Mostramos el arbol
}