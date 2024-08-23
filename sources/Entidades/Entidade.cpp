#include "../../include/Entidades/Entidade.hpp"

Entidades::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
Ente(),
tipo(tp),
corpo(sf::RectangleShape(tam))
{
    corpo.setPosition(pos);
}

Entidades::Entidade::Entidade()
{
}

Entidades::Entidade::~Entidade()
{
}

void Entidades::Entidade::setPosicao(sf::Vector2f pos)
{
    corpo.setPosition(pos);
}

void Entidades::Entidade::desenhar()
{
    pGraf->desenhar(corpo);
}


sf::RectangleShape Entidades::Entidade::getCorpo()
{
    return corpo;
}

sf::Vector2f Entidades::Entidade::getCentro()
{
    return sf::Vector2f(getPosicao() + getTamanho() / 2.0f);
}

sf::Vector2f Entidades::Entidade::getTamanho()
{
    return corpo.getSize();
}

sf::Vector2f Entidades::Entidade::getPosicao()
{
    return corpo.getPosition();
}