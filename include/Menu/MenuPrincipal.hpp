#pragma once

#include "Menu.hpp"

namespace Menu
{
    class MenuPrincipal : public Menu
    {
    private:
        sf::Texture* fundo;

    public:
        MenuPrincipal();
        ~MenuPrincipal();

        void criarBotoes();
        void selecionar(TipoBotao tipo);
    };
}