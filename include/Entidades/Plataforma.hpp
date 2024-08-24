#pragma once

#include "Entidade.hpp"

class Plataforma: public Entidades::Entidade
{
private:
    const bool ehFalsa;
    
public:
    Plataforma(sf::Vector2f pos);
    Plataforma();
    ~Plataforma();

    const bool getFalsa() const;
};