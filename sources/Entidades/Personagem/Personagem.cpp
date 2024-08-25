#include "../../../include/Entidades/Personagem/Personagem.hpp"

using namespace Entidades;

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
Entidade(pos, tam, tp),
animacao(&corpo)
{
    atacando = false;
    iniciouAtaque = false;
    estaNoChao = false;
    direcao = true;
    tomouDano = false;
    tempoAnimacaoAtaque = 0.0f;
    tempoTomouDano = 0.0f;
    tempoAtaque = 0.0f;
}

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

void Personagem::setDirecao(const bool dir) 
{
    direcao = dir;
}

void Personagem::setAtacando(const bool atk)
{
    if(atk)
    {
        iniciouAtaque = true;
    }
    atacando = atk;
}

float Personagem::getVida() 
{
    return vida;
}

void Personagem::tiraVida(const float dano)
{
    tomouDano = true;
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
