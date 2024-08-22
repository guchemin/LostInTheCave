#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Espinho : public Obstaculo
    {
    private:
        float afiado;
        
    public:
        Espinho(sf::Vector2f pos);
        Espinho();
        ~Espinho();

        void atualizar(float dt);
        float getAfiado();
    };
};