#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Espinho : public Obstaculo
    {
    private:
        float afiado; //TODO: Implementar dano
        
    public:
        Espinho(sf::Vector2f pos, sf::Vector2f tam);
        Espinho();
        ~Espinho();

        void atualizar(float dt);
        float getAfiado();
    };
};