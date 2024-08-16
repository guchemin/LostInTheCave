#include "../../../include/Entidades/Obstaculos/Espinho.hpp"

using namespace Entidades;

Obstaculos::Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam):
Entidades(pos, tam, TIPO::ESPINHO)
{
    corpo.setFillColor(sf::Color(123, 15, 165));
}

Obstaculos::Espinho::Espinho()
{
}

Obstaculos::Espinho::~Espinho()
{
}
