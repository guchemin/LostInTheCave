#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/Inputs.hpp"

using namespace Gerenciadores;

namespace Observadores
{
    class Observador
    {
    private:
        Inputs* pInp;

    public:
        Observador();
        virtual ~Observador();

        virtual void notificarPressionada(sf::Keyboard::Key tecla) = 0;
        virtual void notificarSolta(sf::Keyboard::Key tecla) = 0;
    };
}; 