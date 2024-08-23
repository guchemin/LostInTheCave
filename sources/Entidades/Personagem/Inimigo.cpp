#include "../../../include/Entidades/Personagem/Inimigo.hpp"

using namespace Entidades;

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam):
Personagem(pos, tam, TIPO::INIMIGO),
posInicial(pos),
pJogador(NULL)
{
    estaNoChao = false;
    tempoAtaque = 0.0f;
}

Inimigo::Inimigo()
{
    pJogador = NULL;
}

Inimigo::~Inimigo()
{
    pJogador = NULL;
}

void Inimigo::setJogador(Jogador* jog)
{
    if(jog)
    {        
        pJogador = jog;
    }
}

sf::Vector2f Inimigo::getPosJogador()
{
    return pJogador->getPosicao();
}

void Inimigo::colide(Entidade *ent, const sf::Vector2f intersec)
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
            vel.x = -vel.x;
        }
        break;
    }
    
    default:
        break;
    }
}