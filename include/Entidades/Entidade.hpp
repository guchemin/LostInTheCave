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

        void setPosicao(sf::Vector2f pos);
        void desenhar();

        virtual nlohmann::json salvarJogo();
        sf::RectangleShape getCorpo();
        sf::Vector2f getCentro();
        sf::Vector2f getTamanho();
        sf::Vector2f getPosicao();
        virtual void colide(Entidade* ent, const sf::Vector2f intersec){};

        TIPO getTipo() const { return tipo; };
    };
}

