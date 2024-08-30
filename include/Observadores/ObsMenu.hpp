/*
ObsMenu.hpp - Filha de Observador
*/

#pragma once

#include "Observador.hpp"

namespace Estados { namespace Menu { class Menu; } }

namespace Observadores
{
    class ObsMenu : public Observador
    {
    private:
        Estados::Menu::Menu* pMenu;

        sf::Keyboard::Key cima;
        sf::Keyboard::Key baixo;
        sf::Keyboard::Key enter;

        bool podeSelecionar;

    public:
        ObsMenu(Estados::Menu::Menu* pM);
        ObsMenu();
        ~ObsMenu();

        void notificarPressionada(const sf::Keyboard::Key tecla);
        void notificarSolta(const sf::Keyboard::Key tecla);
    };
}