/*
Obstaculo.hpp - Filha de Entidade - Classe Abstrata
*/

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
            
            virtual nlohmann::json salvarJogo();
            void setDanoso(const bool dan);
            bool getDanoso();
            void setVelY(const float vy);
            virtual void colide(Entidade* ent, const sf::Vector2f intersec);
            virtual void executar(const float dt);
        };
    }
}