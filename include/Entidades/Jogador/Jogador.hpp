#pragma once

#include <iostream>

#include "../Entidades.hpp"

namespace Jogador
{
    enum ID
    {
        JOGADOR1,
        JOGADOR2
    };

    class Jogador: public Entidades::Entidades
    {
    private:
        sf::Vector2f vel;
        ID id;
        bool estaNoChao = false;

    public:
        Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i);
        Jogador();
        ~Jogador();
    
        void mover(float dt);
        void colide(Entidades* ent, sf::Vector2f intersec);
    };

};