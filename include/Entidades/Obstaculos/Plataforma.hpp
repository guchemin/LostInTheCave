#pragma once

#include "../Entidades.hpp"

namespace Obstaculos
{
    class Plataforma: public Entidades::Entidades
    {
    private:
        
    public:
        Plataforma(sf::Vector2f pos, sf::Vector2f tam);
        Plataforma();
        ~Plataforma();

        void atualizar(float dt);
    };
};