#include "../../../include/Entidades/Obstaculos/Espinho.hpp"

using namespace Entidades;

Obstaculos::Espinho::Espinho(sf::Vector2f pos):
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::ESPINHO),
afiado(float(rand() % 101 + 50) / 10.0f)
{
    corpo.setFillColor(sf::Color(123, 15, 165));
}

Obstaculos::Espinho::Espinho():
afiado(10.0f)
{
}

Obstaculos::Espinho::~Espinho()
{
}

const float Obstaculos::Espinho::getAfiado() const
{
    return afiado;
}