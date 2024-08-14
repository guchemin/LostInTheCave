#pragma once

#include "Observador.hpp"
namespace Jogador { class Jogador; };

#define DIREITA 1
#define ESQUERDA 0

namespace Observadores 
{
    class ObsJogadores : public Observador 
    {
    private:
        Jogador::Jogador* pJog;
        
        sf::Keyboard::Key direita;
        sf::Keyboard::Key esquerda;
        sf::Keyboard::Key pulo;
        sf::Keyboard::Key ataque;
        
    public:
        ObsJogadores(Jogador::Jogador* pJ);
        ~ObsJogadores();

        void notificarPressionada(sf::Keyboard::Key tecla);
        void notificarSolta(sf::Keyboard::Key tecla);
    };
}