#pragma once

#include <vector>
#include "../Entidades/Personagem/Personagem.hpp"
#include "Lista.hpp"

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
        void remover(Entidades::Entidade* entidade);
        int getTam();
        void limpar();
        Entidades::Entidade* operator[](int pos);  
        void atualizar(const float dt);
        void desenhar();
    };
};