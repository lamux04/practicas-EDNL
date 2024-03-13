#ifndef P1_3_HPP
#define P1_3_HPP

enum operador { NULO, SUMA, RESTA, PROD, DIVI };
struct elem
{
    operador o;
    double n;
    elem(operador o) : o{ o }, n{ 0 } {}
    elem(double n) : o{ NULO }, n{ n } {}
};

double ExpresionInfija(const AbinEnla<elem>& A);
double ExpresionInfija_REC(AbinEnla<elem>::nodo n, const AbinEnla<elem>& A);

#endif