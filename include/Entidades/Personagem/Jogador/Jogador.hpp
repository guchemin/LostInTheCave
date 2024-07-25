#pragma once

#include <iostream>
#include "../../Plataforma/Plataforma.hpp"
#include "../Personagem.hpp"

#define VEL_JOG1 240.0f
#define VEL_JOG2 300.0f
#define VEL_NO_AR_JOG1 360.0f
#define VEL_NO_AR_JOG2 450.0f
#define PULO_JOG1 1500.0f
#define PULO_JOG2 1650.0f

namespace Jogador
{
    enum ID
    {
        JOGADOR1,
        JOGADOR2
    };

    class Jogador: public Personagem
    {
    private:
        ID id;
        bool podeAndar;

    public:
        Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i);
        Jogador();
        ~Jogador();

        bool podePular();
        ID getId() const { return id; };
        void atualizar(float dt);
        void pular(float dt);
        void andar(bool direita, float dt);
        void parar();
        void ajustarVelocidade();
        void colide(Entidades* ent, sf::Vector2f intersec);
    };

};