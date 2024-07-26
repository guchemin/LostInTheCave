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
    corpo.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
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

// void Jogador::Jogador::andarParaEsquerda()
// {
//     if(id == JOGADOR1)
//     {
//         vel.x = -VEL_JOG1;
//         if(!estaNoChao)
//             vel.x *= 1.5;
//     }
//     else if(id == JOGADOR2)
//     {
//         vel.x = -VEL_JOG2;
//         if(!estaNoChao)
//             vel.x *= 1.5f;
//     }
// }

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
            if(corpo.getPosition().y > ent->getCorpo().getPosition().y)
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicao().y - this->getTamanho().y));
                estaNoChao = true;
                ajustarVelocidade();
            }
            vel.y = 0.0f;
        }
        else
        {
            if(corpo.getPosition().x > ent->getCorpo().getPosition().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, corpo.getPosition().y)); 
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x - this->getTamanho().x, corpo.getPosition().y));
            }
        }
        break;
    }
    
    default:
        break;
    }
}

// if(id == JOGADOR1)
    // {
    //     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && estaNoChao)
    //     {
    //         vel.y = -PULO_JOG1;
    //         estaNoChao = false;
    //         dy = vel.y * dt;
    //         corpo.move(0.0f, dy);
    //         vel.x = VEL_NO_AR_JOG1;   
    //     }

    //     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //     {
    //         vel.x = -VEL_JOG1;
    //     }
    //     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //     {
    //         vel.x = VEL_JOG1;
    //     }
    //     else    
    //         vel.x = 0.0f;
        
    //     dx = vel.x * dt;
    //     corpo.move(dx, 0.0f);
    // }
    // else if(id == JOGADOR2)
    // {
    //     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && estaNoChao)
    //     {
    //         vel.y = -PULO_JOG2;
    //         estaNoChao = false;
    //         dy = vel.y * dt;
    //         corpo.move(0.0f, dy);
    //         vel.x = VEL_NO_AR_JOG2;
    //     }
        
    //     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //     {
    //         vel.x = -VEL_JOG2;
    //     }
    //     else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //     {
    //         vel.x = VEL_JOG2;
    //     }
    //     else
    //         vel.x = 0.0f;

    //     dx = vel.x * dt;
    //     corpo.move(dx, 0.0f);
    // }
    // std::cout << vel.x * dt << std::endl;