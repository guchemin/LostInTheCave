#pragma once

#include "Personagem/Inimigo.hpp"

#define CAMINHO_TEXTURA_PROJETIL "../assets/sprites/Projetil/Projetil.png"

class Projetil: public Entidades::Entidade
{
private:  
    sf::Vector2f vel;

public:
    Projetil(sf::Vector2f pos, sf::Vector2f velocidade);
    Projetil();
    ~Projetil();

    void setVelocidade(sf::Vector2f v);
    void setPosicao(sf::Vector2f p);
    bool saiuDaTela();
    void atualizar(const float dt);
    void colide(Entidade* ent, const sf::Vector2f intersec);
};