#pragma once

#include <iostream>

#include "../../Plataforma/Plataforma.hpp"
#include "../Personagem.hpp"

namespace Jogador
{
    enum ID
    {
        JOGADOR1,
        JOGADOR2
    };

    class Jogador: public Personagem
    {
    private:
        ID id;

    public:
        Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i);
        Jogador();
        ~Jogador();
    
        void mover(float dt);
    };

};