#include "../../../include/Entidades/Personagem/Voador.hpp"

Voador::Voador(sf::Vector2f pos, sf::Vector2f tam):
Inimigo(pos, tam)
{
    vel = sf::Vector2f(VEL_Voador, VEL_Voador);
    corpo.setFillColor(sf::Color(80, 80, 80));
    tempoAtaque = 0.0f;
    raioAtaque = 0.0f;
    vida = 40.0f;
    dano = DANO_VOADOR;
}

Voador::Voador()
{
}

Voador::~Voador()
{
}

bool Voador::consegueAtacar()
{
    if(tempoAtaque >= COOLDOWN_VOADOR)
    {
        if(atingiuJogador())
        {
            tempoAtaque = 0.0f;
            return true;
        }
    }
    return false;
}

bool Voador::atingiuJogador()
{
    return corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds());
}

void Voador::atacar()
{ 
    pJogador->tiraVida(dano);
}

void Voador::agir()
{
    if(consegueAtacar())
    {   
        atacar();
    }
}

void Voador::atualizar(float dt)
{
    sf::Vector2f ds;

    tempoAtaque += dt;

    if(getPosicao().y < posInicial.y - 70.0f)
    {
        vel.y = 0.0f;
    }
    else if(getPosicao().y > posInicial.y + 70.0f)
    {
        vel.y = -VEL_Voador;
    }

    if(getPosicao().x < posInicial.x - 300.0f || getPosicao().x > posInicial.x + 300.0f)
    {
        vel.x = -vel.x;
    }

    if(vel.y < 0)
    {
        vel.y -= 1000.0f * dt;
    }

    //acao da gravidade
    vel.y += 1000.0f * dt;
    
    ds = vel * dt;
    corpo.move(ds);
    if(consegueAtacar())
    {
        atacar();
    }
}

void Voador::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y)
        {
            if(getPosicao().y > ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
                vel.y = 0.0f;
            }
            else
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
                vel.y = -VEL_Voador;
            }
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
            vel.x = -vel.x;
        }
        break;
    }

    case TIPO::JOGADOR:
    {
        if(intersec.x > intersec.y)
        {
            if(getPosicao().y > ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
            }
            vel.y = -vel.y;
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
            vel.x = -vel.x;
        }
        break;
    }
    
    default:
        break;
    }
}

