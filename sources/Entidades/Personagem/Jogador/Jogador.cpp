#include "../../../../include/Entidades/Personagem/Jogador/Jogador.hpp"

using namespace Entidades;

Jogador::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i):
id(i),
Personagem(pos, tam, TIPO::JOGADOR)
{
    if(id == JOGADOR1)
    {
        corpo.setFillColor(sf::Color::Red);
        vel = sf::Vector2f(0.0f, 0.0f);
    }
    else if(id == JOGADOR2)
    {
        corpo.setFillColor(sf::Color::Blue);
        vel = sf::Vector2f(0.0f, 0.0f);
    }
    estaNoChao = false;
    pulou = false;
    vida = 100.0f;
}

Jogador::Jogador::Jogador()
{
}

Jogador::Jogador::~Jogador()
{
}

void Jogador::Jogador::autorizarPulo(bool autoriza)
{
    pulou = !autoriza;
}

bool Jogador::Jogador::podePular()
{
    return estaNoChao && !pulou;
}

void Jogador::Jogador::perderVida(float dano)
{
    tiraVida(dano);
}

void Jogador::Jogador::atualizar(float dt) 
{
    ds.y = vel.y * dt;
    ds.x = vel.x * dt;

    if(vel.y > GRAVIDADE * dt)
        estaNoChao = false;
    
    corpo.move(ds);

    // acao da gravidade para a proxima iteracao
    vel.y += GRAVIDADE * dt;
}

void Jogador::Jogador::pular()
{
    if(id == JOGADOR1)
    {
        vel.y = -PULO_JOG1;
        vel.x *= 1.5f;
    } 
    else if(id == JOGADOR2)
    {
        vel.y = -PULO_JOG2;
        vel.x *= 1.5f;
    }
    estaNoChao = false;
}

void Jogador::Jogador::andar(bool direita)
{
    if(id == JOGADOR1)
    {
        vel.x = VEL_JOG1;
        if(!estaNoChao)
            vel.x *= 1.5f;
    }
    else if(id == JOGADOR2)
    {
        vel.x = VEL_JOG2;
        if(!estaNoChao)
            vel.x *= 1.5f;
    }
    if(!direita)
        vel.x *= -1.0f;
}

void Jogador::Jogador::parar()
{
    vel.x = 0.0f;
}

void Jogador::Jogador::ajustarVelocidade()
{
    if(vel.x < 0.0f)
    {
        if(id == JOGADOR1)
        {
            vel.x = -VEL_JOG1;
        }
        else if(id == JOGADOR2)
        {
            vel.x = -VEL_JOG2;
        }
    }
    else if(vel.x > 0.0f)
    {
        if(id == JOGADOR1)
        {
            vel.x = VEL_JOG1;
        }
        else if(id == JOGADOR2)
        {
            vel.x = VEL_JOG2;
        }
    }
}

void Jogador::Jogador::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y || vel.x == 0.0f)
        {
            if(getPosicao().y > ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
                ajustarVelocidade();
            }
            vel.y = 0.0f;
        }
        else
        {
            if(getPosicao().x > ent->getPosicao().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y)); 
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
            }
        }
        break;
    }
    
    default:
        break;
    }
}