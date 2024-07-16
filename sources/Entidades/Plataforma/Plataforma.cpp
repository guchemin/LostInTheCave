#include "../../../include/Entidades/Plataforma/Plataforma.hpp"

using namespace Entidades;

Plataforma::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam): 
Entidades::Entidades(pos, tam, TIPO::PLATAFORMA)
{
    corpo.setFillColor(sf::Color::Green);
}

Plataforma::Plataforma::Plataforma()
{
}

Plataforma::Plataforma::~Plataforma()
{
}

void Plataforma::Plataforma::colide(Entidades *ent, sf::Vector2f intersec)
{
    
}