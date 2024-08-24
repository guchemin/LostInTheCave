#pragma once

#include "../Entidade.hpp"
using namespace Entidades;

class Personagem: public Entidade
{
protected:
    sf::Vector2f vel;
    bool estaNoChao;
    float vida;
    float raioAtaque;
    float dano;
    float tempoAtaque;
    Animacoes::Animacao animacao;
    
public:
    Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
    Personagem();
    virtual ~Personagem();

    virtual void inicializarAnimacao() = 0;
    virtual void atualizarAnimacao() = 0;
    float getVida();
    void tiraVida(const float dano);
    float getRaioAtaque();
    float getDano();
    virtual void atacar() = 0;
};