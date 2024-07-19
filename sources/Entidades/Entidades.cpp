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

void Entidades::Entidades::setPosicao(sf::Vector2f pos)
{
    corpo.setPosition(pos);
}

sf::RectangleShape Entidades::Entidades::getCorpo()
{
    return corpo;
}

sf::Vector2f Entidades::Entidades::getCentro()
{
    return sf::Vector2f(corpo.getPosition() + corpo.getSize() / 2.0f);
}

sf::Vector2f Entidades::Entidades::getTamanho()
{
    return corpo.getSize();
}

sf::Vector2f Entidades::Entidades::getPosicao()
{
    return corpo.getPosition();
}