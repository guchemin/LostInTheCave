#pragma once

#include "Obstaculo.hpp"

#define CAMINHO_TEXTURA_ESPINHO "../assets/sprites/Espinho/Espinho.png"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
        private:
            const float afiado;
            
        public:
            Espinho(sf::Vector2f pos);
            Espinho();
            ~Espinho();

            const float getAfiado() const;
        };
    }
}