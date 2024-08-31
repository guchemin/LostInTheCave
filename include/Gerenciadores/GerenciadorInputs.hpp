/*
GerenciadorInputs.hpp
----------------------------------------------------
 * Gerencia os inputs do jogo.
 * Padrão de projeto Observer (faz o papel do subject).
 * Padrão de projeto Singleton.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <list>
using namespace std;

namespace Observadores { class Observador; };

namespace Gerenciadores
{
    class GerenciadorInputs
    {
    private:
        list<Observadores::Observador*> observadores;

        static GerenciadorInputs* instancia;
        GerenciadorInputs();

    public:
        ~GerenciadorInputs();
        
        static GerenciadorInputs* getInstancia();
        void adicionarObservador(Observadores::Observador* pObs);
        void removerObservador(Observadores::Observador* pObs);
        void teclaPressionada(sf::Keyboard::Key tecla);
        void teclaSolta(sf::Keyboard::Key tecla);
    };
};