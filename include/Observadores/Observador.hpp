#pragma once

#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorInputs.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"
#include <map>
#include <string>

using namespace Gerenciadores;

namespace Observadores
{
    class Observador
    {
    protected:
        GerenciadorInputs* pInp;
        GerenciadorEstados* pEstados;
        map<sf::Keyboard::Key, std::string> keys;
        map<sf::Keyboard::Key, std::string> tecladoEspecial;

    public:
        Observador();
        virtual ~Observador();

        void inicializaTeclado();
        virtual void notificarPressionada(const sf::Keyboard::Key tecla) = 0;
        virtual void notificarSolta(const sf::Keyboard::Key tecla) = 0;
    };
}; 