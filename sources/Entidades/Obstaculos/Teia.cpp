#include "../../../include/Entidades/Obstaculos/Teia.hpp"

using namespace Entidades;

Obstaculos::Teia::Teia(sf::Vector2f pos):
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::TEIA),
densidade(float(rand() % 11 + 25) / 10.0f)
{
    textura.loadFromFile(CAMINHO_TEXTURA_TEIA);
    corpo.setTexture(&textura);
}

Obstaculos::Teia::Teia():
densidade(3.0f)
{
}

Obstaculos::Teia::~Teia()
{
}

const float Obstaculos::Teia::getDensidade() const 
{
    return densidade;
}