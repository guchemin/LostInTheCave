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

bool Jogador::Jogador::podePular()
{
    return estaNoChao;
}

void Jogador::Jogador::atualizar(float dt)
{
    float dy;
    float dx;
    
    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);
    if(vel.y > GRAVIDADE * dt)
        estaNoChao = false;

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
    // corpo.move(vel.x * dt, 0.0f);
}

void Jogador::Jogador::pular(float dt)
{
    float dy;

    if(id == JOGADOR1)
    {
        vel.y = -PULO_JOG1;
        vel.x = VEL_NO_AR_JOG1; 
    } 
    else if(id == JOGADOR2)
    {
        vel.y = -PULO_JOG2;
        vel.x = VEL_NO_AR_JOG2;
    }
    
    estaNoChao = false;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);
}

void Jogador::Jogador::andar(bool direita, float dt)
{
    float dx;
    // podeAndar = true;

    // dx = fabs(vel.x) * dt;

    // if(!direita)
    //     dx *= -1;

    
    if(id == JOGADOR1)
    {
        if(direita)
        {
            vel.x = VEL_JOG1;
        }
        else
        {
            vel.x = -VEL_JOG1;
        }
    } 
    else if(id == JOGADOR2)
    {
        if(direita)
        {
            vel.x = VEL_JOG2;
        }
        else
        {
            vel.x = -VEL_JOG2;
        }
    }
    // std::cout << "dx jog2: " << dx << std::endl;
    dx = vel.x * dt;
    corpo.move(dx, 0.0f);
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