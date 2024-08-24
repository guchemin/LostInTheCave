#include "../../include/Gerenciadores/GerenciadorGrafico.hpp"
#include <iostream>

using namespace Gerenciadores;

//padrao Singleton
GerenciadorGrafico* GerenciadorGrafico::instancia = NULL;

GerenciadorGrafico* GerenciadorGrafico::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new GerenciadorGrafico();
    }
    return instancia;
}
GerenciadorGrafico::GerenciadorGrafico()
{
    janela = new sf::RenderWindow(sf::VideoMode(800, 600), "LOST IN THE CAVE");
    camera.setSize(1200, 900);
    centralizarCamera(sf::Vector2f(600, 450));
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    if(janela)
        delete(janela);
}

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
    return janela;
}

void Gerenciadores::GerenciadorGrafico::centralizarCamera(sf::Vector2f pos)
{
    camera.setCenter(pos);
    janela->setView(camera);
}

sf::Texture Gerenciadores::GerenciadorGrafico::carregarTextura(const char *caminho)
{
    sf::Texture textura;
    if(!textura.loadFromFile(caminho))
    {
        std::cout << "Erro ao carregar textura: " << caminho << std::endl;
    }
    return textura;
}

sf::Vector2f Gerenciadores::GerenciadorGrafico::getCentro()
{
    return camera.getCenter();
}

sf::Vector2f Gerenciadores::GerenciadorGrafico::getTamanho()
{
    return camera.getSize();
}

void GerenciadorGrafico::limpar()
{
    janela->clear();
}

void GerenciadorGrafico::desenhar(sf::RectangleShape desenho)
{
    janela->draw(desenho);
}

void GerenciadorGrafico::desenhar(sf::CircleShape desenho)
{
    janela->draw(desenho);
}

void GerenciadorGrafico::desenhar(sf::Text texto)
{
    janela->draw(texto);
}

void GerenciadorGrafico::mostrar()
{
    janela->display();
}

bool GerenciadorGrafico::estaAberta()
{
    return janela->isOpen();
}

void GerenciadorGrafico::fecharJanela()
{
    janela->close();
}

void GerenciadorGrafico::verificaSeFechou()
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
