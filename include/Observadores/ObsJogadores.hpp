#pragma once

#include "Observador.hpp"

class Jogador;

#define DIREITA 1
#define ESQUERDA 0

namespace Observadores 
{
    class ObsJogadores : public Observador 
    {
    private:
        Jogador* pJog;
        
        sf::Keyboard::Key direita;
        sf::Keyboard::Key esquerda;
        sf::Keyboard::Key pulo;
        sf::Keyboard::Key ataque;
        sf::Keyboard::Key pausa;
        
    public:
        ObsJogadores(Jogador* pJ);
        ObsJogadores();
        ~ObsJogadores();

        void notificarPressionada(const sf::Keyboard::Key tecla);
        void notificarSolta(const sf::Keyboard::Key tecla);
    };
}