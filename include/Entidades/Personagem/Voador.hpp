/*
Voador.hpp - Filha de Inimigo
*/

#pragma once

#include "Inimigo.hpp"

#define VEL_VOADOR 250.0f
#define CAMINHO_VOADOR "../assets/sprites/Voador/Voando.png"

namespace Entidades
{
    namespace Personagem
    {
        class Voador: public Inimigo::Inimigo
        {
        private:
            bool endiabrado;

        public:
            Voador(sf::Vector2f pos);
            Voador();
            ~Voador();

            virtual nlohmann::json salvarJogo();
            void inicializarAnimacao();
            void atualizarAnimacao();
            bool consegueAtacar();
            bool atingiuJogador();
            void atacar();
            void agir();
            void setEndiabrado(const bool endb);
            const bool getEndiabrado() const;
            float getPontuacao();

            void executar(const float dt);
            void colide(Entidade* ent, const sf::Vector2f intersec);
        };
    }
}