#pragma once

#include "Fase.hpp"

#define BACKGROUNG_FASE1 "../assets/sprites/Backgrounds/Background1.png"
#define TAMANHO_MAPA_X 8400.0f

namespace Fases
{
    class FaseUm : public Fase
    {
    private:
        // Entidades::Chave* chave; essa é a chave necessaria para passar de fase

    public:
        FaseUm();
        ~FaseUm();

        void criarMapa();

        void centralizarCamera();
        void atualizar(const float dt);
        void desenhar();
        void executar();
    };
    
    
};