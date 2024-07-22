#pragma once

#include "Projetil.hpp"
#include "../../../../Listas/ListaEntidades.hpp"

#define RAIO_ESQUELETO 200.0f
#define COOLDOWN_ESQUELETO 1.7f

class Esqueleto: public Inimigo::Inimigo
{
private:
    Listas::ListaEntidades* listaProjetil;
    float tempoAtaque;

public:
    Esqueleto(sf::Vector2f pos, sf::Vector2f tam);
    Esqueleto();
    ~Esqueleto();

    bool consegueAtacar();
    void atacar();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};