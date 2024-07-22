#pragma once
#include <cmath>
#include <iostream>
#include "../SFML/Graphics.hpp"

#define GRAVIDADE 98.1f
#define VEL_ESQUELETO 3.0f

namespace Entidades
{    
    enum TIPO
    {
        JOGADOR,
        INIMIGO,
        PLATAFORMA
    };
    
    class Entidades 
    {
    protected:
        sf::RectangleShape corpo;
        TIPO tipo;
    
    public:
        Entidades(sf::Vector2f pos, sf::Vector2f tam, TIPO tp);
        Entidades();
        ~Entidades();

        void setPosicao(sf::Vector2f pos);
        sf::RectangleShape getCorpo();
        sf::Vector2f getCentro();
        sf::Vector2f getTamanho();
        sf::Vector2f getPosicao();

        virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0; 
        TIPO getTipo() const {return tipo;};
    };
};