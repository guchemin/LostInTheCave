#pragma once

#include "Jogador.hpp"
#include "../../Listas/ListaEntidades.hpp"

#define COOLDOWN_ATIRADOR 1.7f
#define COOLDOWN_CHEFAO 1.5f
#define COOLDOWN_VOADOR 1.0f

#define DANO_ATIRADOR 15.0f // projetil
#define DANO_CHEFAO 20.0f
#define DANO_VOADOR 10.0f

class Inimigo: public Personagem
{
protected:
    Jogador* pJogador;
    sf::Vector2f posInicial;
    float tempoAtaque;
    Listas::ListaEntidades* listaJogadores;

public:
    Inimigo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog);
    Inimigo();
    virtual ~Inimigo();

    virtual bool consegueAtacar() = 0;
    void setJogador();
    sf::Vector2f getPosJogador();
    virtual void parar() = 0; // nao ta no UML pq nao ta mais usando para nada, talvez dê para excluir depois
    virtual void atacar() = 0;
    virtual void atualizar(float dt) = 0;
    virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0;
};

