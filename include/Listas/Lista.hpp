/*
Lista.hpp - Classe template de Lista
----------------------------------------------------
 * Inspirado em: https://github.com/Giovanenero/JogoPlataforma2D-Jungle e https://moodle.dainf.ct.utfpr.edu.br/course/view.php?id=953
*/

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
        int getTam();
        void limparLista();
        TL* operator[](int pos);

        class Iterador 
        {
        private:
            Elemento<TL>* atual;

        public:
            Iterador(Elemento<TL>* inicio): atual(inicio) {}

            virtual Iterador& operator++() 
            {
                if (atual != NULL)
                    atual = atual->getProx();
                return *this;
            }

            bool operator!=(const Iterador& outro) const 
            {
                return atual != outro.atual;
            }

            TL* operator*() const 
            {
                if (atual != NULL)
                    return atual->getElemento();
                return NULL;
            }

            Iterador getProx() const
            {
                if(atual && atual->getProx())
                {
                    return Iterador(atual->getProx());
                }
                return Iterador(NULL);
            }

            friend class Lista;
        };

        Iterador remover(Iterador it);  

        Iterador inicio() { return Iterador(pPrimeiro); }
        Iterador fim() { return Iterador(NULL); }
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
    typename Lista<TL>::Iterador Lista<TL>::remover(Iterador it)
    {
        Elemento<TL>* aux = it.atual;
        if (!aux) return it;

        if (aux == pPrimeiro)
        {
            pPrimeiro = aux->getProx();
            if (pPrimeiro == nullptr)
            {
                pUltimo = nullptr;  // Lista ficou vazia
            }
        }
        else
        {
            Elemento<TL>* anterior = pPrimeiro;
            while (anterior->getProx() != aux)
            {
                anterior = anterior->getProx();
            }
            anterior->setProx(aux->getProx());

            if (aux == pUltimo)
            {
                pUltimo = anterior;
            }
        }

        Iterador proximo = it.getProx();
        delete aux;
        tam--;

        return proximo;  // Retorne o próximo iterador válido
    }

    // template<class TL>
    // void Lista<TL>::remover(TL* elemento)
    // {
    //     if(elemento == NULL)
    //     {
    //         std::cout << "ERROR::Lista elemento eh NULL" << std::endl;
    //         exit(1);
    //     }
    //     Elemento<TL>* aux = pPrimeiro;
    //     Elemento<TL>* aux2 = NULL;
    //     while (aux != NULL && aux->getElemento() != elemento)
    //     {
    //         aux2 = aux;
    //         aux = aux->getProx();
    //     }
    //     if(aux->getElemento() == elemento)
    //     {
    //         if(aux == pPrimeiro)
    //         {
    //             pPrimeiro = aux->getProx();
    //         }
    //         else if(aux == pUltimo)
    //         {
    //             pUltimo = aux2;
    //         } 
    //         else 
    //         {
    //             aux2->setProx(aux->getProx());
    //         }
    //         if(aux)
    //             delete(aux);
    //         aux = NULL;
    //         aux2 = NULL;
    //         tam--;
    //     }
    // }

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
                if(elemento)
                {
                    delete(elemento);
                    elemento = NULL;
                }
                aux2 = aux->getProx();
                if(aux)
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