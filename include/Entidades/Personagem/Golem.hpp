#pragma once

#include "Inimigo.hpp"

#define RAIO_GOLEM_X 300.0f
#define RAIO_GOLEM_Y 150.0f
#define RAIO_ATAQUE_GOLEM 65.0f
#define VEL_GOLEM 60.0f
#define VEL_GOLEM_PERSEG 105.0f

class Golem: public Inimigo::Inimigo
{
private:
    bool estaPerseguindo;

public:
    Golem(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog);
    Golem();
    ~Golem();

    void perseguir(float dt);
    void moverAleatorio(float dt);
    void ajustaVelocidade();
    bool consegueAtacar();
    bool conseguePerseguir();
    void atacar();
    void parar();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};