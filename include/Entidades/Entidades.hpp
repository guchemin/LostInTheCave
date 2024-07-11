#pragma once

#include "../SFML/Graphics.hpp"

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
        
        sf::RectangleShape getCorpo();
    };
};