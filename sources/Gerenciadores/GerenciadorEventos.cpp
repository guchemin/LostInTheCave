#include "../../include/Gerenciadores/GerenciadorEventos.hpp"

namespace Gerenciadores
{
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
    }

    GerenciadorEventos::~GerenciadorEventos()
    {
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
        }
    }
}