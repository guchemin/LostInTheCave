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
            const bool endiabrado; //se for endiabrado ele voa mais rapido

        public:
            Voador(sf::Vector2f pos);
            Voador();
            ~Voador();

            void inicializarAnimacao();
            void atualizarAnimacao();
            bool consegueAtacar();
            bool atingiuJogador();
            void atacar();
            void agir();
            void executar(const float dt);
            void colide(Entidade* ent, const sf::Vector2f intersec);
            const bool getEndiabrado() const;
            float getPontuacao();
        };
    }
}