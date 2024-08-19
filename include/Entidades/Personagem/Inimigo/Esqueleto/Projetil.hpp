#pragma once

#include "../Inimigo.hpp"

class Projetil: public Entidades::Entidades
{
private:
    sf::Vector2f vel;
    Listas::ListaEntidades* listaJogadores;
    const sf::Vector2f posInicial;

public:
    bool existeProjetil;

public:
    Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Listas::ListaEntidades* listaJog);
    Projetil();
    ~Projetil();

    bool saiuDaTela();
    void atacar(Jogador::Jogador* pJog);
    bool atingiuJogador();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};