#include "../../../include/Entidades/Obstaculos/Obstaculo.hpp"


Obstaculos::Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
Entidade(pos, tam, tp)
{
    if(tp == TIPO::ESPINHO)
    {
        danoso = true;
    }
    else
    {
        danoso = false;
    }
}

Obstaculos::Obstaculo::Obstaculo()
{
}

Obstaculos::Obstaculo::~Obstaculo()
{
}

bool Obstaculos::Obstaculo::getDanoso()
{
    return danoso;
}
