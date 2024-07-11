
#include "../../../include/Entidades/Jogador/Jogador.hpp"

using namespace Entidades;

Jogador::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i):
id(i),
Entidades(pos, tam, TIPO::JOGADOR)
{
    if(id == JOGADOR1)
    {
        corpo.setFillColor(sf::Color::Red);
        vel = sf::Vector2f(0.2f, 0.2f);
    }
    else if(id == JOGADOR2)
    {
        corpo.setFillColor(sf::Color::Blue);
        vel = sf::Vector2f(0.4f, 0.4f);
    }
}

Jogador::Jogador::Jogador()
{

}

Jogador::Jogador::~Jogador()
{
}

void Jogador::Jogador::mover()
{
    if(id == JOGADOR1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            corpo.move(0.0f, -vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            corpo.move(0.0f, vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            corpo.move(-vel.x, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            corpo.move(vel.x, 0.0f);
        }
    }
    else if(id == JOGADOR2)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            corpo.move(0.0f, -vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            corpo.move(0.0f, vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            corpo.move(-vel.x, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            corpo.move(vel.x, 0.0f);
        }
    }
}