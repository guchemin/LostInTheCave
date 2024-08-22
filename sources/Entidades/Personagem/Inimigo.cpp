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