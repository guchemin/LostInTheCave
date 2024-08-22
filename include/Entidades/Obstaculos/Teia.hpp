#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Teia : public Obstaculo
    {
    private:
        float densidade;
        
    public:
        Teia(sf::Vector2f pos);
        Teia();
        ~Teia();

        void atualizar(float dt);
        float getDensidade();
    };
};