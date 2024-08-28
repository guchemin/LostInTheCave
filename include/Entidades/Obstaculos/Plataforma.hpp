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
            const bool ehFalsa;
            const float empuxo;
            sf::Vector2f vel;
            
        public:
            Plataforma(sf::Vector2f pos, sf::Vector2f tam);
            Plataforma();
            ~Plataforma();

            const bool getFalsa() const;
            void executar(const float dt);
        };
    }
}