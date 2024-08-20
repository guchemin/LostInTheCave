#pragma once

#include <vector>
#include "../Entidades/Personagem/Personagem.hpp"
#include "Lista.hpp"

namespace Listas
{
    class ListaEntidades
    {
    private:
        Lista<Entidades::Entidades> lista;

    public:
        ListaEntidades();
        ~ListaEntidades();
        
        void adicionar(Entidades::Entidades* entidade);
        void remover(Entidades::Entidades* entidade);
        int getTam();
        void limpar();
        Entidades::Entidades* operator[](int pos);  
        void atualizar(float dt);
        void desenhar();
    };
};