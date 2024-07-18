#include "../../../include/Entidades/Personagem/Personagem.hpp"
using namespace Entidades;

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, TIPO tp):
Entidades(pos, tam, tp)
{
}

Personagem::Personagem()
{
}

Personagem::~Personagem()
{
}

void Personagem::colide(Entidades* ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y)
        {
            if(corpo.getPosition().y > ent->getCorpo().getPosition().y)
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicaoY() + ent->getTamanhoY()));
            }
            else
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicaoY() - this->getTamanhoY()));
                estaNoChao = true;
            }
            vel.y = 0.0f;
        }
        else
        {
            if(corpo.getPosition().x > ent->getCorpo().getPosition().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicaoX() + ent->getTamanhoX(), corpo.getPosition().y));    
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicaoX() - this->getTamanhoX(), corpo.getPosition().y));
            }
        }
    }
        break;
    
    default:
        break;
    }
}
