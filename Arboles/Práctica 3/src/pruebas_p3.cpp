#include <iostream>
#include <fstream>

#include "Implementaciones/Arbol_general_celdas_enlazadas.hpp"

#include "E-S/agen_E-S.h"

#include "pruebas/pruebas_p3.hpp"
#include "practicas/practica3.hpp"

void prueba_grado_agen()
{
    using namespace std;
    AgenEnla<char> A, B;

    ifstream fs("./include/E-S/agen.dat");
    rellenarAgen(fs, A);
    fs.close();

    cout << "Grado A (4) -> " << gradoAgen(A) << endl;
    cout << "Grado B (0) -> " << gradoAgen(B);
}

void prueba_profundidad_agen()
{
    using namespace std;
    AgenEnla<char> A;

    ifstream fs("./include/E-S/agen.dat");
    rellenarAgen(fs, A);
    fs.close();

    cout << "Profundidad A (2) -> " << profundidadAgen(A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz()))), A) << endl;
    cout << "Profundidad B (0) -> " << profundidadAgen(A.raiz(), A);
}

void prueba_desequilibrio_agen()
{
    using namespace std;
    AgenEnla<char> A, B;

    ifstream fs("./include/E-S/agen.dat");
    rellenarAgen(fs, A);
    fs.close();

    cout << "Desequilibrio A (1) -> " << desequilibrioAgen(A) << endl;
    cout << "Desequilibrio B (0) -> " << gradoAgen(B);
}

void prueba_podar_agen()
{
    using namespace std;
    AgenEnla<char> A;

    ifstream fs("./include/E-S/agen.dat");
    rellenarAgen(fs, A);
    fs.close();

    podarEnteroAgen('g', A);
    imprimirAgen(A);
}