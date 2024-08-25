#include "../../include/Entidades/Plataforma.hpp"

using namespace Entidades;

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam):
Entidade(pos, tam, TIPO::PLATAFORMA),
ehFalsa(!(bool)(rand() % 20 || tam.x == 50.0f))
{
    if(tam.x == 50.0f)
    {
        textura.loadFromFile(CAMINHO_TEXTURA_PAREDE);
        corpo.setTexture(&textura);
        corpo.setScale(1.8f, 1.8f);
        corpo.setOrigin(8.0f, 12.0f);
    }
    else if(tam.x == 100.0f)
    {
        if(!ehFalsa)
        {
            textura.loadFromFile(CAMINHO_TEXTURA_CHAO);
            corpo.setTexture(&textura);
            corpo.setScale(1.1f, 1.5f);
            corpo.setOrigin(8.0f, 8.0f);
        }
        else
        {
            textura.loadFromFile(CAMINHO_TEXTURA_FALSO);
            corpo.setTexture(&textura);
            corpo.setScale(1.1f, 1.5f);
            corpo.setOrigin(8.0f, 11.0f);
        }
        
    }
}

Plataforma::Plataforma():
ehFalsa(false)
{
}

Plataforma::~Plataforma()
{
}

const bool Plataforma::getFalsa() const
{
    return ehFalsa;
}
