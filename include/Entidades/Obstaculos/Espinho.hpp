/*
Espinho.hpp - Filha de Obstaculo
*/

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
            float afiado;
            
        public:
            Espinho(sf::Vector2f pos);
            Espinho();
            ~Espinho();

            nlohmann::json salvarJogo();
            void setAfiado(float afd);
            const float getAfiado() const;
        };
    }
}