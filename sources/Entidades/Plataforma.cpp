#include "../../include/Entidades/Plataforma.hpp"

using namespace Entidades;

Plataforma::Plataforma(sf::Vector2f pos):
Entidade(pos, sf::Vector2f(50, 50), TIPO::PLATAFORMA),
ehFalsa(!(bool)(rand() % 20))
{
    corpo.setFillColor(sf::Color::Green);
}

Plataforma::Plataforma():
ehFalsa(false)
{
}

Plataforma::~Plataforma()
{
}

const bool Plataforma::getFalsa() const
{
    return ehFalsa;
}
