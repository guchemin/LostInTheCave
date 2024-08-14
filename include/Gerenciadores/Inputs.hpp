#pragma once
#include <SFML/Graphics.hpp>
#include <list>
using namespace std;

namespace Observadores { class Observador; };

using namespace Observadores;

namespace Gerenciadores
{
    class Inputs
    {
    private:
        list<Observador*> observadores;

        static Inputs* instancia;
        Inputs();

    public:
        ~Inputs();
        
        static Inputs* getInstancia();
        void adicionarObservador(Observador* pObs);
        void removerObservador(Observador* pObs);
        void teclaPressionada(sf::Keyboard::Key tecla);
        void teclaSolta(sf::Keyboard::Key tecla);
    };
};