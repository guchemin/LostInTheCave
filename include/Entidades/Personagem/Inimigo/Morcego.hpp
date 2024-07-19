#pragma once

#include "Inimigo.hpp"

#define VEL_MORCEGO 3.0f 

class Morcego: public Inimigo::Inimigo
{
private:

public:
    Morcego(sf::Vector2f pos, sf::Vector2f tam);
    Morcego();
    ~Morcego();

    void mover(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};