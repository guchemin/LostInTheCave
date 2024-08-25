#pragma once

#include "Obstaculo.hpp"

#define CAMINHO_TEXTURA_PEDRA "../assets/sprites/Pedra/Pedra.png"

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