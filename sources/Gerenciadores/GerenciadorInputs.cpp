#include "../../include/Observadores/Observador.hpp"

using namespace Gerenciadores;
using namespace Observadores;

GerenciadorInputs* GerenciadorInputs::instancia = NULL;

GerenciadorInputs *GerenciadorInputs::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new GerenciadorInputs();
    }
    return instancia;
}

GerenciadorInputs::GerenciadorInputs():
observadores()
{
    observadores.clear();
}

GerenciadorInputs::~GerenciadorInputs()
{
    list<Observador*>::iterator it;
    for(it = observadores.begin(); it != observadores.end(); it++)
    {
        if(*it)
            delete (*it);
    }
    observadores.clear();
}

void GerenciadorInputs::adicionarObservador(Observador* pObs)
{
    if(pObs)
    {    
        observadores.push_back(pObs);
    }
}

void GerenciadorInputs::removerObservador(Observador* pObs)
{
    if(pObs)
    {
        observadores.remove(pObs);
    }
}

void GerenciadorInputs::teclaPressionada(sf::Keyboard::Key tecla)
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

void Gerenciadores::GerenciadorInputs::teclaSolta(sf::Keyboard::Key tecla)
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
