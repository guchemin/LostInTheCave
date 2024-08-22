#include "../../../include/Entidades/Personagem/Chefao.hpp"

Chefao::Chefao(sf::Vector2f pos):
Inimigo(pos, sf::Vector2f(70.0f, 130.0f))
{
    vel = sf::Vector2f(VEL_CHEFAO, 0.0f);
    corpo.setFillColor(sf::Color(200, 200, 200));
    tempoAtaque = COOLDOWN_CHEFAO;
    raioAtaque = RAIO_ATAQUE_CHEFAO;
    estaPerseguindo = false;
    vida = 150.0f;
    dano = DANO_CHEFAO;
}

Chefao::Chefao()
{
}

Chefao::~Chefao()
{
}

void Chefao::perseguir(float dt)
{
    float dx;

    if(pJogador->getPosicao().x > getPosicao().x + getTamanho().x + 1.0)
    {   
        vel.x = VEL_CHEFAO_PERSEG;
    }
    else if(pJogador->getPosicao().x + pJogador->getTamanho().x < getPosicao().x - 1.0f)
    {
        vel.x = -VEL_CHEFAO_PERSEG;
    }
    else
    {
        vel.x = 0.0f;
    }
    
    dx = vel.x * dt;
    corpo.move(dx, 0.0f);
}

void Chefao::moverAleatorio(float dt)
{
    float dx;
    ajustaVelocidade();
    
    if(getPosicao().x < posInicial.x - 150.0f || getPosicao().x > posInicial.x + 150.0f)
    {
        vel.x = -vel.x;
    }

    dx = vel.x * dt;
    corpo.move(dx, 0.0f);
}

void Chefao::ajustaVelocidade()
{
    if(!estaPerseguindo)
    {
        if(vel.x > 0.0f)
        {
            vel.x = VEL_CHEFAO;
        }
        else
        {
            vel.x = -VEL_CHEFAO;
        }
    }
}

bool Chefao::consegueAtacar()
{
    if(tempoAtaque >= COOLDOWN_CHEFAO)
    {
        tempoAtaque = 0.0f;
        return true;
    }
    return false;
}

bool Chefao::conseguePerseguir()
{
    return false;   
}

void Chefao::atacar()
{  
    pJogador->tiraVida(dano);
}

void Chefao::agir()
{
    if(consegueAtacar())
    {
        atacar();
    }
}

void Chefao::atualizar(float dt)
{
    float dy;
    sf::Vector2f posChefao = getPosicao();

    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);

    tempoAtaque += dt;
    
    if(pJogador == NULL)
    {
        estaPerseguindo = false;
        moverAleatorio(dt);
        return;
    }    
    
    sf::Vector2f posJog = pJogador->getPosicao();
    if(fabs(posChefao.x - posJog.x) < RAIO_CHEFAO_X && fabs(posChefao.y - posJog.y) < RAIO_CHEFAO_Y)
    {
        perseguir(dt);
        estaPerseguindo = true;
        posInicial = posChefao;
    }
    else
    {
        estaPerseguindo = false;
        moverAleatorio(dt);
    }
}

void Chefao::colide(Entidades *ent, sf::Vector2f intersec)
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
            vel.x = -vel.x;
        }
        break;
    }

    case TIPO::JOGADOR:
        break;

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
            vel.x = -vel.x;
        }
        break;
    }
    
    default:
        break;
    }
}