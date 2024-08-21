#pragma once

#include "Inimigo.hpp"

#define RAIO_CHEFAO_X 300.0f
#define RAIO_CHEFAO_Y 150.0f
#define RAIO_ATAQUE_CHEFAO 65.0f
#define VEL_CHEFAO 60.0f
#define VEL_CHEFAO_PERSEG 105.0f

class Chefao: public Inimigo::Inimigo
{
private:
    bool estaPerseguindo;
    //ideia: criar um bool furioso, se ele for furioso (quando a vida < 50%) ele vai andar mais rapido

public:
    Chefao(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog);
    Chefao();
    ~Chefao();

    void perseguir(float dt);
    void moverAleatorio(float dt);
    void ajustaVelocidade();
    bool consegueAtacar();
    bool conseguePerseguir();
    void atacar();
    void parar(); // nao ta no UML pq nao ta mais usando para nada, talvez dê para excluir depois
    void atualizar(float dt);
    void colide(Entidades* ent, sf::Vector2f intersec);
};