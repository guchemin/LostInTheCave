#pragma once

#include "../Entidades.hpp"

namespace Obstaculos
{
    class Espinho : public Entidades::Entidades
    {
    private:
        
    public:
        Espinho(sf::Vector2f pos, sf::Vector2f tam);
        Espinho();
        ~Espinho();
    };
};