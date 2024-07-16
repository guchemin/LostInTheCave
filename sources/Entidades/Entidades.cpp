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

float Entidades::Entidades::getCentroX()
{
    return corpo.getPosition().x + corpo.getSize().x/2;
}

float Entidades::Entidades::getCentroY()
{
    return corpo.getPosition().y + corpo.getSize().y/2;
}

float Entidades::Entidades::getTamanhoX()
{
    return corpo.getSize().x;
}

float Entidades::Entidades::getTamanhoY()
{
    return corpo.getSize().y;
}
