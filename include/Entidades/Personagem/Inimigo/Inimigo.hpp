#pragma once

#include "../Jogador/Jogador.hpp"
#include "../../../Listas/ListaEntidades.hpp"

#define COOLDOWN_ESQUELETO 1.7f
#define COOLDOWN_GOLEM 1.5f
#define COOLDOWN_MORCEGO 1.0f

namespace Inimigo
{
    class Inimigo: public Personagem
    {
    protected:
        Jogador::Jogador* pJogador;
        sf::Vector2f posInicial;
        float tempoAtaque;
        Listas::ListaEntidades* listaJogadores;

    public:
        Inimigo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog);
        Inimigo();
        ~Inimigo();

        void setJogador();
        sf::Vector2f getPosJogador();
        virtual void atacar() = 0;
        virtual void atualizar(float dt) = 0;
        virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0;
    };
};

