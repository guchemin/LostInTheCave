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

        public:
            MenuPausa(Fases::Fase* f);
            MenuPausa();
            ~MenuPausa();

            void criarBotoes();
            void setFase(Fases::Fase* f);
            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}