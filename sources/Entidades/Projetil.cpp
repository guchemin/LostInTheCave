#include "../../include/Entidades/Projetil.hpp"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f velocidade):
Entidades(pos, sf::Vector2f(10.0f, 10.0f), TIPO::PROJETIL)
{
    vel = velocidade;
    corpo.setFillColor(sf::Color::Cyan);
}

Projetil::Projetil()
{
}

Projetil::~Projetil()
{
}

void Projetil::setVelocidade(sf::Vector2f v)
{
    vel = v;
}

void Projetil::setPosicao(sf::Vector2f p)
{
    Entidades::setPosicao(p);
}

bool Projetil::saiuDaTela()
{
    if(fabs(getPosicao().x - pGraf->getCentro().x) > pGraf->getTamanho().x / 2.0f || fabs(getPosicao().y - pGraf->getCentro().y) > pGraf->getTamanho().y / 2.0f)
    {
        return true;
    }
    return false;
}

void Projetil::atualizar(float dt)
{
    sf::Vector2f ds = vel * dt;

    //acao da gravidade
    vel.y += 98 * dt;
    ds.y = vel.y * dt;
    
    corpo.move(ds);
}

void Projetil::colide(Entidades* ent, sf::Vector2f intersec)
{
    switch(ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
        setVelocidade(sf::Vector2f(0.0f, 0.0f));
        break;
    }
        
    case TIPO::JOGADOR:
    {
        Jogador* pJog = static_cast<Jogador*>(ent);
        pJog->tiraVida(DANO_ATIRADOR);
        setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
        setVelocidade(sf::Vector2f(0.0f, 0.0f));
        break;
    }
    default:
        break;
    }
}