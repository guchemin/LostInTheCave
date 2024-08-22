#include "../../../include/Entidades/Personagem/Atirador.hpp"

using namespace Gerenciadores;

Atirador::Atirador(sf::Vector2f pos):
Inimigo(pos, sf::Vector2f(50.0f, 90.0f))
{
    vel = sf::Vector2f(0.0f, 0.0f);
    corpo.setFillColor(sf::Color(255, 255, 255));
    corpo.setOutlineColor(sf::Color::Red);
    pProjetil = NULL;
    raioAtaque = RAIO_ATIRADOR;
    tempoAtaque = 0.0f;
    vida = 60.0f;
    dano = DANO_ATIRADOR;
}

Atirador::Atirador()
{

}

Atirador::~Atirador()
{
    pProjetil = NULL;
}

void Atirador::setProjetil(Projetil *proj)
{
    if(proj)
    {
        pProjetil = proj;
    }
}

bool Atirador::consegueAtacar() 
{
    // verifica cooldown
    if(tempoAtaque >= COOLDOWN_ATIRADOR)
    {
        tempoAtaque = 0.0f;
        if(pProjetil->getPosicao().x == -1000.0f && pProjetil->getPosicao().y == -1000.0f)
        {
            return true;
        }
    }
    return false;
}

void Atirador::atacar()
{
    sf::Vector2f velProj = calcVel();
    sf::Vector2f posProj = sf::Vector2f(getCentro().x, getPosicao().y + getTamanho().y / 2.0f);
    pProjetil->setPosicao(posProj);
    pProjetil->setVelocidade(velProj);
}

void Atirador::agir()
{
    if(consegueAtacar())
    {
        atacar();
    }
}

void Atirador::atualizar(float dt)
{
    float dy;
    
    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);

    tempoAtaque += dt;

    pProjetil->atualizar(dt);
    pProjetil->desenhar();
    if(pProjetil->saiuDaTela())
    {
        pProjetil->setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
        pProjetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
    }
}

sf::Vector2f Atirador::calcVel()
{
    if(pJogador == NULL)
    {
        return sf::Vector2f(0.0f, 0.0f);
    }
    
    float Dx;
    float Dy;
    float theta;
    sf::Vector2f velProj;

    if(pJogador->getCentro().x > getCentro().x)
    {    
        Dx = pJogador->getPosicao().x - getCentro().x;
    }
    else
    {    
        Dx = getCentro().x - (pJogador->getPosicao().x + pJogador->getTamanho().x);
    }
    
    Dy = (pJogador->getPosicao().y + pJogador->getTamanho().y / 4.0f) - (getPosicao().y + getTamanho().y / 2.0f);

    theta = atan(fabs(Dy / Dx));

    if(pJogador->getCentro().x > getCentro().x)
    {    
        velProj.x = VEL_PROJ * cos(theta);
    }
    else
    {
        velProj.x = -VEL_PROJ * cos(theta);
    }

    if(pJogador->getPosicao().y > getPosicao().y)
    {
        velProj.y = VEL_PROJ * sin(theta);
    }
    else
    {
        velProj.y = -VEL_PROJ * sin(theta);
    }

    return velProj;
}

void Atirador::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y)
        {
            if(getPosicao().y > ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
            }
            vel.y = 0.0f;
        }
        else
        {
            if(getPosicao().x > ent->getPosicao().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));    
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
            }
        }
        break;
    }
    
    case TIPO::INIMIGO:
    {
        if(intersec.x > intersec.y)
        {
            if(getPosicao().y > ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
            }
            vel.y = 0.0f;
        }
        else
        {
            if(getPosicao().x > ent->getPosicao().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, getPosicao().y));    
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x - getTamanho().x, getPosicao().y));
            }
        }
        break;
    }

    default:
        break;
    }
}