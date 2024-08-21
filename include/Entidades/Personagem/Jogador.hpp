#pragma once

#include <iostream>
#include "../Obstaculos/Plataforma.hpp"
#include "../Obstaculos/Espinho.hpp"
#include "../Obstaculos/Teia.hpp"
#include "Personagem.hpp"
#include "../../Observadores/ObsJogadores.hpp"

#define VEL_JOG1 240.0f
#define VEL_JOG2 300.0f
#define PULO_JOG1 1500.0f
#define PULO_JOG2 1650.0f
#define COOLDOWN_ATAQUE 1.0f

enum ID
{
    JOGADOR1,
    JOGADOR2
};

class Jogador: public Personagem
{
private:
    ID id;
    sf::Vector2f ds;
    bool pulou;
    bool estaNaTeia;
    float aceleracaoTeia;
    bool foiEspinhado;
    bool atacando;
    Observadores::ObsJogadores obs;

public:
    Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i);
    Jogador();
    ~Jogador();

    void autorizarPulo(bool autoriza);
    bool podePular();
    bool podeAtacar();
    void setAtacando(bool atk);
    ID getId() const { return id; };
    void atacar();
    void atualizar(float dt);
    void pular();
    void andar(bool direita);
    void parar();
    void ajustarVelocidade();
    void desacelerarTeia();
    void colide(Entidades* ent, sf::Vector2f intersec);
};