#pragma once

#include "Entidade.hpp"

#define CAMINHO_TEXTURA_PAREDE "../assets/sprites/Plataforma/Parede.png"
#define CAMINHO_TEXTURA_CHAO "../assets/sprites/Plataforma/Chao.png"
#define CAMINHO_TEXTURA_FALSO "../assets/sprites/Plataforma/Falso.png"

class Plataforma: public Entidades::Entidade
{
private:
    const bool ehFalsa;
    
public:
    Plataforma(sf::Vector2f pos, sf::Vector2f tam);
    Plataforma();
    ~Plataforma();

    const bool getFalsa() const;
};