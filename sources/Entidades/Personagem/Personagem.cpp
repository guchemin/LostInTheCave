#include "../../../include/Entidades/Personagem/Personagem.hpp"

using namespace Entidades;

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
Entidade(pos, tam, tp)
{
}

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

float Personagem::getVida()
{
    return vida;
}

void Personagem::tiraVida(const float dano)
{
    vida -= dano;
}

float Personagem::getRaioAtaque()
{
    return raioAtaque;
}

float Personagem::getDano()
{
    return dano;
}
