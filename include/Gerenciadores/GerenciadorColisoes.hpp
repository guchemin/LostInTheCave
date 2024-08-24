#pragma once

#include "../Listas/ListaEntidades.hpp"
#include "../Entidades/Personagem/Inimigo.hpp"
#include "../Entidades/Personagem/Jogador.hpp"
#include "../Entidades/Plataforma.hpp"
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
        Listas::ListaEntidades* listaPlataformas;

    public:
        GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li, Listas::ListaEntidades* lpl,
                            Listas::ListaEntidades* lo, Listas::ListaEntidades* lp);
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        void verificarColisoes();
    };
};