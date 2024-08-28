#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorInputs.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"
#include <map>
#include <string>

namespace Observadores
{
    class Observador
    {
    protected:
        Gerenciadores::GerenciadorInputs* pInp;
        Gerenciadores::GerenciadorEstados* pEstados;
        map<sf::Keyboard::Key, std::string> teclado;
        map<sf::Keyboard::Key, std::string> tecladoEspecial;

    public:
        Observador();
        virtual ~Observador();

        void inicializaTeclado();
        virtual void notificarPressionada(const sf::Keyboard::Key tecla) = 0;
        virtual void notificarSolta(const sf::Keyboard::Key tecla) = 0;
    };
}; 