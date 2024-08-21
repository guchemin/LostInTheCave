#include "../../../include/Entidades/Personagem/Jogador.hpp"
#include "../../../include/Entidades/Personagem/Inimigo.hpp"

using namespace Entidades;

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ID i):
id(i),
obs(this),
Personagem(pos, tam, TIPO::JOGADOR)
{
    if(id == JOGADOR1)
    {
        corpo.setFillColor(sf::Color::Red);
        vel = sf::Vector2f(0.0f, 0.0f);
    }
    else if(id == JOGADOR2)
    {
        corpo.setFillColor(sf::Color::Blue);
        vel = sf::Vector2f(0.0f, 0.0f);
    }
    estaNoChao = false;
    pulou = false;
    estaNaTeia = false;
    foiEspinhado = false;
    atacando = false;
    vida = 100.0f;
    aceleracaoTeia = 1.0f;
    dano = 10.0f;
    tempoAtaque = 0.0f;
}

Jogador::Jogador():
obs(this)
{
}

Jogador::~Jogador()
{
}

void Jogador::autorizarPulo(bool autoriza)
{
    pulou = !autoriza;
}

bool Jogador::podePular()
{
    return estaNoChao && !pulou;
}

bool Jogador::podeAtacar()
{
    if(tempoAtaque >= COOLDOWN_ATAQUE)
    {
        tempoAtaque = 0.0f;
        if(atacando)
        {
            atacando = false;
            return true;
        }
    }
    return false;
}

void Jogador::setAtacando(bool atk)
{
    atacando = atk;
}

void Jogador::atacar()
{

}

void Jogador::atualizar(float dt)
{
    tempoAtaque += dt;

    if(estaNaTeia)
    {
        desacelerarTeia();
        estaNaTeia = false;
    }

    ds.y = vel.y * dt;
    ds.x = vel.x * dt;

    if(vel.y > GRAVIDADE * dt)
        estaNoChao = false;
    
    corpo.move(ds);

    // acao da gravidade para a proxima iteracao
    vel.y += GRAVIDADE * dt;
}

void Jogador::pular()
{
    if(id == JOGADOR1)
    {
        vel.y = -PULO_JOG1;
        vel.x *= 1.5f;
    } 
    else if(id == JOGADOR2)
    {
        vel.y = -PULO_JOG2;
        vel.x *= 1.5f;
    }
    estaNoChao = false;
}

void Jogador::andar(bool direita)
{
    if(foiEspinhado)
        return;

    if(id == JOGADOR1)
    {
        vel.x = VEL_JOG1;
        if(!estaNoChao)
            vel.x *= 1.5f;
    }
    else if(id == JOGADOR2)
    {
        vel.x = VEL_JOG2;
        if(!estaNoChao)
            vel.x *= 1.5f;
    }

    if(!direita)
        vel.x *= -1.0f;
}

void Jogador::parar()
{
    vel.x = 0.0f;
}

void Jogador::ajustarVelocidade()
{
    if(vel.x < 0.0f)
    {
        if(id == JOGADOR1)
        {
            vel.x = -VEL_JOG1;
        }
        else if(id == JOGADOR2)
        {
            vel.x = -VEL_JOG2;
        }
    }
    else if(vel.x > 0.0f)
    {
        if(id == JOGADOR1)
        {
            vel.x = VEL_JOG1;
        }
        else if(id == JOGADOR2)
        {
            vel.x = VEL_JOG2;
        }
    }
}

void Jogador::desacelerarTeia()
{
    if(id == JOGADOR1)
    {
        if(fabs(vel.x) > VEL_JOG1 * 0.35)
        {
            vel.x *= aceleracaoTeia;
        }
    }
    else if(id == JOGADOR2)
    {
        if(fabs(vel.x) > VEL_JOG2 * 0.35f)
        {
            vel.x *= aceleracaoTeia;
        }
    }
}

void Jogador::colide(Entidades *ent, sf::Vector2f intersec)
{
    switch (ent->getTipo())
    {
    case TIPO::PLATAFORMA:
    {
        if(intersec.x > intersec.y || vel.x == 0.0f)
        {
            if(getPosicao().y > ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y + ent->getTamanho().y));
            }
            else
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
                ajustarVelocidade();
            }
            vel.y = 0.0f;
            
            if(foiEspinhado)
            {
                vel.x = 0.0f;
                foiEspinhado = false;
            }
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

    case TIPO::TEIA:
    {
        estaNaTeia = true;
        Obstaculos::Teia* teia = static_cast<Obstaculos::Teia*>(ent);
        aceleracaoTeia = 1.0f / teia->getDensidade();
        vel.y *= 2 * aceleracaoTeia;
        break;
    }

    case TIPO::ESPINHO:
    {
        Obstaculos::Espinho* espinho = static_cast<Obstaculos::Espinho*>(ent);
        tiraVida(espinho->getAfiado());
        foiEspinhado = true;

        vel.y = -1000.0f;

        if(getCentro().x > ent->getCentro().x)
        {
            vel.x = 300.0f;
        }
        else
        {
            vel.x = -300.0f;
        }
        break;
    }

    case TIPO::INIMIGO:
    {
        if((intersec.x > intersec.y || vel.x == 0.0f))
        {
            if(getPosicao().y <= ent->getPosicao().y)
            {
                setPosicao(sf::Vector2f(getPosicao().x, ent->getPosicao().y - getTamanho().y));
                estaNoChao = true;
            }
            vel.y = 0.0f;

            if(foiEspinhado)
            {
                vel.x = 0.0f;
                foiEspinhado = false;
            }
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