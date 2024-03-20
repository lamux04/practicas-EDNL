#ifndef ARBOL_GENERAL_CELDAS_ENLAZADAS
#define ARBOL_GENERAL_CELDAS_ENLAZADAS

#include <cassert>

template <typename T>
class AgenEnla
{
    struct celda;

public:
    typedef celda *nodo;
    static const nodo NODO_NULO;

    AgenEnla();
    bool arbolVacio() const;
    void insertarRaiz(const T &e);
    void insertarHijoIzqdo(nodo n, const T &e);
    void insertarHermDrcho(nodo n, const T &e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHermDrcho(nodo n);
    void eliminarRaiz();
    const T &elemento(nodo n) const;
    T &elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hermDrcho(nodo n) const;
    AgenEnla(const AgenEnla<T> &A);
    AgenEnla<T> &operator=(const AgenEnla<T> &A);
    ~AgenEnla();

private:
    struct celda
    {
        T elto;
        nodo padre, hizq, heder;
        celda(const T &e, nodo p = NODO_NULO) : elto(e), padre(p), hizq(NODO_NULO), heder(NODO_NULO) {}
    };

    nodo r;

    void destruirNodos(nodo &n);
    nodo copiar(nodo n);
};

template <typename T>
const typename AgenEnla<T>::nodo AgenEnla<T>::NODO_NULO{ nullptr };

template <typename T>
inline AgenEnla<T>::AgenEnla() : r(NODO_NULO) {}

template <typename T>
inline bool AgenEnla<T>::arbolVacio() const
{
    return r == NODO_NULO;
}

template <typename T>
inline void AgenEnla<T>::insertarRaiz(const T &e)
{
    assert(r == NODO_NULO);
    r = new celda(e);
}

template <typename T>
inline void AgenEnla<T>::insertarHijoIzqdo(nodo n, const T &e)
{
    assert(n != NODO_NULO);

    nodo t = n->hizq;
    n->hizq = new celda(e, n);
    n->hizq->heder = t;
}

template <typename T>
inline void AgenEnla<T>::insertarHermDrcho(nodo n, const T &e)
{
    assert(n != NODO_NULO);

    nodo t = n->heder;
    n->heder = new celda(e, n->padre);
    n->heder->heder = t;
}

template <typename T>
inline void AgenEnla<T>::eliminarHijoIzqdo(nodo n)
{
    nodo hizqdo;

    assert(n != NODO_NULO);
    hizqdo = n->hizq;
    assert(hizqdo != NODO_NULO);
    assert(hizqdo->hizq == NODO_NULO);

    n->hizq = hizqdo->heder;
    delete hizqdo;
}

template <typename T>
inline void AgenEnla<T>::eliminarHermDrcho(nodo n)
{
    nodo heder;

    assert(n != NODO_NULO);
    heder = n->hder;
    assert(heder != NODO_NULO);
    assert(heder->hizq == NODO_NULO);

    n->heder = heder->heder;
    delete heder;
}

template <typename T>
inline void AgenEnla<T>::eliminarRaiz()
{
    assert(r != NODO_NULO);
    assert(r->hizq == NODO_NULO);

    delete r;
    r = NODO_NULO;
}

template <typename T>
inline const T &AgenEnla<T>::elemento(nodo n) const
{
    assert(n != NODO_NULO);

    return n->elto;
}

template <typename T>
inline T &AgenEnla<T>::elemento(nodo n)
{
    assert(n != NODO_NULO);

    return n->elto;
}

template <typename T>
inline typename AgenEnla<T>::nodo AgenEnla<T>::raiz() const
{
    return r;
}

template <typename T>
inline typename AgenEnla<T>::nodo AgenEnla<T>::padre(nodo n) const
{
    assert(n != NODO_NULO);

    return n->padre;
}

template <typename T>
inline typename AgenEnla<T>::nodo AgenEnla<T>::hijoIzqdo(nodo n) const
{
    assert(n != NODO_NULO);

    return n->hizq;
}

template <typename T>
inline typename AgenEnla<T>::nodo AgenEnla<T>::hermDrcho(nodo n) const
{
    assert(n != NODO_NULO);

    return n->heder;
}

template <typename T>
AgenEnla<T>::AgenEnla(const AgenEnla<T> &A)
{
    r = copiar(A.r);
}

template <typename T>
AgenEnla<T> &AgenEnla<T>::operator=(const AgenEnla<T> &A)
{
    if (this != &A)
    {
        destruirNodos(r);
        r = copiar(A.r);
    }

    return *this;
}

template <typename T>
AgenEnla<T>::~AgenEnla()
{
    destruirNodos(r);
}

template <typename T>
void AgenEnla<T>::destruirNodos(nodo &n)
{
    if (n != NODO_NULO)
    {
        if (n->hizq != NODO_NULO)
        {
            nodo heder = n->hizq->heder;
            while (heder != NODO_NULO)
            {
                n->hizq->heder = heder->heder;
                destruirNodos(heder);
                heder = n->hizq->heder;
            }
            destruirNodos(n->hizq);
        }
        delete n;
        n = NODO_NULO;
    }
}

template <typename T>
typename AgenEnla<T>::nodo AgenEnla<T>::copiar(nodo n)
{
    nodo m = NODO_NULO;
    if (n != NODO_NULO)
    {
        m = new celda(n->elto);
        if (n->hizq != NODO_NULO)
        {
            m->hizq = copiar(n->hizq);
            m->hizq->padre = m;
            nodo hijo = m->hizq;
            nodo heder = n->hizq->heder;
            while (heder != NODO_NULO)
            {
                hijo->heder = copiar(heder);
                hijo = hijo->heder;
                hijo->padre = m;
                heder = heder->heder;
            }
        }
    }
    return m;
}

#endif