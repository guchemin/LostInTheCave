#include "../../include/Gerenciadores/GerenciadorEventos.hpp"

using namespace Gerenciadores;

//padrao Singleton
GerenciadorEventos* GerenciadorEventos::instancia = NULL;

GerenciadorEventos* GerenciadorEventos::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new GerenciadorEventos();
    }
    return instancia;
}

GerenciadorEventos::GerenciadorEventos(): 
pGraf(GerenciadorGrafico::getInstancia()),
pInp(GerenciadorInputs::getInstancia())
{
    pJog1 = NULL;
    pJog2 = NULL;
}

void Gerenciadores::GerenciadorEventos::setJogador(Jogador *pJog)
{
    if(pJog->getId() == ID::JOGADOR1)
    {
        pJog1 = pJog;
    }
    else if(pJog->getId() == ID::JOGADOR2)
    {
        pJog2 = pJog;
    }
}

GerenciadorEventos::~GerenciadorEventos()
{
    pJog1 = NULL;
    pJog2 = NULL;
}

void Gerenciadores::GerenciadorEventos::verificaSeParou()
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

void GerenciadorEventos::verificarEventos()
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