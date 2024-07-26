#include "../../../../../include/Entidades/Personagem/Inimigo/Esqueleto/Esqueleto.hpp"

using namespace Gerenciadores;

Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
pGraf(Graficos::getInstancia()),
Inimigo(pos, tam, listaJog)
{
    vel = sf::Vector2f(0.0f, 0.0f);
    corpo.setFillColor(sf::Color(255, 255, 255));
    corpo.setOutlineColor(sf::Color::Red);
    pProjetil = NULL;
    tempoAtaque = 0.0f;
}

Esqueleto::Esqueleto()
{

}

Esqueleto::~Esqueleto()
{
    pProjetil = NULL;
}

bool Esqueleto::consegueAtacar()
{
    // verifica cooldown
    if(tempoAtaque >= COOLDOWN_ESQUELETO)
    {
        setJogador();

        // verifica distancia
        float dist = sqrt(pow(pJogador->getPosicao().x - this->getPosicao().x, 2) + pow(pJogador->getPosicao().y - this->getPosicao().y, 2));

        tempoAtaque = 0.0f;
        if(pProjetil == NULL)
            return (dist < RAIO_ESQUELETO);
    }
    return false;
}

void Esqueleto::atacar()
{
    sf::Vector2f velProj = calcVel();
    sf::Vector2f posProj = sf::Vector2f(this->getCentro().x, this->getPosicao().y + this->getTamanho().y / 4.0f);
    pProjetil = new Projetil(posProj, sf::Vector2f(10.0f, 10.0f), velProj, listaJogadores);
}

void Esqueleto::atualizar(float dt)
{
    float dy;
    
    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);

    tempoAtaque += dt;

    if(consegueAtacar())
    {
        atacar();
    }
    
    if(pProjetil != NULL && pProjetil->existeProjetil)
    {
        pProjetil->atualizar(dt);
        pGraf->desenhar(pProjetil->getCorpo());
        if(!pProjetil->existeProjetil)
        {
            delete pProjetil;
            pProjetil = NULL;
        }    
    }
        
}

sf::Vector2f Esqueleto::calcVel()
{
    float Dx;
    float Dy;
    float theta;
    sf::Vector2f velProj;

    if(pJogador->getCentro().x > this->getCentro().x)
    {    
        Dx = pJogador->getPosicao().x - this->getCentro().x;
    }
    else
    {    
        Dx = this->getCentro().x - (pJogador->getPosicao().x + pJogador->getTamanho().x);
    }
    
    Dy = pJogador->getCentro().y - this->getCentro().y;

    theta = atan(fabs(Dy / Dx));

    if(pJogador->getCentro().x > this->getCentro().x)
    {    
        velProj.x = VEL_PROJ * cos(theta);
    }
    else
    {
        velProj.x = -VEL_PROJ * cos(theta);
    }

    if(pJogador->getCentro().y > this->getCentro().y)
    {
        velProj.y = VEL_PROJ * sin(theta);
    }
    else
    {
        velProj.y = -VEL_PROJ * sin(theta);
    }

    return velProj;
}

void Esqueleto::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y)
        {
            if(corpo.getPosition().y > ent->getCorpo().getPosition().y)
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(corpo.getPosition().x, ent->getPosicao().y - this->getTamanho().y));
                estaNoChao = true;
            }
            vel.y = 0.0f;
        }
        else
        {
            if(corpo.getPosition().x > ent->getCorpo().getPosition().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, corpo.getPosition().y));    
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x - this->getTamanho().x, corpo.getPosition().y));
            }
        }
        break;
    }
    
    default:
        break;
    }
}


// sf::Vector2f Esqueleto::calcVel()
// {
//     sf::Vector2f velProj;
//     if(pJogador->getCentro().x > this->getCentro().x)
//         velProj.x = VEL_PROJ_X;
//     else
//         velProj.x = -VEL_PROJ_X;
    
//     float t = fabs(pJogador->getCentro().x - this->getCentro().x) / VEL_PROJ_X;
//     velProj.y = (pJogador->getCentro().y - this->getCentro().y) / t - 0.5f * GRAVIDADE / 1000.f * t;

//     return velProj;
// }