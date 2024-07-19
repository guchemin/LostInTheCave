#pragma once

#include "Inimigo.hpp"

#define RAIO_GOLEM 250.0f
#define RAIO_ATAQUE_GOLEM 50.0f
#define VEL_GOLEM 1.5f
#define VEL_GOLEM_PERSEG 2.5f

class Golem: public Inimigo::Inimigo
{
private:

public:
    Golem(sf::Vector2f pos, sf::Vector2f tam);
    Golem();
    ~Golem();

    void perseguir();
    void moverAleatorio();
    void atacar();
    void mover(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};