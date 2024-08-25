#include "../../../include/Entidades/Obstaculos/Espinho.hpp"

using namespace Entidades;

Obstaculos::Espinho::Espinho(sf::Vector2f pos):
Obstaculo(pos, sf::Vector2f(100.0f, 50.0f), TIPO::ESPINHO),
afiado(float(rand() % 101 + 50) / 10.0f)
{
    textura.loadFromFile(CAMINHO_TEXTURA_ESPINHO);
    corpo.setTexture(&textura);
    corpo.setScale(1.2f, 1.2f);
    corpo.setOrigin(10.0f, 8.0f);
}

Obstaculos::Espinho::Espinho():
afiado(10.0f)
{
}

Obstaculos::Espinho::~Espinho()
{
}

const float Obstaculos::Espinho::getAfiado() const
{
    return afiado;
}