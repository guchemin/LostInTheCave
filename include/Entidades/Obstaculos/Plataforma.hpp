#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Plataforma: public Obstaculo
    {
    private:
        
    public:
        Plataforma(sf::Vector2f pos, sf::Vector2f tam);
        Plataforma();
        ~Plataforma();

        void atualizar(float dt);
    };
};