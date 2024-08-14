#include "../../include/Observadores/Observador.hpp"

using namespace Gerenciadores;
using namespace Observadores;

Inputs* Inputs::instancia = NULL;

Inputs *Inputs::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Inputs();
    }
    return instancia;
}

Inputs::Inputs():
observadores()
{
    observadores.clear();
}

Inputs::~Inputs()
{
    list<Observador*>::iterator it;
    for(it = observadores.begin(); it != observadores.end(); it++)
    {
        if(*it)
            delete (*it);
    }
    observadores.clear();
}

void Inputs::adicionarObservador(Observador* pObs)
{
    if(pObs)
    {    
        observadores.push_back(pObs);
    }
}

void Inputs::removerObservador(Observador* pObs)
{
    if(pObs)
    {
        observadores.remove(pObs);
    }
}

void Inputs::teclaPressionada(sf::Keyboard::Key tecla)
{
    list<Observador*>::iterator it;
    for(it = observadores.begin(); it != observadores.end(); it++)
    {
        if(*it)
        {
            (*it)->notificarPressionada(tecla);
        }
    }
}

void Gerenciadores::Inputs::teclaSolta(sf::Keyboard::Key tecla)
{
    list<Observador*>::iterator it;
    for(it = observadores.begin(); it != observadores.end(); it++)
    {
        if(*it)
        {
            (*it)->notificarSolta(tecla);
        }
    }
}
