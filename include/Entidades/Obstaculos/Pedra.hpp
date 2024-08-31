/*
Pedra.hpp - Filha de Obstaculo
*/

#pragma once

#include "Obstaculo.hpp"

#define CAMINHO_TEXTURA_PEDRA "../assets/sprites/Pedra/Pedra.png"

namespace Entidades
{
    namespace Obstaculos
    {
        class Pedra : public Obstaculo
        {
        private:
            float peso;
            float dx;
            
        public:
            Pedra(sf::Vector2f pos);
            Pedra();
            ~Pedra();

            nlohmann::json salvarJogo();
            void setDx(const float x);
            void setPeso(const float p);    
            const float getPeso() const;
            void arrastar(const bool direita);
            void colide(Entidade* ent, const sf::Vector2f intersec);
        };
    }
}