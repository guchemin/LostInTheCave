#include "../../../include/Entidades/Obstaculos/Espinho.hpp"

using namespace Entidades;

Obstaculos::Espinho::Espinho(sf::Vector2f pos):
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::ESPINHO),
afiado(10.0f)
{
    srand(Ente::id * (unsigned)time(0));
    afiado = float(rand() % 101 + 100) / 10.0f;
    corpo.setFillColor(sf::Color(123, 15, 165));
}

Obstaculos::Espinho::Espinho()
{
}

Obstaculos::Espinho::~Espinho()
{
}

void Obstaculos::Espinho::atualizar(float dt)
{
}

float Obstaculos::Espinho::getAfiado()
{
    return afiado;
}