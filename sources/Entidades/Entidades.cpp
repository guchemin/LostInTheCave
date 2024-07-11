#include "../../include/Entidades/Entidades.hpp"

Entidades::Entidades::Entidades(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
tipo(tp),
corpo(sf::RectangleShape(tam))
{
    corpo.setPosition(pos);
}

Entidades::Entidades::Entidades()
{
}

Entidades::Entidades::~Entidades()
{
}

sf::RectangleShape Entidades::Entidades::getCorpo()
{
    return corpo;
}
