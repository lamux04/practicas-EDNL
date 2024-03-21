#ifndef ColaDinamica_DINAMICA
#define ColaDinamica_DINAMICA
#include <cassert>
#include <cstddef>

template <typename T>
class ColaDinamica
{
public:
    ColaDinamica();
    bool vacia() const;
    T frente() const;
    size_t tama() const;
    void push(const T &x);
    void pop();
    ColaDinamica(const ColaDinamica &P);
    ColaDinamica &operator=(const ColaDinamica &P);
    ~ColaDinamica();

private:
    struct nodo
    {
        T elem;
        nodo *sig;
    };
    nodo *inicio;
    nodo *fin;
    size_t n_elem;
    void copiar(const ColaDinamica &P);
};

template <typename T>
ColaDinamica<T>::ColaDinamica()
{
    inicio = nullptr;
    n_elem = 0;
}

template <typename T>
bool ColaDinamica<T>::vacia() const
{
    return (n_elem == 0);
}

template <typename T>
T ColaDinamica<T>::frente() const
{
    assert(!vacia());
    return (inicio->elem);
}

template <typename T>
size_t ColaDinamica<T>::tama() const
{
    return (n_elem);
}

template <typename T>
void ColaDinamica<T>::push(const T &x)
{
    if (!vacia())
    {
        fin->sig = new nodo;
        fin = fin->sig;
        fin->elem = x;
        fin->sig = nullptr;
    }
    else
    {
        inicio = new nodo;
        inicio->elem = x;
        inicio->sig = nullptr;
        fin = inicio;
    }
    n_elem++;
}

template <typename T>
void ColaDinamica<T>::pop()
{
    assert(!vacia());
    nodo *p = inicio;
    inicio = inicio->sig;
    delete p;
    n_elem--;
}

template <typename T>
ColaDinamica<T>::ColaDinamica(const ColaDinamica &P)
{
    copiar(P);
}

template <typename T>
ColaDinamica<T> &ColaDinamica<T>::operator=(const ColaDinamica &P)
{
    if (this != &P)
    {
        this->~ColaDinamica();
        copiar(P);
    }
    return *this;
}

template <typename T>
ColaDinamica<T>::~ColaDinamica()
{
    nodo *p;
    while (inicio != nullptr)
    {
        p = inicio;
        inicio = inicio->sig;
        delete p;
    }
    fin = nullptr;
    n_elem = 0;
}

template <typename T>
void ColaDinamica<T>::copiar(const ColaDinamica &P)
{
    if (!P.vacia())
    {
        nodo *p = P.inicio;
        nodo *q;
        q = new nodo;
        inicio = q;
        q->elem = p->elem;
        p = p->sig;
        while (p != nullptr)
        {
            q->sig = new nodo;
            q = q->sig;
            q->elem = p->elem;
            p = p->sig;
        }
        fin = q;
        fin->sig = nullptr;
    }
    n_elem = P.n_elem;
}

#endif