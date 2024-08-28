#pragma once

#include "Menu.hpp"
#include "../Fases/Fase.hpp"

namespace Estados
{
    namespace Menu 
    {
        class MenuFim : public Menu 
        {
        private:
            Fases::Fase* fase;
            sf::RectangleShape painel;

        public:
            MenuFim(Fases::Fase* f);
            MenuFim();
            ~MenuFim();

            void criarBotoes();
            void setFase(Fases::Fase* f);
            Fases::Fase* getFase();
            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}