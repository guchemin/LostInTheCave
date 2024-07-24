#pragma once

#include "../Inimigo.hpp"

class Projetil: public Inimigo::Inimigo
{
private:
public:
    Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Jogador::Jogador* pJog);
    Projetil();
    ~Projetil();

    bool existeProjetil;
    bool saiuDaTela();
    void atacar();
    bool atingiuJogador();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};