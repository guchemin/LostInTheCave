#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Teia : public Obstaculo
    {
    private:
        const float densidade;
        
    public:
        Teia(sf::Vector2f pos);
        Teia();
        ~Teia();

        const float getDensidade() const;
    };
};