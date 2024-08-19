#pragma once
#include <cmath>
#include <iostream>
#include "../SFML/Graphics.hpp"

#define GRAVIDADE 5400.0f

namespace Entidades
{    
    enum TIPO
    {
        JOGADOR,
        INIMIGO,
        PLATAFORMA,
        TEIA,
        ESPINHO,
        PROJETIL,
    };
    
    class Entidades 
    {
    protected:
        sf::RectangleShape corpo;
        TIPO tipo;
    
    public:
        Entidades(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
        Entidades();
        virtual ~Entidades();

        void setPosicao(sf::Vector2f pos);
        virtual void atualizar(float dt) = 0;

        sf::RectangleShape getCorpo();
        sf::Vector2f getCentro();
        sf::Vector2f getTamanho();
        sf::Vector2f getPosicao();

        TIPO getTipo() const { return tipo; };
    };
};

