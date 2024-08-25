#pragma once

#include "../Entidade.hpp"
#include "../../Animacoes/Animacao.hpp"
using namespace Entidades;

#define TEMPO_TOMOU_DANO 0.3f
#define TEMPO_TOTAL_ATAQUE 0.42f

class Personagem: public Entidade
{
protected:
    sf::Vector2f vel;
    bool estaNoChao;
    bool direcao;
    float vida;
    float raioAtaque;
    float dano;
    float tempoAtaque;
    float tempoAnimacaoAtaque;
    bool iniciouAtaque;
    bool atacando;
    bool tomouDano;
    float tempoTomouDano;
    Animacoes::Animacao animacao;
    
public:
    Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
    Personagem();
    virtual ~Personagem();

    virtual void inicializarAnimacao() = 0;
    virtual void atualizarAnimacao() = 0;
    void setAtacando(const bool atk);
    void setDirecao(const bool dir);
    float getVida();
    void tiraVida(const float dano);
    float getRaioAtaque();
    float getDano();
    virtual void atacar(){};
};