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

Eventos::Eventos() : pGraf(Graficos::getInstancia())
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

void Eventos::verificarTeclaPessionada(sf::Keyboard::Key tecla)
{
    if(pJog1 != NULL)
    {
        if(tecla == sf::Keyboard::Key::W && pJog1->podePular())
        {
            pJog1->autorizarPulo(false);
            pJog1->pular(dt);
        }
        if(tecla == sf::Keyboard::Key::A)
        {
            pJog1->andarParaEsquerda(dt);
        }
        else if(tecla == sf::Keyboard::Key::D)
        {
            pJog1->andarParaDireita(dt);
        }
    }

    if(pJog2 != NULL)
    {
        if(tecla == sf::Keyboard::Key::Up && pJog2->podePular())
        {
            pJog2->autorizarPulo(false);
            pJog2->pular(dt);
        }

        if(tecla == sf::Keyboard::Key::Left)
        {
            pJog2->andarParaEsquerda(dt);
        }
        else if(tecla == sf::Keyboard::Key::Right)
        {
            pJog2->andarParaDireita(dt);
        }
    }
}

void Eventos::verificarTeclaSolta(sf::Keyboard::Key tecla)
{
    if(pJog1 != NULL)
    {
        if(tecla == sf::Keyboard::Key::W)
        {
            pJog1->autorizarPulo(true);
        }
    }

    if(pJog2 != NULL)
    {
        if(tecla == sf::Keyboard::Key::Up)
        {
            pJog2->autorizarPulo(true);
        }
    }
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

void Eventos::verificarEventos(float t)
{
    dt = t;
    sf::Event evento;
    while(pGraf->getJanela()->pollEvent(evento))
    {
        if (evento.type == sf::Event::Closed)
        {
            pGraf->fecharJanela();
        }
        else if(evento.type == sf::Event::KeyPressed)
        {
            verificarTeclaPessionada(evento.key.code);
        }
        else if(evento.type == sf::Event::KeyReleased)
        {
            verificarTeclaSolta(evento.key.code);
        }
        verificaSeParou();
    }
}
