#pragma once

namespace Estados
{
    namespace Fases
    {
        class FaseDois : public Fase
        {
            private:
                const int numPedra;
                const int numChefao;
            
            public:
                FaseDois();
                ~FaseDois();

                void criarMapa();
                void criarAleatorios();
                void criarEntidades(sf::);
        } 
    }
}