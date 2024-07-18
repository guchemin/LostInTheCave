#include "../../../../include/Entidades/Personagem/Jogador/Jogador.hpp"

using namespace Entidades;

Jogador::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i):
id(i),
Personagem(pos, tam, TIPO::JOGADOR)
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
    estaNoChao = false;
}

Jogador::Jogador::Jogador()
{
    
}

Jogador::Jogador::~Jogador()
{
}

void Jogador::Jogador::mover(float dt)
{
    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    corpo.move(0.0f, vel.y);

    if(id == JOGADOR1)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && estaNoChao)
        {
            vel.y = -PULO_JOG1;
            estaNoChao = false;
            corpo.move(0.0f, vel.y);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            corpo.move(0.0f, vel.y);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            corpo.move(-vel.x, 0.0f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            corpo.move(vel.x, 0.0f);
        }
    }
    else if(id == JOGADOR2)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao)
        {
            vel.y = -PULO_JOG2;
            estaNoChao = false;
            corpo.move(0.0f, vel.y);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            corpo.move(0.0f, vel.y);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            corpo.move(-vel.x, 0.0f);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            corpo.move(vel.x, 0.0f);
        }
    }
}