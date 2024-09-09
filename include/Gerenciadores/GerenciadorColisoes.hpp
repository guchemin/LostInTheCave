/*
GerenciadorColisoes.hpp
----------------------------------------------------
 * Inspirado em: https://github.com/MatheusBurda/Desert
 * Classe que gerencia as colisões entre as entidades do jogo.
 * Padrão de projeto Mediator.
*/

#pragma once

#include "../Listas/ListaEntidades.hpp"
#include "../Entidades/Personagem/Inimigo.hpp"
#include "../Entidades/Personagem/Jogador.hpp"
#include "../Entidades/Obstaculos/Plataforma.hpp"
#include "../Entidades/Projetil.hpp"


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

    private:

        void colidePlataforma();
        void colideJogador();
        void colideObstaculo();
        void colideInimigo();
        void colideProjetil();

    public:
        GerenciadorColisoes(Listas::ListaEntidades* lj, Listas::ListaEntidades* li, Listas::ListaEntidades* lpl,
                            Listas::ListaEntidades* lo, Listas::ListaEntidades* lp);
        GerenciadorColisoes();
        ~GerenciadorColisoes();

        void verificarColisoes();
    };
};