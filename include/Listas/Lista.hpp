#pragma once

#include "Elemento.hpp"

namespace Listas 
{
    template<class TL>
    class Lista 
    {
    private:
        Elemento<TL>* pPrimeiro;
        Elemento<TL>* pUltimo;
        unsigned int tam;
        
    public:
        Lista();
        ~Lista();
        
        void adicionar(TL* elemento);
        void remover(TL* elemento);
        int getTam();
        void limparLista();
        TL* operator[](int pos);
        
    };

    template<class TL>
    Lista<TL>::Lista():
    pPrimeiro(NULL), 
    pUltimo(NULL), 
    tam(0)
    {

    }

    template<class TL>
    Lista<TL>::~Lista()
    {

    }

    template<class TL>
    void Lista<TL>::adicionar(TL* elemento)
    {
        if(elemento == NULL)
        {
            std::cout << "ERROR::Lista elemento eh NULL" << std::endl;
            exit(1);
        }
        Elemento<TL>* novoElemento = new Elemento<TL>();
        if(novoElemento == NULL)
        {
            std::cout << "ERROR::Lista aux eh NULL" << std::endl;
            exit(1);
        }
        novoElemento->setElemento(elemento);
        if(pPrimeiro == NULL)
        {
            pPrimeiro = novoElemento;
            pUltimo = novoElemento;
        } else 
        {
            pUltimo->setProx(novoElemento);
            pUltimo = novoElemento;
        }
        tam++;
    }


    template<class TL>
    void Lista<TL>::remover(TL* elemento)
    {
        if(elemento == NULL)
        {
            std::cout << "ERROR::Lista elemento eh NULL" << std::endl;
            exit(1);
        }
        Elemento<TL>* aux = pPrimeiro;
        Elemento<TL>* aux2 = NULL;
        while (aux != NULL && aux->getElemento() != elemento)
        {
            aux2 = aux;
            aux = aux->getProx();
        }
        if(aux->getElemento() == elemento)
        {
            if(aux == pPrimeiro)
            {
                pPrimeiro = aux->getProx();
            } 
            else if(aux == pUltimo)
            {
                pUltimo = aux2;
            } 
            else 
            {
                aux2->setProx(aux->getProx());
            }
            tam--;
        }
        
    }

    template<class TL>
    int Lista<TL>::getTam()
    {
        return (int)tam;
    }

    template<class TL>
    TL* Lista<TL>::operator[](int pos)
    {
        if(pos >= (int)tam || pos < 0)
        {
            std::cout << "ERROR::Lista pos eh maior que o tamanho da lista" << std::endl;
            exit(1);
        }
        Elemento<TL>* aux = pPrimeiro;
        for(int i = 0; i < pos; i++)
        {
            aux = aux->getProx();
        }
        return aux->getElemento();
    }

    template<class TL>
    void Lista<TL>::limparLista()
    {
        if(pPrimeiro != NULL)
        {
            Elemento<TL>* aux = pPrimeiro;
            Elemento<TL>* aux2 = NULL;
            int i = 0;
            while(aux != NULL && i < tam)
            {
                TL* elemento = aux->getElemento();
                if(elemento != NULL)
                {
                    delete(elemento);
                    elemento = NULL;
                }
                aux2 = aux->getProx();
                delete(aux);
                aux = NULL;
                aux = aux2;
                i++;
            }
        }
        pPrimeiro = NULL;
        pUltimo = NULL;
        tam = 0;
    }
}