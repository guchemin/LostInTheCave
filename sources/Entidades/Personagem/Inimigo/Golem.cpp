#include "../../../../include/Entidades/Personagem/Inimigo/Golem.hpp"

Golem::Golem(sf::Vector2f pos, sf::Vector2f tam):
Inimigo(pos, tam)
{
    vel = sf::Vector2f(VEL_GOLEM, 0.0f);
    corpo.setFillColor(sf::Color(200, 200, 200));
}

Golem::Golem()
{
}

Golem::~Golem()
{
}

void Golem::perseguir()
{
    if(pJogador->getPosicao().x > this->getPosicao().x + this->getTamanho().x)
    {   
        corpo.move(VEL_GOLEM_PERSEG, 0.0f);
    }
    else if(pJogador->getPosicao().x + pJogador->getTamanho().x < this->getPosicao().x)
    {
        corpo.move(-VEL_GOLEM_PERSEG, 0.0f);
    }

    if(abs(pJogador->getCentro().x - (this->getPosicao().x + this->getTamanho().x / 2.0f)) <= RAIO_ATAQUE_GOLEM)
    {
        atacar();
    }
    else if(abs(this->getPosicao().x - pJogador->getCentro().x) <= RAIO_ATAQUE_GOLEM)
    {
        atacar();
    }
}

void Golem::moverAleatorio()
{
    if(corpo.getPosition().x < posInicial.x - 300.0f || corpo.getPosition().x > posInicial.x + 300.0f)
    {
        vel.x = -vel.x;
    }
    corpo.move(vel);
}

void Golem::atacar()
{  
    //TODO atacar jogador
}

void Golem::mover(float dt)
{
    sf::Vector2f posGolem = corpo.getPosition();
    sf::Vector2f posJog = pJogador->getPosicao();

    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    corpo.move(0.0f, vel.y);
    
    if(abs(posGolem.x - posJog.x) < RAIO_GOLEM && abs(posGolem.y - posJog.y) < RAIO_GOLEM)
    {
        perseguir();
        posInicial = posGolem;
    }
    else
    {
        moverAleatorio();
    }
}

void Golem::colide(Entidades *ent, sf::Vector2f intersec)
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