#include "../../../include/Entidades/Obstaculos/Teia.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Teia::Teia(sf::Vector2f pos):
        Obstaculo(pos, sf::Vector2f(50.0f, 50.0f), TIPO::TEIA),
        densidade(float(rand() % 11 + 25) / 10.0f)
        {
            textura.loadFromFile(CAMINHO_TEXTURA_TEIA);
            corpo.setTexture(&textura);
        }

        Teia::Teia():
        densidade(3.0f)
        {
        }

        Teia::~Teia()
        {
        }

        const float Teia::getDensidade() const 
        {
            return densidade;
        }
    }
}