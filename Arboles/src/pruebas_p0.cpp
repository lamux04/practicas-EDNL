#include "pruebas/pruebas_p0.hpp"
#include "practicas/p0.hpp"

#include "Implementaciones/Arbol_binario_celdas_enlazadas.h"
#include "Implementaciones/Arbol_binario_vectorial.h"

#include "E-S/abinEnla_E-S.h"
#include "E-S/abinVec_E-S.h"

void prueba_num_nodos_abin()
{
    using namespace std;
    AbinEnla<char> A, B;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Num nodos (12): " << NumNodosAbin(A) << endl;
    cout << "Num nodos (0): " << NumNodosAbin(B) << endl;
}

void prueba_altura_nodos_abin()
{
    using namespace std;
    AbinEnla<char> A, B;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Altura (4): " << AlturaAbin(A) << endl;
    cout << "Altura (-1): " << AlturaAbin(B) << endl;
}

void prueba_profundidad_abin()
{
    using namespace std;
    AbinEnla<char> A;
    AbinEnla<char>::nodo n;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Profundidad (0): " << ProfundidadAbin(A.raiz(), A) << endl;
    n = A.hijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz())));
    cout << "Profundidad (3): " << ProfundidadAbin(n, A) << endl;
}

void prueba_altura_nodos_abin_enla()
{
    using namespace std;
    AbinEnla<char> A, B;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Altura (4): " << A.altura(A.raiz()) << endl;
    cout << "Altura (-1): " << B.altura(B.raiz()) << endl;
}

void prueba_profundidad_abin_enla()
{
    using namespace std;
    AbinEnla<char> A;
    AbinEnla<char>::nodo n;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Profundidad (0): " << A.profundidad(A.raiz()) << endl;
    n = A.hijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz())));
    cout << "Profundidad (3): " << A.profundidad(n) << endl;
}

void prueba_altura_nodos_abin_vec()
{
    using namespace std;
    AbinVec<char> A(50), B(50);
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Altura (4): " << A.altura(A.raiz()) << endl;
    cout << "Altura (-1): " << B.altura(B.raiz()) << endl;
}

void prueba_profundidad_abin_vec()
{
    using namespace std;
    AbinVec<char> A(50);
    AbinVec<char>::nodo n;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Profundidad (0): " << A.profundidad(A.raiz()) << endl;
    n = A.hijoIzqdo(A.hijoIzqdo(A.hijoIzqdo(A.raiz())));
    cout << "Profundidad (3): " << A.profundidad(n) << endl;
}


void prueba_desequilibrio_abin()
{
    using namespace std;
    AbinEnla<char> A, B;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    cout << "Desequilibrio (2): " << DesequilibroAbin(A) << endl;
    cout << "Desequilibrio (-1): " << DesequilibroAbin(B) << endl;
}


void prueba_pseudocompleto_abin()
{
    using namespace std;
    AbinEnla<char> A, B;
    ifstream fich("dat/abin.dat"); // Abrir fichero de entrada
    rellenarAbin(fich, A);
    fich.close();                    // Cerramos fichero

    rellenarAbin(B, '$');

    cout << "Desequilibrio (0): " << PseudocompletoAbin(A) << endl;
    cout << "Desequilibrio (??): " << PseudocompletoAbin(B) << endl;
}