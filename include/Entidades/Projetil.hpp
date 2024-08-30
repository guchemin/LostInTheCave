/*
Projetil.hpp - Definição da classe Projetil - Filha de Entidade
*/

#pragma once

#include "Personagem/Inimigo.hpp"

#define CAMINHO_TEXTURA_PROJETIL "../assets/sprites/Projetil/Projetil.png"

namespace Entidades
{
    class Projetil: public Entidades::Entidade
    {
    private:  
        sf::Vector2f vel;

    public:
        Projetil(sf::Vector2f pos, sf::Vector2f velocidade);
        Projetil();
        ~Projetil();

        virtual nlohmann::json salvarJogo();
        void setVelocidade(sf::Vector2f v);
        void setPosicao(sf::Vector2f p);
        bool saiuDaTela();
        void executar(const float dt);
        void colide(Entidade* ent, const sf::Vector2f intersec);
    };
}