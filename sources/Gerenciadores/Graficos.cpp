#include "../../include/Gerenciadores/Graficos.hpp"

using namespace Gerenciadores;

//padrao Singleton
Graficos* Graficos::instancia = NULL;

Graficos* Graficos::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Graficos();
    }
    return instancia;
}

sf::RenderWindow* Graficos::getJanela()
{
    return janela;
}

Graficos::Graficos():
janela(new sf::RenderWindow(sf::VideoMode(800, 600), "LOST IN THE CAVE"))
{
}

Graficos::~Graficos()
{
    delete (janela);
}

void Graficos::limpar()
{
    janela->clear();
}

void Graficos::desenhar(sf::RectangleShape desenho)
{
    janela->draw(desenho);
}

void Graficos::desenhar(sf::CircleShape desenho)
{
    janela->draw(desenho);
}

void Graficos::mostrar()
{
    janela->display();
}

bool Graficos::estaAberta()
{
    return janela->isOpen();
}

void Graficos::fecharJanela()
{
    janela->close();
}

void Graficos::verificaSeFechou()
{
    sf::Event evento;
    while(janela->pollEvent(evento))
    {
        if(evento.type == sf::Event::Closed)
        {
            janela->close();
        }
    }
}
