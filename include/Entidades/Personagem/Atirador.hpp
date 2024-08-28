#pragma once

#include "../Projetil.hpp"
#include "../../Gerenciadores/GerenciadorGrafico.hpp"

#define RAIO_ATIRADOR 600.0f
#define VEL_PROJ 420.0f

#define CAMINHO_ATIRADOR_PARADO "../assets/sprites/Atirador/Parado.png"
#define CAMINHO_ATIRADOR_ATACANDO "../assets/sprites/Atirador/Atacando.png"
#define TEMPO_TOTAL_ATAQUE_ATIRADOR 0.45f

namespace Entidades
{
    namespace Personagem
    {
        class Atirador: public Inimigo::Inimigo
        {
        private:
            Projetil* pProjetil;

        public:
            Atirador(sf::Vector2f pos);
            Atirador();
            ~Atirador();

            void inicializarAnimacao();
            void atualizarAnimacao();
            void setProjetil(Projetil* proj);
            bool consegueAtacar();
            void atacar();
            void agir();
            void executar(const float dt);
            sf::Vector2f calcVel();
            float getPontuacao();
        };
    }
}