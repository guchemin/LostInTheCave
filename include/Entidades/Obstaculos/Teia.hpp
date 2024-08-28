#pragma once

#include "Obstaculo.hpp"

#define CAMINHO_TEXTURA_TEIA "../assets/sprites/Teia/Teia.png"

namespace Entidades
{
    namespace Obstaculos
    {
        class Teia : public Obstaculo
        {
        private:
            const float densidade;
            
        public:
            Teia(sf::Vector2f pos);
            Teia();
            ~Teia();

            const float getDensidade() const;
        };
    }
}