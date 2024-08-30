/*
Plataforma.hpp - Filha de Obstaculo
*/

#pragma once

#include "Obstaculo.hpp"

#define CAMINHO_TEXTURA_PAREDE "../assets/sprites/Plataforma/Parede.png"
#define CAMINHO_TEXTURA_CHAO "../assets/sprites/Plataforma/Chao.png"
#define CAMINHO_TEXTURA_FALSO "../assets/sprites/Plataforma/Falso.png"

namespace Entidades
{
    namespace Obstaculos
    {
        class Plataforma: public Obstaculo
        {
        private:
            bool ehFalsa;
            const float empuxo;
            
        public:
            Plataforma(sf::Vector2f pos, sf::Vector2f tam);
            Plataforma();
            ~Plataforma();

            virtual nlohmann::json salvarJogo();
            void setFalsa(const bool falsa);
            const bool getFalsa() const;
            void executar(const float dt);
        };
    }
}