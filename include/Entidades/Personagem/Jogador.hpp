#pragma once

#include <iostream>
#include "../Plataforma.hpp"
#include "../Obstaculos/Espinho.hpp"
#include "../Obstaculos/Teia.hpp"
#include "../Obstaculos/Pedra.hpp"
#include "Personagem.hpp"
#include "../../Observadores/ObsJogadores.hpp"
#include "../../Animacoes/Animacao.hpp"

#define VEL_JOG1 300.0f
#define VEL_JOG2 300.0f
#define PULO_JOG1 1500.0f
#define PULO_JOG2 1650.0f
#define COOLDOWN_ATAQUE 1.0f
#define CAMINHO_JOG_ANDAR "../assets/spritesheet(1).png"
#define CAMINHO_JOG_PARADO "../assets/spritesheet(2).png"

enum ID
{
    JOGADOR1,
    JOGADOR2
};

class Jogador: public Personagem
{
private:
    const ID id;
    sf::Vector2f ds;
    bool pulou;
    bool estaNaTeia;
    float aceleracaoTeia;
    bool foiEspinhado;
    bool atacando;
    Observadores::ObsJogadores obs;

public:
    Jogador(sf::Vector2f pos, const ID i);
    Jogador();
    ~Jogador();

    void inicializarAnimacao();
    void autorizarPulo(const bool autoriza);
    bool podePular();
    bool podeAtacar();
    void setAtacando(const bool atk);
    const ID getId() const { return id; };
    void atacar();
    void atualizar(const float dt);
    void pular();
    void andar(const bool direita);
    void parar();
    void ajustarVelocidade();
    void desacelerarTeia();
    void colide(Entidade* ent, const sf::Vector2f intersec);
};