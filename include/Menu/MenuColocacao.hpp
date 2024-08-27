#pragma once

#include "Menu.hpp"

namespace Menu
{
    class MenuColocacao : public Menu
    {
    private:
        sf::Texture texturaFundo;
        // TODO
    public:
        MenuColocacao();
        ~MenuColocacao();

        void criarBotoes();
        void selecionar(TipoBotao tipo);
        void executar();
    };
}