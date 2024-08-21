#include "../../../include/Entidades/Personagem/Atirador.hpp"

using namespace Gerenciadores;

Atirador::Atirador(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Inimigo(pos, tam, listaJog)
{
    vel = sf::Vector2f(0.0f, 0.0f);
    corpo.setFillColor(sf::Color(255, 255, 255));
    corpo.setOutlineColor(sf::Color::Red);
    pProjetil = NULL;
    tempoAtaque = 0.0f;
    vida = 60.0f;
    pProjetil = new Projetil(sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(10.0f, 10.0f), sf::Vector2f(0.0f, 0.0f), listaJogadores);
}

Atirador::Atirador()
{

}

Atirador::~Atirador()
{
    delete pProjetil;
    pProjetil = NULL;
}

bool Atirador::consegueAtacar()
{
    // verifica cooldown
    if(tempoAtaque >= COOLDOWN_ATIRADOR)
    {
        setJogador();

        // verifica distancia
        float dist = sqrt(pow(pJogador->getPosicao().x - getPosicao().x, 2) + pow(pJogador->getPosicao().y - getPosicao().y, 2));

        tempoAtaque = 0.0f;
        if(pProjetil->getPosicao().x == -1000.0f && pProjetil->getPosicao().y == -1000.0f)
        {
            return (dist < RAIO_ATIRADOR);
        }
    }
    return false;
}

void Atirador::atacar()
{
    sf::Vector2f velProj = calcVel();
    sf::Vector2f posProj = sf::Vector2f(getCentro().x, getPosicao().y + getTamanho().y / 4.0f);
    pProjetil->setPosicao(posProj);
    pProjetil->setVelocidade(velProj);
}

void Atirador::parar()
{
}

void Atirador::atualizar(float dt)
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

    pProjetil->atualizar(dt);
    pProjetil->desenhar();
    if(pProjetil->atingiuJogador() || pProjetil->saiuDaTela())
    {
        pProjetil->setPosicao(sf::Vector2f(-1000.0f, -1000.0f));
        pProjetil->setVelocidade(sf::Vector2f(0.0f, 0.0f));
    }
        
}

sf::Vector2f Atirador::calcVel()
{
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
    
    Dy = pJogador->getPosicao().y - getCentro().y;

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
    
    default:
        break;
    }
}