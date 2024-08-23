#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorInputs.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"

using namespace Gerenciadores;

namespace Observadores
{
    class Observador
    {
    private:
        GerenciadorInputs* pInp;

    protected:
        GerenciadorEstados* pEstados;

    public:
        Observador();
        virtual ~Observador();

        virtual void notificarPressionada(const sf::Keyboard::Key tecla) = 0;
        virtual void notificarSolta(const sf::Keyboard::Key tecla) = 0;
    };
}; 