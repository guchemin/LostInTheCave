#pragma once

#include "Personagem/Inimigo.hpp"

class Projetil: public Entidades::Entidades
{
private:
    sf::Vector2f vel;

public:
    Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade);
    Projetil();
    ~Projetil();

    void setVelocidade(sf::Vector2f v);
    void setPosicao(sf::Vector2f p);
    bool saiuDaTela();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};