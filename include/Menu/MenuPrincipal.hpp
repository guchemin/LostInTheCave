#pragma once

#include "Menu.hpp"

namespace Menu
{
    class MenuPrincipal : public Menu
    {
    private:

    public:
        MenuPrincipal();
        ~MenuPrincipal();

        void criarBotoes();
        void selecionar(TipoBotao tipo);
    };
}