#include "../../../include/Entidades/Obstaculos/Pedra.hpp"

Obstaculos::Pedra::Pedra(sf::Vector2f pos):
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::PEDRA),
peso(float(rand() % 6 + 15) / 10.0f)
{
    corpo.setFillColor(sf::Color(123, 15, 165));
}

Obstaculos::Pedra::Pedra():
Obstaculo(),
peso(10.0f)
{
}

Obstaculos::Pedra::~Pedra()
{
}

const float Obstaculos::Pedra::getPeso() const
{
    return peso;
}

void Obstaculos::Pedra::arrastar(const float dx)
{
    corpo.move(dx, 0.0f);
}