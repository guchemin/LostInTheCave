#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Espinho : public Obstaculo
    {
    private:
        const float afiado;
        
    public:
        Espinho(sf::Vector2f pos);
        Espinho();
        ~Espinho();

        const float getAfiado() const;
    };
};