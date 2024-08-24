#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Pedra : public Obstaculo
    {
    private:
        const float peso;
        
    public:
        Pedra(sf::Vector2f pos);
        Pedra();
        ~Pedra();

        const float getPeso() const;
        void arrastar(const float dx);
    };
};