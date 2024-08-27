#pragma once

#include "Inimigo.hpp"

#define RAIO_CHEFAO_X 500.0f
#define RAIO_CHEFAO_Y 150.0f
#define RAIO_ATAQUE_CHEFAO 75.0f
#define VEL_CHEFAO 75.0f
#define VEL_CHEFAO_PERSEG 150.0f

#define CAMINHO_CHEFAO_ANDANDO "../assets/sprites/Chefao/Andando.png"
#define CAMINHO_CHEFAO_ATACANDO "../assets/sprites/Chefao/Atacando.png"
#define CAMINHO_CHEFAO_CORRENDO "../assets/sprites/Chefao/Correndo.png"
#define TEMPO_MUDANCA_DIRECAO 6.0f
#define TEMPO_BATIDA 0.175f

class Chefao: public Inimigo::Inimigo
{
private:
    bool estaPerseguindo;
    float tempoMudancaDirecao;
    //ideia: criar um bool furioso, se ele for furioso (quando a vida < 50%) ele vai andar mais rapido

public:
    Chefao(sf::Vector2f pos);
    Chefao();
    ~Chefao();

    void inicializarAnimacao();
    void atualizarAnimacao();
    void perseguir(const float dt);
    void moverAleatorio(const float dt);
    void ajustaVelocidade();
    bool consegueAtacar();
    bool conseguePerseguir();
    void atacar();
    void agir();
    void atualizar(const float dt);
    void colide(Entidade *ent, const sf::Vector2f intersec);
    float getPontuacao();
};