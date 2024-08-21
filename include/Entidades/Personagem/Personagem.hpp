#pragma once

#include "../Entidades.hpp"
using namespace Entidades;

class Personagem: public Entidades
{
protected:
    sf::Vector2f vel;
    bool estaNoChao;
    float vida;
    float raioAtaque;
    float dano;
    float tempoAtaque;
    
public:
    Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
    Personagem();
    virtual ~Personagem();

    float getVida();
    void tiraVida(const float dano);
    float getRaioAtaque();
    float getDano();
    virtual void atacar() = 0;
    virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0;
    virtual void atualizar(float dt) = 0;
};