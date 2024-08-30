/*
Jogador.hpp - Filha de Personagem
*/

#pragma once

#include <iostream>
#include "../Obstaculos/Plataforma.hpp"
#include "../Obstaculos/Espinho.hpp"
#include "../Obstaculos/Teia.hpp"
#include "../Obstaculos/Pedra.hpp"
#include "Personagem.hpp"
#include "../../Observadores/ObsJogadores.hpp"

#define VEL_JOG1 300.0f
#define VEL_JOG2 300.0f
#define PULO_JOG1 1650.0f
#define PULO_JOG2 1650.0f

#define COOLDOWN_ATAQUE 1.0f
#define DANO_JOGADOR 15.0f

#define CAMINHO_JOG1_ANDANDO "../assets/sprites/Jogador1/Andando.png"
#define CAMINHO_JOG1_PARADO "../assets/sprites/Jogador1/Parado.png"
#define CAMINHO_JOG1_ATACANDO "../assets/sprites/Jogador1/Atacando.png"
#define CAMINHO_JOG1_NO_AR "../assets/sprites/Jogador1/NoAr.png"

#define CAMINHO_JOG2_ANDANDO "../assets/sprites/Jogador2/Andando.png"
#define CAMINHO_JOG2_PARADO "../assets/sprites/Jogador2/Parado.png"
#define CAMINHO_JOG2_ATACANDO "../assets/sprites/Jogador2/Atacando.png"
#define CAMINHO_JOG2_NO_AR "../assets/sprites/Jogador2/NoAr.png"

namespace Entidades
{
    namespace Personagem
    {
        enum ID
        {
            JOGADOR1,
            JOGADOR2
        };

        class Jogador: public Personagem
        {
        private:
            const ID id;
            sf::Vector2f ds;
            bool pulou;
            bool estaNaTeia;
            float aceleracaoTeia;
            bool foiEspinhado;
            Observadores::ObsJogadores obs;
            static float pontuacao;

        public:
            Jogador(sf::Vector2f pos, const ID i);
            Jogador();
            ~Jogador();

            virtual nlohmann::json salvarJogo();
            void inicializarAnimacao();
            void atualizarAnimacao();
            void autorizarPulo(const bool autoriza);
            bool podePular();
            void parouDeAtacar();
            const ID getId() const { return id; };
            const bool podeAtacar(bool direita);
            void pular();
            void setPulou(const bool p);
            void andar(const bool direita);
            void parar();
            void ajustarVelocidade();
            void setEspinhado(const bool esp);
            void setNaTeia(const bool teia);
            void desacelerarTeia();
            static float getPontuacao();
            static void somaPontos(const float p); //fazer com operator+=
            static void setPontuacao(const float p);

            void executar(const float dt);
            void colide(Entidade* ent, const sf::Vector2f intersec);
        };
    }
}