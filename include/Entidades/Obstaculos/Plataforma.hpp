#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Plataforma: public Obstaculo
    {
    private:
        
    public:
        Plataforma(sf::Vector2f pos);
        Plataforma();
        ~Plataforma();

        void atualizar(float dt);
    };
};