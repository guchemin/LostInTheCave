#pragma once

#include "Fase.hpp"

namespace Fases
{
    class FaseUm : public Fase
    {
    private:
        
    public:
        FaseUm();
        ~FaseUm();

        void inicializar();
        void inicializarJogadores();
        void inicializarInimigos();
        void inicializarObstaculos();

        void atualizar(float dt);
        void desenhar();
        void executar();
    };
    
    
};