#pragma once

#include "../Entidades.hpp"

namespace Obstaculos
{
    class Espinho : public Entidades::Entidades
    {
    private:
        float afiado; //TODO: Implementar dano
        
    public:
        Espinho(sf::Vector2f pos, sf::Vector2f tam);
        Espinho();
        ~Espinho();

        void atualizar(float dt);
    };
};