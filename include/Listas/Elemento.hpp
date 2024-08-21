#pragma once

#include <iostream>

namespace Listas 
{
    template<class TE>
    class Elemento 
    {
    private:
        Elemento<TE>* prox;
        TE* elemento;

    public:
        Elemento();
        ~Elemento();
        void setProx(Elemento<TE>* pr);
        void setElemento(TE* elem);
        Elemento<TE>* getProx();
        TE* getElemento();

    };
    
    template<class TE>
    Elemento<TE>::Elemento():
    prox(NULL), 
    elemento(NULL)
    {

    }

    template<class TE>
    Elemento<TE>::~Elemento()
    {
        
    }

    template<class TE>
    void Elemento<TE>::setProx(Elemento<TE>* pr)
    {
        prox = pr;
    }

    template<class TE>
    void Elemento<TE>::setElemento(TE* elem)
    {
        elemento = elem;
    }

    template<class TE>
    Elemento<TE>* Elemento<TE>::getProx()
    {
        return prox;
    }

    template<class TE>
    TE* Elemento<TE>::getElemento()
    {
        return elemento;
    }
}

