#include "../../../../include/Entidades/Personagem/Inimigo/Inimigo.hpp"

using namespace Entidades;

Inimigo::Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Personagem(pos, tam, TIPO::INIMIGO),
posInicial(pos),
listaJogadores(listaJog)
{
    estaNoChao = false;
    tempoAtaque = 0.0f;
}

Inimigo::Inimigo::Inimigo()
{
    pJogador = NULL;
    listaJogadores = NULL;;
}

Inimigo::Inimigo::~Inimigo()
{
    pJogador = NULL;
    listaJogadores = NULL;
}

void Inimigo::Inimigo::setJogador()
{
    if(listaJogadores->estaVazia())
    {
        return;
    }
    
    std::vector<Entidades*>::iterator it;

    float dist;
    float menorDist = 999999.0f;

    for(it = listaJogadores->getInicio(); it != listaJogadores->getFim(); ++it)
    {
        dist = sqrt(pow((*it)->getPosicao().x - this->getPosicao().x, 2) + pow((*it)->getPosicao().y - this->getPosicao().y, 2));
        if(dist < menorDist)
        {
            menorDist = dist;
            pJogador = dynamic_cast<Jogador::Jogador*>(*it);
        }
    }
}

sf::Vector2f Inimigo::Inimigo::getPosJogador()
{
    return pJogador->getPosicao();
}