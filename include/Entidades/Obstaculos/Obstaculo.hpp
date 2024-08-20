#pragma once

#include "../Entidades.hpp"

using namespace Entidades;

namespace Obstaculos
{
    class Obstaculo: public Entidades
    {
    private:

    public:
        Obstaculo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
        Obstaculo();
        ~Obstaculo();

        virtual void atualizar(float dt) = 0;
    };
}

