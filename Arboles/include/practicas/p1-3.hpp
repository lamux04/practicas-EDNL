#ifndef P1_3_HPP
#define P1_3_HPP

enum operador { NULO, SUMA, RESTA, PROD, DIVI };
struct elem
{
    operador o;
    int n;
    elem(operador o) : o{ o }, n{ 0 } {}
    elem(int n) : o{ NULO }, n{ n } {}
};

int ExpresionInfija(const AbinEnla<elem>& A);
int ExpresionInfija_REC(AbinEnla<elem>::nodo n, const AbinEnla<elem>& A);

#endif