#include "../../../../include/Entidades/Personagem/Inimigo/Morcego.hpp"

Morcego::Morcego(sf::Vector2f pos, sf::Vector2f tam):
Inimigo(pos, tam)
{
    vel = sf::Vector2f(VEL_MORCEGO, VEL_MORCEGO);
    corpo.setFillColor(sf::Color(80 ,80 ,80));
}

Morcego::Morcego()
{
}

Morcego::~Morcego()
{
}

void Morcego::mover(float dt)
{
    if(corpo.getPosition().y < posInicial.y - 100.0f || corpo.getPosition().y > posInicial.y + 100.0f)
    {
        vel.y = -vel.y;
    }
    if(corpo.getPosition().x < posInicial.x - 300.0f || corpo.getPosition().x > posInicial.x + 300.0f)
    {
        vel.x = -vel.x;
    }
    corpo.move(vel);
}

void Morcego::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y)
        {
            if(corpo.getPosition().y > ent->getCorpo().getPosition().y)
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicao().y - this->getTamanho().y));
                estaNoChao = true;
            }
            vel.y = -vel.y;
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
            vel.x = -vel.x;
        }
        break;
    }

    case TIPO::JOGADOR:
    {
        Jogador::Jogador *jog = dynamic_cast<Jogador::Jogador*>(ent);
        setpJogador(jog);

        //TODO tira vida do jogador
        break;
    }
    
    default:
        break;
    }
}

