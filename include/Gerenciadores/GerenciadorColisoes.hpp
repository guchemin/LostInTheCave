#pragma once

#include "../Listas/ListaEntidades.hpp"
#include "../Entidades/Personagem/Inimigo.hpp"
#include "../Entidades/Personagem/Jogador.hpp"
#include "../Entidades/Obstaculos/Plataforma.hpp"
#include "../Entidades/Projetil.hpp"

using namespace Listas;

namespace Gerenciadores
{
    class GerenciadorColisoes
    {
    private:
        Listas::ListaEntidades* listaJogadores;
        Listas::ListaEntidades* listaInimigos;
        Listas::ListaEntidades* listaObstaculos;
        Listas::ListaEntidades* listaProjeteis;

    public:
        GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li, Listas::ListaEntidades* lo, Listas::ListaEntidades* lp);
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        void verificarColisoes();
    };
};