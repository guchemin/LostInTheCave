#include "../../../include/Entidades/Obstaculos/Plataforma.hpp"

using namespace Entidades;

Obstaculos::Plataforma::Plataforma(sf::Vector2f pos): 
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::PLATAFORMA),
ehFalsa(!(bool)(rand() % 20))
{
    corpo.setFillColor(sf::Color::Green);
}

Obstaculos::Plataforma::Plataforma():
ehFalsa(false)
{
}

Obstaculos::Plataforma::~Plataforma()
{
}

const bool Obstaculos::Plataforma::getFalsa() const
{
    return ehFalsa;
}
