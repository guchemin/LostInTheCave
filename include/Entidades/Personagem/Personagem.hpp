#pragma once

#include "../Entidades.hpp"
using namespace Entidades;

class Personagem: public Entidades
{
protected:
    sf::Vector2f vel;
    bool estaNoChao;
    
public:
    Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
    Personagem();
    ~Personagem();

    virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0;
    virtual void atualizar(float dt) = 0;
};