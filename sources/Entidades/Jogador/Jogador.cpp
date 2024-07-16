
#include "../../../include/Entidades/Jogador/Jogador.hpp"

using namespace Entidades;

Jogador::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i):
id(i),
Entidades(pos, tam, TIPO::JOGADOR)
{
    if(id == JOGADOR1)
    {
        corpo.setFillColor(sf::Color::Red);
        vel = sf::Vector2f(VEL_JOG1, 0.0f);
    }
    else if(id == JOGADOR2)
    {
        corpo.setFillColor(sf::Color::Blue);
        vel = sf::Vector2f(VEL_JOG2, 0.0f);
    }
}

Jogador::Jogador::Jogador()
{

}

Jogador::Jogador::~Jogador()
{
}

void Jogador::Jogador::mover(float dt)
{
    vel.y += GRAVIDADE * dt;
    if(!estaNoChao)
    {
        corpo.move(0.0f, vel.y);
    }

    if(id == JOGADOR1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && estaNoChao)
        {
            vel.y = -1.0f;
            estaNoChao = false;
            corpo.move(0.0f, vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            corpo.move(0.0f, vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            corpo.move(-vel.x, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            corpo.move(vel.x, 0.0f);
        }
    }
    else if(id == JOGADOR2)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao)
        {
            vel.y = -1.0f;
            estaNoChao = false;
            corpo.move(0.0f, vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            corpo.move(0.0f, vel.y);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            corpo.move(-vel.x, 0.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            corpo.move(vel.x, 0.0f);
        }
    }
}

void Jogador::Jogador::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
        if(intersec.x > intersec.y)
        {
            if(corpo.getPosition().y > ent->getCorpo().getPosition().y)
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y + intersec.y));
            }
            else
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, corpo.getPosition().y - intersec.y));
            }
            estaNoChao = true;
            vel.y = 0.0f;
        }
        else
        {
            if(corpo.getPosition().x > ent->getCorpo().getPosition().x)
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x + intersec.x, corpo.getPosition().y));    
            }
            else
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x - intersec.x, corpo.getPosition().y));
            }
        }
        break;
    
    default:
        break;
    }
}