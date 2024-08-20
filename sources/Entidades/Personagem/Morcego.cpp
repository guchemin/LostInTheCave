#include "../../../include/Entidades/Personagem/Morcego.hpp"

Morcego::Morcego(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Inimigo(pos, tam, listaJog)
{
    vel = sf::Vector2f(VEL_MORCEGO, VEL_MORCEGO);
    corpo.setFillColor(sf::Color(80, 80, 80));
    tempoAtaque = 0.0f;
    vida = 40.0f;
}

Morcego::Morcego()
{
}

Morcego::~Morcego()
{
}

bool Morcego::consegueAtacar()
{
    if(tempoAtaque >= COOLDOWN_MORCEGO)
    {
        setJogador();
        if(atingiuJogador())
        {
            tempoAtaque = 0.0f;
            return true;
        }
    }
    return false;
}

bool Morcego::atingiuJogador()
{
    return corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds());
}

void Morcego::atacar()
{ 
    pJogador->perderVida(DANO_MORCEGO);
}

void Morcego::parar()
{
}

void Morcego::atualizar(float dt)
{
    sf::Vector2f ds;

    tempoAtaque += dt;

    if(getPosicao().y < posInicial.y - 70.0f)
    {
        vel.y = 0.0f;
    }
    else if(getPosicao().y > posInicial.y + 70.0f)
    {
        vel.y = -VEL_MORCEGO;
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

void Morcego::colide(Entidades *ent, sf::Vector2f intersec)
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
                vel.y = -VEL_MORCEGO;
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

