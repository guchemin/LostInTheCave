#pragma once
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;

namespace Observadores { class Observador; };

using namespace Observadores;

namespace Gerenciadores
{
    class GerenciadorInputs
    {
    private:
        list<Observador*> observadores;

        static GerenciadorInputs* instancia;
        GerenciadorInputs();

    public:
        ~GerenciadorInputs();
        
        static GerenciadorInputs* getInstancia();
        void adicionarObservador(Observador* pObs);
        void removerObservador(Observador* pObs);
        void teclaPressionada(sf::Keyboard::Key tecla);
        void teclaSolta(sf::Keyboard::Key tecla);
    };
};