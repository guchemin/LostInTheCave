#pragma once

#include "../Jogador/Jogador.hpp"

namespace Inimigo
{
    class Inimigo: public Personagem
    {
    protected:
        Jogador::Jogador* pJogador;
        sf::Vector2f posInicial;

    public:
        Inimigo(sf::Vector2f pos, sf::Vector2f tam);
        Inimigo();
        ~Inimigo();

        void setpJogador(Jogador::Jogador* pJ);
        sf::Vector2f getPosJogador();
        virtual void atacar() = 0;
        virtual void atualizar(float dt) = 0;
        virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0;
    };
};

