#pragma once

#include "../Entidade.hpp"

using namespace Entidades;

namespace Obstaculos
{
    class Obstaculo: public Entidade
    {
    private:
        bool danoso;
        
    public:
        Obstaculo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
        Obstaculo();
        ~Obstaculo();
        
        bool getDanoso();
    };
}

