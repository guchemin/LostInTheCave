#pragma once
#include <iostream>
#include "../SFML/Graphics.hpp"
#define GRAVIDADE 5.0f
#define VEL_JOG1 0.2f
#define VEL_JOG2 0.3f

namespace Entidades
{    
    enum TIPO
    {
        JOGADOR,
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
        float getCentroX();
        float getCentroY();
        float getTamanhoX();
        float getTamanhoY();

        virtual void colide(Entidades* ent, sf::Vector2f intersec) = 0; 
        TIPO getTipo() const {return tipo;};
    };
};