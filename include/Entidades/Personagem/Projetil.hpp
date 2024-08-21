#pragma once

#include "Inimigo.hpp"

class Projetil: public Entidades::Entidades
{
private:
    sf::Vector2f vel;
    Listas::ListaEntidades* listaJogadores;

public:
    Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Listas::ListaEntidades* listaJog);
    Projetil();
    ~Projetil();

    void setVelocidade(sf::Vector2f v);
    void setPosicao(sf::Vector2f p);
    bool saiuDaTela();
    void atacar(Jogador* pJog);
    bool atingiuJogador();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};