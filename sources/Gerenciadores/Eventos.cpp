#include "../../include/Gerenciadores/Eventos.hpp"

using namespace Gerenciadores;

//padrao Singleton
Eventos* Eventos::instancia = NULL;

Eventos* Eventos::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Eventos();
    }
    return instancia;
}

Eventos::Eventos(): 
pGraf(Graficos::getInstancia()),
pInp(Inputs::getInstancia())
{
    pJog1 = NULL;
    pJog2 = NULL;
}

void Gerenciadores::Eventos::setJogador(Jogador::Jogador *pJog)
{
    if(pJog->getId() == Jogador::ID::JOGADOR1)
    {
        pJog1 = pJog;
    }
    else if(pJog->getId() == Jogador::ID::JOGADOR2)
    {
        pJog2 = pJog;
    }
}

Eventos::~Eventos()
{
    pJog1 = NULL;
    pJog2 = NULL;
}

void Gerenciadores::Eventos::verificaSeParou()
{
    if(pJog1 != NULL)
    {
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)))
        {
            pJog1->parar();
        }
    }
    if(pJog2 != NULL)
    {
        if(!(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
        {
            pJog2->parar();
        }
    }
}

void Eventos::verificarEventos()
{
    while(pGraf->getJanela()->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed || (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape))
        {
            pGraf->fecharJanela();
        }
        else if(evento.type == sf::Event::KeyPressed)
        {
            pInp->teclaPressionada(evento.key.code);
        }
        else if(evento.type == sf::Event::KeyReleased)
        {
            pInp->teclaSolta(evento.key.code);
        }
        verificaSeParou();
    }
}