#include "../../../include/Entidades/Obstaculos/Plataforma.hpp"


using namespace Entidades;

Obstaculos::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam): 
Obstaculo(pos, tam, TIPO::PLATAFORMA)
{
    corpo.setFillColor(sf::Color::Green);
}

Obstaculos::Plataforma::Plataforma()
{
}

Obstaculos::Plataforma::~Plataforma()
{
}

void Obstaculos::Plataforma::atualizar(float dt)
{
}
