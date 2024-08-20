#pragma once

#include "Projetil.hpp"
#include "../../Gerenciadores/GerenciadorGrafico.hpp"

#define RAIO_ESQUELETO 400.0f
#define VEL_PROJ 420.0f

class Esqueleto: public Inimigo::Inimigo
{
private:
    Projetil* pProjetil;

public:
    Esqueleto(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog);
    Esqueleto();
    ~Esqueleto();

    bool consegueAtacar();
    void atacar();
    void parar();
    void atualizar(float dt);
    sf::Vector2f calcVel();
    void colide(Entidades* ent, sf::Vector2f intersec);
};