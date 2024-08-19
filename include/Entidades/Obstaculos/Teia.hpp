#pragma once

#include "../Entidades.hpp"

namespace Obstaculos
{
    class Teia : public Entidades::Entidades
    {
    private:
        float densidade; //TODO: Implementar lentidão
        
    public:
        Teia(sf::Vector2f pos, sf::Vector2f tam);
        Teia();
        ~Teia();

        void atualizar(float dt);
    };
};