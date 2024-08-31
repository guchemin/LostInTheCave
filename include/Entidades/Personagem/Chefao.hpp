/*
Chefao.hpp - Filha de Inimigo
*/

#pragma once

#include "Inimigo.hpp"

#define RAIO_CHEFAO_X 500.0f
#define RAIO_CHEFAO_Y 150.0f
#define RAIO_ATAQUE_CHEFAO 75.0f
#define VEL_CHEFAO 75.0f
#define VEL_CHEFAO_PERSEG 150.0f

#define CAMINHO_CHEFAO_ANDANDO "../assets/sprites/Chefao/Andando.png"
#define CAMINHO_CHEFAO_ATACANDO "../assets/sprites/Chefao/Atacando.png"
#define CAMINHO_CHEFAO_CORRENDO "../assets/sprites/Chefao/Correndo.png"
#define TEMPO_MUDANCA_DIRECAO 6.0f
#define TEMPO_BATIDA 0.175f

namespace Entidades
{
    namespace Personagem
    {
        class Chefao: public Inimigo::Inimigo
        {
        private:
            bool estaPerseguindo;
            float tempoMudancaDirecao;

        private:
            void inicializarAnimacao();
            void atualizarAnimacao();
            void perseguir(const float dt);
            void moverAleatorio(const float dt);
            void ajustaVelocidade();
            void atacar();

        public:
            Chefao(sf::Vector2f pos);
            Chefao();
            ~Chefao();

            nlohmann::json salvarJogo();
            void setPerseguindo(bool perseg);
            bool consegueAtacar();
            void agir();
            const float getPontuacao() const;
            
            void executar(const float dt);
            void colide(Entidade *ent, const sf::Vector2f intersec);            
        };
    }
}