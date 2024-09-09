/*
ListaEntidades.hpp
----------------------------------------------------
 * Lista de entidades do jogo
 * Padrão de projeto Iterator.
*/

#pragma once

#include <vector>
#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> lista;
        Gerenciadores::GerenciadorEstados* pEstados;

    public:
        class IteradorEntidades 
        {
        private:
            Lista<Entidades::Entidade>::Iterador iterador;

        public:
            IteradorEntidades(Lista<Entidades::Entidade>::Iterador it): 
                iterador(it) {}

            ~IteradorEntidades() {}

            IteradorEntidades& operator++() 
            {
                ++iterador;
                return *this;
            }

            bool operator!=(const IteradorEntidades& outro) const 
            {
                return iterador != outro.iterador;
            }

            Entidades::Entidade* operator*() const 
            {
                return *iterador;
            }

            IteradorEntidades getProx() const 
            {
                return IteradorEntidades(iterador.getProx());
            }

            friend class ListaEntidades;
        };

        ListaEntidades();
        ~ListaEntidades();
        
        void adicionar(Entidades::Entidade* entidade);
        IteradorEntidades remover(IteradorEntidades it);
        const int getTam() const;
        void limpar();
        Entidades::Entidade* operator[](int pos);  
        void executar(const float dt);
        void desenhar();

        IteradorEntidades inicio() { return IteradorEntidades(lista.inicio()); }
        IteradorEntidades fim() { return IteradorEntidades(lista.fim()); }
    };
}