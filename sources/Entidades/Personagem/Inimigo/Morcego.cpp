#include "../../../../include/Entidades/Personagem/Inimigo/Morcego.hpp"

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

void Morcego::atualizar(float dt) 
{
    sf::Vector2f ds;

    tempoAtaque += dt;

    if(getPosicao().y < posInicial.y - 100.0f || getPosicao().y > posInicial.y + 100.0f)
    {
        vel.y = -vel.y;
    }
    if(getPosicao().x < posInicial.x - 300.0f || getPosicao().x > posInicial.x + 300.0f)
    {
        vel.x = -vel.x;
    }
    
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

    case TIPO::JOGADOR:
    {
        //Jogador::Jogador *jog = dynamic_cast<Jogador::Jogador*>(ent);
        //setJogador();

        //TODO tira vida do jogador
        break;
    }
    
    default:
        break;
    }
}

