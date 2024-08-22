#include "../../../include/Entidades/Obstaculos/Plataforma.hpp"


using namespace Entidades;

Obstaculos::Plataforma::Plataforma(sf::Vector2f pos): 
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::PLATAFORMA)
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
