#include "../../../../include/Entidades/Personagem/Inimigo/Inimigo.hpp"

using namespace Entidades;

Inimigo::Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, ID i):
id(i),
Personagem(pos, tam, TIPO::INIMIGO)
{
    switch (id)
    {
    case INIM1:
        {
            corpo.setFillColor(sf::Color::Magenta);
            vel = sf::Vector2f(VEL_INIM1, 0.0f);
            break;
        }
    case INIM2:
        {
            corpo.setFillColor(sf::Color(120, 120, 120));
            vel = sf::Vector2f(VEL_INIM2, 0.0f);
            break;
        }
    case INIM3:
        {
            corpo.setFillColor(sf::Color::White);
            vel = sf::Vector2f(VEL_INIM3, 0.0f);
            break;
        }
    
    default:
        break;
    }
    estaNoChao = false;
}

Inimigo::Inimigo::Inimigo()
{
}

Inimigo::Inimigo::~Inimigo()
{
}

void Inimigo::Inimigo::mover(float dt)
{
    //TODO
}