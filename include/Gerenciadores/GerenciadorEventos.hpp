/*
GerenciadorEventos.hpp
----------------------------------------------------
 * Captura os eventos do jogo
 * Padrão de projeto Singleton.
*/

#pragma once

#include "GerenciadorGrafico.hpp"
#include "GerenciadorInputs.hpp"
#include "../Entidades/Personagem/Jogador.hpp"

namespace Gerenciadores
{
    class GerenciadorEventos
    {
    private:
        GerenciadorGrafico* pGraf;
        GerenciadorInputs* pInp;
        sf::Event evento;

        static GerenciadorEventos* instancia;
        GerenciadorEventos();

    public:
        ~GerenciadorEventos();
    
        static GerenciadorEventos* getInstancia();
        void verificarEventos();
    };
};