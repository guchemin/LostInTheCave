#include "../../include/Gerenciadores/Graficos.hpp"

using namespace Gerenciadores;

//padrao Singleton
Graficos* Graficos::instancia = NULL;

Graficos *Gerenciadores::Graficos::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Graficos();
    }
    return instancia;
}

sf::RenderWindow *Gerenciadores::Graficos::getJanela()
{
    return window;
}

Graficos::Graficos():
window(new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo"))
{
}

Graficos::~Graficos()
{
    delete (window);
}

void Graficos::limpar()
{
    window->clear();
}

void Graficos::desenhar(sf::RectangleShape desenho)
{
    window->draw(desenho);
}

void Graficos::mostrar()
{
    window->display();
}

bool Graficos::estaAberta()
{
    return window->isOpen();
}

void Graficos::fecharJanela()
{
    window->close();
}

void Gerenciadores::Graficos::verificaSeFechou()
{
    sf::Event evento;
    while(window->pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
        {
            window->close();
        }
    }
}
