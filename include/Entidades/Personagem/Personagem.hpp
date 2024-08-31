/*
Personagem.hpp - Filha de Entidade - Classe Abstrata
*/

#pragma once

#include "../Entidade.hpp"
#include "../../Animacoes/Animacao.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades;

#define TEMPO_TOMOU_DANO 0.3f
#define TEMPO_TOTAL_ATAQUE 0.42f

namespace Entidades
{
    namespace Personagem
    {
        class Personagem: public Entidade
        {
        protected:
            sf::Vector2f vel;
            bool estaNoChao;
            bool direcao;
            float vida;
            float raioAtaque;
            float dano;
            float tempoAtaque;
            float tempoAnimacaoAtaque;
            bool iniciouAtaque;
            bool atacando;
            bool tomouDano;
            float tempoTomouDano;
            Animacoes::Animacao animacao;

        protected:
            virtual void inicializarAnimacao() = 0;
            virtual void atualizarAnimacao() = 0;
            
        public:
            Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
            Personagem();
            virtual ~Personagem();

            virtual nlohmann::json salvarJogo();
            void setAtacando(const bool atk);
            void setDirecao(const bool dir);
            void setVida(const float vd);
            void setVelocidade(const sf::Vector2f v);
            void operator-=(const float dano);
            float getVida();
            float getRaioAtaque();
            float getDano();

            virtual void executar(const float dt) = 0;
            virtual void colide(Entidade* ent, const sf::Vector2f intersec) = 0;
        };
    }
}