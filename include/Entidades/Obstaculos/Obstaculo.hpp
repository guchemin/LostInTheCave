#pragma once

#include "../Entidade.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo: public Entidade
        {
        protected:
            bool danoso;
            float velY;
            
        public:
            Obstaculo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
            Obstaculo();
            ~Obstaculo();
            
            bool getDanoso();

            virtual void colide(Entidade* ent, const sf::Vector2f intersec);
            virtual void executar(const float dt);
        };
    }
}