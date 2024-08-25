#include "../../include/Entidades/Projetil.hpp"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f velocidade):
Entidade(pos, sf::Vector2f(25.0f, 25.0f), TIPO::PROJETIL)
{
    vel = velocidade;
    // corpo.setFillColor(sf::Color::Cyan);

    textura.loadFromFile("../assets/sprites/Projetil/Projetil.png");
    corpo.setTexture(&textura);
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
    Entidade::setPosicao(p);
}

bool Projetil::saiuDaTela()
{
    if(fabs(getPosicao().y - pGraf->getCentro().y) > pGraf->getTamanho().y / 2.0f)
    {
        return true;
    }
    return false;
}

void Projetil::atualizar(const float dt)
{
    sf::Vector2f ds = vel * dt;
    //acao da gravidade
    if(getPosicao().y < 1000.0f)
    {
        vel.y += 60 * dt;
        ds.y = vel.y * dt;
    }
    else
    {
        vel.y = 0.0f;
        ds.y = 0.0f;
    }

    corpo.move(ds);
}

void Projetil::colide(Entidade* ent, const sf::Vector2f intersec)
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