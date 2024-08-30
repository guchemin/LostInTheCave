/*
FaseDois.hpp - Filha de Fase
----------------------------------------------------
 * Padrão de projeto Builder.
*/

#pragma once

#include "Fase.hpp"

#define MAX_PEDRA 3
#define MAX_CHEFAO 2
#define MAX_ATIRADOR 3
#define MAX_TEIA 3
#define BACKGROUND_FASE2 "../assets/sprites/Backgrounds/Background1.png"
#define TAMANHO_MAPA_X 8150.0f

namespace Estados
{
    namespace Fases
    {
        class FaseDois : public Fase
        {
            private:
                const int numPedra;
                const int numChefao;
                Entidades::Personagem::Jogador* pJog1;
                Entidades::Personagem::Jogador* pJog2;
                bool sequencial; //usado apenas se a fase for sequencial
            
            public:
                FaseDois(bool carregar);
                FaseDois();
                ~FaseDois();

                void criarMapa();
                void criarAleatorios();
                void criarEntidade(sf::Vector2f pos, char caracter);
                void criarPedra(sf::Vector2f pos);
                void criarChefao(sf::Vector2f pos);
                void atualizarTextos();
                void verificarFimDeJogo();
                void centralizarCamera();
                void executar(const float dt);
                void desenhar();
                void executar();
        }; 
    }
}