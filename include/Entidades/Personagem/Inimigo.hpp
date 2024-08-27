#pragma once

#include "Jogador.hpp"
#include "../../Listas/ListaEntidades.hpp"

#define COOLDOWN_ATIRADOR 1.7f
#define COOLDOWN_CHEFAO 1.5f
#define COOLDOWN_VOADOR 1.0f

#define DANO_ATIRADOR 10.0f // projetil
#define DANO_CHEFAO 20.0f
#define DANO_VOADOR 5.0f

#define PONTUACAO_ATIRADOR 75.0f
#define PONTUACAO_CHEFAO 250.0f
#define PONTUACAO_VOADOR 150.0f

class Inimigo: public Personagem
{
protected:
    Jogador* pJogador;
    sf::Vector2f posInicial;

public:
    Inimigo(sf::Vector2f pos, sf::Vector2f tam);
    Inimigo();
    virtual ~Inimigo();

    virtual bool consegueAtacar() = 0;
    void setJogador(Jogador* jog);
    sf::Vector2f getPosJogador();
    virtual void atacar() = 0;
    virtual void agir() = 0;
    virtual void colide(Entidade* ent, const sf::Vector2f intersec);
    virtual float getPontuacao() = 0;
};