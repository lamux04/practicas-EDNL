#include <iostream>
#include <fstream>
#include "Implementaciones/Arbol_binario_pos_relativas.h"
#include "E-S/abinRel_E-S.h"
#include "pruebas/AbinRel_Prueba.h"

void prueba_abin_rel()
{
    using namespace std;
    AbinRel<char> A{1024, '$'}, B{250, '$'};
    cout << "*** Lectura del arbol binario A de abin.dat ***" << endl;

    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    B = A;
    
    imprimirAbin(B);                 // Mostramos el arbol
}