#pragma once

#include "../Personagem.hpp"

namespace Inimigo
{
    enum ID
    {
    INIM1, // morcego
    INIM2, //golem
    INIM3  //esqueleto 
    };

    class Inimigo: public Personagem
    {
    private:
        ID id;

    public:
        Inimigo(sf::Vector2f pos, sf::Vector2f tam, ID i);
        Inimigo();
        ~Inimigo();

        void mover(float dt);
    };
};

