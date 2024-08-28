#pragma once

#include <vector>
#include "Lista.hpp"
#include "../Entidades/Entidade.hpp"

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidade> lista;

    public:
        ListaEntidades();
        ~ListaEntidades();
        
        void adicionar(Entidades::Entidade* entidade);
        Lista<Entidades::Entidade>::Iterador remover(Lista<Entidades::Entidade>::Iterador it);
        int getTam();
        void limpar();
        Entidades::Entidade* operator[](int pos);  
        void executar(const float dt);
        void desenhar();

        Lista<Entidades::Entidade>::Iterador inicio() { return lista.inicio(); }
        Lista<Entidades::Entidade>::Iterador fim() { return lista.fim(); }
    };
};