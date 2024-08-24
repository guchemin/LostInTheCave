#pragma once

#include "Obstaculo.hpp"

namespace Obstaculos
{
    class Pedra : public Obstaculo
    {
    private:
        const float peso;
        float dx;
        
    public:
        Pedra(sf::Vector2f pos);
        Pedra();
        ~Pedra();

        const float getPeso() const;
        void arrastar(const bool direita);
        void colide(Entidade* ent, const sf::Vector2f intersec);
    };
};