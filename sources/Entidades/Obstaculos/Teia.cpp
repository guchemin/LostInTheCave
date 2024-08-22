#include "../../../include/Entidades/Obstaculos/Teia.hpp"

using namespace Entidades;

Obstaculos::Teia::Teia(sf::Vector2f pos):
Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::TEIA),
densidade(3.0f)
{
    srand(Ente::id * (unsigned)time(0));
    densidade = float(rand() % 11 + 25) / 10.0f;
    corpo.setFillColor(sf::Color(100, 100, 100));
}

Obstaculos::Teia::Teia()
{
}

Obstaculos::Teia::~Teia()
{
}
void Obstaculos::Teia::atualizar(float dt)
{
}
float Obstaculos::Teia::getDensidade()
{
    return densidade;
}