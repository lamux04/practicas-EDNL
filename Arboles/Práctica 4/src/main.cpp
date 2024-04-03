#include <iostream>

#include "Implementaciones/Arbol_general_celdas_enlazadas.hpp"
#include "E-S/agen_E-S.h"

int main() {
    AgenEnla<char> A;
    rellenarAgen(A, '$');
    imprimirAgen(A);
}