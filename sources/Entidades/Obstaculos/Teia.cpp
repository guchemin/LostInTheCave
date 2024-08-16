#include "../../../include/Entidades/Obstaculos/Teia.hpp"

using namespace Entidades;

Obstaculos::Teia::Teia(sf::Vector2f pos, sf::Vector2f tam):
Entidades(pos, tam, TIPO::TEIA)
{
    corpo.setFillColor(sf::Color(100, 100, 100));
}

Obstaculos::Teia::Teia()
{
}

Obstaculos::Teia::~Teia()
{
}