#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Plataforma: public Obstaculo
    {
    private:
        const bool ehFalsa;
        
    public:
        Plataforma(sf::Vector2f pos);
        Plataforma();
        ~Plataforma();

        const bool getFalsa() const;
    };
};