/*
MenuFim.hpp - Filha da classe Menu
*/

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

        private:
            void criarBotoes();

        public:
            MenuFim(Fases::Fase* f);
            MenuFim();
            ~MenuFim();

            void setFase(Fases::Fase* f);
            Fases::Fase* getFase();
            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}