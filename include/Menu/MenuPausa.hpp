#pragma once

#include "Menu.hpp"
#include "../Fases/Fase.hpp"

namespace Menu
{
    class MenuPausa : public Menu
    {
    private:
        Fases::Fase* fase;
        sf::RectangleShape filtro;
        sf::RectangleShape fundo;

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