/*
MenuPausa.hpp - Filha da classe Menu
*/

#pragma once

#include "Menu.hpp"
#include "../Fases/Fase.hpp"

namespace Estados
{
    namespace Menu
    {
        class MenuPausa : public Menu
        {
        private:
            Fases::Fase* fase;
            sf::RectangleShape painel;

        private:
            void criarBotoes();

        public:
            MenuPausa(Fases::Fase* f);
            MenuPausa();
            ~MenuPausa();

            void setFase(Fases::Fase* f);
            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}