#pragma once

#include "Inimigo.hpp"

#define VEL_MORCEGO 180.0f 

class Morcego: public Inimigo::Inimigo
{
private:

public:
    Morcego(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog);
    Morcego();
    ~Morcego();

    bool consegueAtacar();
    bool atingiuJogador();
    void atacar();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};