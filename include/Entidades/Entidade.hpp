/*
Entidade.hpp - Filha de Ente - Classe Abstrata
*/

#pragma once

#include <cmath>
#include <iostream>
#include "../SFML/Graphics.hpp"
#include "../Ente.hpp"

#define GRAVIDADE 5400.0f

namespace Entidades
{    
    enum TIPO
    {
        JOGADOR,
        ATIRADOR,
        CHEFAO,
        VOADOR,
        PLATAFORMA,
        TEIA,
        ESPINHO,
        PROJETIL,
        PEDRA
    };
    
    class Entidade : public Ente
    {
    protected:
        sf::RectangleShape corpo;
        TIPO tipo;
        sf::Texture textura;
    
    public:
        Entidade(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
        Entidade();
        virtual ~Entidade();

        void setPosicao(const sf::Vector2f pos);
        void desenhar();

        virtual nlohmann::json salvarJogo();
        const sf::RectangleShape getCorpo() const;
        const sf::Vector2f getCentro() const;
        const sf::Vector2f getTamanho() const;
        const sf::Vector2f getPosicao() const;

        virtual void executar(const float dt) = 0;
        virtual void colide(Entidade* ent, const sf::Vector2f intersec) = 0;

        const TIPO getTipo() const { return tipo; };
    };
}

