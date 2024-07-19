#include "../../../../include/Entidades/Personagem/Inimigo/Inimigo.hpp"

using namespace Entidades;

Inimigo::Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam):
Personagem(pos, tam, TIPO::INIMIGO),
posInicial(pos)
{
    estaNoChao = false;
}

Inimigo::Inimigo::Inimigo()
{
    pJogador = NULL;
}

Inimigo::Inimigo::~Inimigo()
{
    pJogador = NULL;
}

void Inimigo::Inimigo::setpJogador(Jogador::Jogador *pJ)
{
    pJogador = pJ;
}

sf::Vector2f Inimigo::Inimigo::getPosJogador()
{
    return pJogador->getPosicao();
}