#pragma once

#include "../Inimigo.hpp"
#include "../../../../Listas/ListaEntidades.hpp"
#include "../../../../Gerenciadores/Graficos.hpp"

class Projetil: public Inimigo::Inimigo
{
private:
    Listas::ListaEntidades* listaProjetil;
    Gerenciadores::Graficos* pGraf;

public:
    Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Jogador::Jogador* pJog, Listas::ListaEntidades* lista);
    Projetil();
    ~Projetil();

    bool saiuDaTela();
    void atacar();
    bool atingiuJogador();
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};