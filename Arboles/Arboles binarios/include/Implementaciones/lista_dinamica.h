#ifndef LISTA_DINAMICA
#define LISTA_DINAMICA
#include <cassert>
#include <cstddef>

template <typename T>
class ListaDinamica
{
    struct nodo;

public:
    typedef nodo *posicion;
    ListaDinamica();
    bool vacia() const;
    size_t tama() const;
    void insertar(const T &x, posicion p);
    void eliminar(posicion p);
    T elemento(posicion p) const;
    T &elemento(posicion p);
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    ListaDinamica(const ListaDinamica &P);
    ListaDinamica &operator=(const ListaDinamica &P);
    ~ListaDinamica();

private:
    struct nodo
    {
        T elem;
        nodo *sig;
    };
    nodo *L;
    size_t n_elem;
    void copiar(const ListaDinamica<T> &P);

};

template <typename T>
ListaDinamica<T>::ListaDinamica()
{
    n_elem = 0;
    L = new nodo;
    L->sig = L;
}

template <typename T>
bool ListaDinamica<T>::vacia() const
{
    return (n_elem == 0);
}

template <typename T>
size_t ListaDinamica<T>::tama() const
{
    return n_elem;
}

template <typename T>
void ListaDinamica<T>::insertar(const T &x, posicion p)
{
    nodo *q = p->sig;
    p->sig = new nodo;
    p->sig->elem = x;
    p->sig->sig = q;
    if (p == L)
        L = p->sig;
    ++n_elem;
}

template <typename T>
void ListaDinamica<T>::eliminar(posicion p)
{
    assert(p != fin());
    nodo *q = p->sig;
    if (q == fin())
        L = p;
    p->sig = p->sig->sig;
    delete q;
    --n_elem;
}

template <typename T>
T ListaDinamica<T>::elemento(posicion p) const
{
    assert(p != fin());
    return p->sig->elem;
}

template <typename T>
T &ListaDinamica<T>::elemento(posicion p)
{
    assert(p != fin());
    return p->sig->elem;
}

template <typename T>
typename ListaDinamica<T>::posicion ListaDinamica<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return (p->sig);
}

template <typename T>
typename ListaDinamica<T>::posicion ListaDinamica<T>::anterior(posicion p) const
{
    assert(p != primera());
    posicion q = primera();
    while (q->sig != p)
        q = q->sig;
    return (q);
}

template <typename T>
typename ListaDinamica<T>::posicion ListaDinamica<T>::primera() const
{
    return L->sig;
}

template <typename T>
typename ListaDinamica<T>::posicion ListaDinamica<T>::fin() const
{
    return L;
}

template <typename T>
void ListaDinamica<T>::copiar(const ListaDinamica<T> &P)
{
    if (!P.vacia())
    {
        n_elem = P.n_elem;
        posicion p = P.primera();
        nodo *q = new nodo;
        nodo *inicio = q;
        q->sig = new nodo;
        q = q->sig;
        p = p->sig;
        q->elem = p->elem;
        while (p->sig != P.primera())
        {
            p = p->sig;
            q->sig = new nodo;
            q = q->sig;
            q->elem = p->elem;
        }
        L = q;
        L->sig = inicio;
    } else
    {
        ListaDinamica();
    }
}

template <typename T>
ListaDinamica<T>::ListaDinamica(const ListaDinamica &P)
{
    copiar(P);
}

template <typename T>
ListaDinamica<T> &ListaDinamica<T>::operator=(const ListaDinamica &P)
{
    if (this != &P)
    {
        this->~ListaDinamica();
        copiar(P);
    }
    return *this;
}

template <typename T>
ListaDinamica<T>::~ListaDinamica()
{
    posicion p;
    posicion q = primera();
    L->sig = nullptr;
    while (q != nullptr)
    {
        p = q;
        q = q->sig;
        delete p;
    }
    n_elem = 0;
    L = nullptr;
}

#endif