#pragma once

#include "../Projetil.hpp"
#include "../../Gerenciadores/GerenciadorGrafico.hpp"

#define RAIO_ATIRADOR 600.0f
#define VEL_PROJ 420.0f

class Atirador: public Inimigo::Inimigo
{
private:
    Projetil* pProjetil;

public:
    Atirador(sf::Vector2f pos);
    Atirador();
    ~Atirador();

    void setProjetil(Projetil* proj);
    bool consegueAtacar();
    void atacar();
    void agir();
    void atualizar(const float dt);
    sf::Vector2f calcVel();
};