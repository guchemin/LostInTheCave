#pragma once

#include <iostream>
#include "../../Plataforma/Plataforma.hpp"
#include "../Personagem.hpp"

#define VEL_JOG1 4.0f
#define VEL_JOG2 5.0f
#define VEL_NO_AR_JOG1 6.0f
#define VEL_NO_AR_JOG2 7.5f
#define PULO_JOG1 25.0f
#define PULO_JOG2 27.5f

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

    public:
        Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i);
        Jogador();
        ~Jogador();
        
        void atualizar(float dt);
        void colide(Entidades* ent, sf::Vector2f intersec);
    };

};