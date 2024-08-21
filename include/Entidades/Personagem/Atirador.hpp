#pragma once

#include "../Projetil.hpp"
#include "../../Gerenciadores/GerenciadorGrafico.hpp"

#define RAIO_ATIRADOR 400.0f
#define VEL_PROJ 420.0f

class Atirador: public Inimigo::Inimigo
{
private:
    Projetil* pProjetil;

public:
    Atirador(sf::Vector2f pos, sf::Vector2f tam);
    Atirador();
    ~Atirador();

    void setProjetil(Projetil* proj);
    bool consegueAtacar();
    void atacar();
    void agir();
    void atualizar(float dt);
    sf::Vector2f calcVel();
    void colide(Entidades* ent, sf::Vector2f intersec);
};