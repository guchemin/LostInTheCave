/*
FaseUm.hpp - Filha de Fase
----------------------------------------------------
 * Padrão de projeto Builder.
*/

#pragma once

#include "Fase.hpp"

#define BACKGROUND_FASE1 "../assets/sprites/Backgrounds/Background1.png"
#define TAMANHO_MAPA_1 8400.0f

#define MAX_VOADOR 3
#define MAX_ESPINHO 3
#define MAX_ATIRADOR 3
#define MAX_TEIA 3

namespace Estados
{
    namespace Fases
    {
        class FaseUm : public Fase
        {
        private:
            const int numVoador;
            const int numEspinho;

        public:
            FaseUm(bool carregar);
            FaseUm();
            ~FaseUm();

            void criarMapa();
            void criarAleatorios();
            void criarEntidade(sf::Vector2f pos, char caracter);
            void criarVoador(sf::Vector2f pos);
            void criarEspinho(sf::Vector2f pos);
            void atualizarTextos();
            void verificarFimDeJogo();
            void centralizarCamera();
            void executar(const float dt);
            void desenhar();
            void executar();
        };    
    }
}