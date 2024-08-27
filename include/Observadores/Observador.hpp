#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorInputs.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"

using namespace Gerenciadores;

namespace Observadores
{
    class Observador
    {
    protected:
        GerenciadorInputs* pInp;
        GerenciadorEstados* pEstados;
        map<sf::Keyboard::Key, char> teclado;
        map<sf::Keyboard::Key, string> tecladoEspecial;

    public:
        Observador();
        virtual ~Observador();

        void inicializaTeclado();
        virtual void notificarPressionada(const sf::Keyboard::Key tecla) = 0;
        virtual void notificarSolta(const sf::Keyboard::Key tecla) = 0;
    };
}; 