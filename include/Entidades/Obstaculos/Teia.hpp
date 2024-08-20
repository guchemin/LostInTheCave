#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Teia : public Obstaculo
    {
    private:
        float densidade; //TODO: Implementar lentidao
        
    public:
        Teia(sf::Vector2f pos, sf::Vector2f tam);
        Teia();
        ~Teia();

        void atualizar(float dt);
        float getDensidade();
    };
};