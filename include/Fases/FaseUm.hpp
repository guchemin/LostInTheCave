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

        void criarMapa();

        void atualizar(float dt);
        void desenhar();
        void executar();
    };
    
    
};