/*
MenuPrincipal.hpp - Filha da classe Menu
*/

#pragma once

#include "Menu.hpp"
#include "../Fases/FaseUm.hpp"
#include "../Fases/FaseDois.hpp"

#define BACKGROUND_FASE1 "../assets/sprites/Backgrounds/Background1.png"
#define BACKGROUND_FASE2 "../assets/sprites/Backgrounds/Background1.png"

namespace Estados
{
    namespace Menu
    {
        class MenuPrincipal : public Menu
        {
        private:
            sf::Texture texturaFundoFaseUm;
            sf::Texture texturaFundoFaseDois;

        public:
            MenuPrincipal();
            ~MenuPrincipal();

            void mudarBackground(TipoBotao tipo);
            Fases::Fase* carregarFase();
            void criarBotoes();
            void selecionar(TipoBotao tipo);
            void executar();
        };
    }
}