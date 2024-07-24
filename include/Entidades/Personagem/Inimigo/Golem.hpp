#pragma once

#include "Inimigo.hpp"

#define RAIO_GOLEM 300.0f
#define RAIO_ATAQUE_GOLEM 50.0f
#define VEL_GOLEM 60.0f
#define VEL_GOLEM_PERSEG 105.0f

class Golem: public Inimigo::Inimigo
{
private:

public:
    Golem(sf::Vector2f pos, sf::Vector2f tam);
    Golem();
    ~Golem();

    void perseguir(float dt);
    void moverAleatorio(float dt);
    void ajustaVelocidade();
    bool consegueAtacar();
    void atacar();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};