#include "../../../include/Entidades/Personagem/Inimigo.hpp"

using namespace Entidades;

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Personagem(pos, tam, TIPO::INIMIGO),
posInicial(pos),
listaJogadores(listaJog)
{
    estaNoChao = false;
    tempoAtaque = 0.0f;
}

Inimigo::Inimigo()
{
    pJogador = NULL;
    listaJogadores = NULL;;
}

Inimigo::~Inimigo()
{
    pJogador = NULL;
    listaJogadores = NULL;
}

void Inimigo::setJogador()
{
    float dist;
    float menorDist = 999999.0f;

    int tamJog = listaJogadores->getTam();

    for(int i = 0; i < tamJog; i++)
    {
        Jogador* pJog = static_cast<Jogador*>((*listaJogadores)[i]);
        dist = sqrt(pow(pJog->getPosicao().x - getPosicao().x, 2) + pow(pJog->getPosicao().y - getPosicao().y, 2));
        if(dist < menorDist)
        {
            menorDist = dist;
            pJogador = pJog;
        }
    }
}

sf::Vector2f Inimigo::getPosJogador()
{
    return pJogador->getPosicao();
}