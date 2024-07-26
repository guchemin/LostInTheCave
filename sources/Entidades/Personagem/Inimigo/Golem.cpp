#include "../../../../include/Entidades/Personagem/Inimigo/Golem.hpp"

Golem::Golem(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Inimigo(pos, tam, listaJog)
{
    vel = sf::Vector2f(VEL_GOLEM, 0.0f);
    corpo.setFillColor(sf::Color(200, 200, 200));
    tempoAtaque = COOLDOWN_GOLEM;
    estaPerseguindo = false;
}

Golem::Golem()
{
}

Golem::~Golem()
{
}

void Golem::perseguir(float dt)
{
    float dx;

    if(pJogador->getPosicao().x > this->getPosicao().x + this->getTamanho().x)
    {   
        vel.x = VEL_GOLEM_PERSEG;
    }
    else if(pJogador->getPosicao().x + pJogador->getTamanho().x < this->getPosicao().x)
    {
        vel.x = -VEL_GOLEM_PERSEG;
    }
    else
    {
        if(consegueAtacar())
        {
            atacar();
        }

        if (fabs(vel.x) < 0.2f)
        {
            vel.x = 0.0f;
        }
        else
        {
            vel.x *= 0.95f;
        }
    }
    
    dx = vel.x * dt;
    corpo.move(dx, 0.0f);
}

void Golem::moverAleatorio(float dt)
{
    float dx;
    ajustaVelocidade();
    
    if(corpo.getPosition().x < posInicial.x - 150.0f || corpo.getPosition().x > posInicial.x + 150.0f)
    {
        vel.x = -vel.x;
    }

    dx = vel.x * dt;
    corpo.move(dx, 0.0f);
}

void Golem::ajustaVelocidade()
{
    if(!estaPerseguindo)
    {
        if(vel.x > 0.0f)
        {
            vel.x = VEL_GOLEM;
        }
        else
        {
            vel.x = -VEL_GOLEM;
        }
    }
}

bool Golem::consegueAtacar()
{
    if(tempoAtaque >= COOLDOWN_GOLEM)
    {
        if(fabs(this->getPosicao().y - pJogador->getPosicao().y) < pJogador->getTamanho().y)
        {
            tempoAtaque = 0.0f;
            return true;
        }
    }
    return false;
}

bool Golem::coseguePerseguir()
{
    return false;   
}

void Golem::atacar()
{  
    pJogador->perderVida(1.0f);
}

void Golem::atualizar(float dt)
{
    setJogador();
    
    float dy;
    sf::Vector2f posGolem = this->getPosicao();
    sf::Vector2f posJog = pJogador->getPosicao();

    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);

    tempoAtaque += dt;
    
    if(fabs(posGolem.x - posJog.x) < RAIO_GOLEM_X && fabs(posGolem.y - posJog.y) < RAIO_GOLEM_Y)
    {
        perseguir(dt);
        estaPerseguindo = true;
        posInicial = posGolem;
    }
    else
    {
        estaPerseguindo = false;
        moverAleatorio(dt);
    }
}

void Golem::colide(Entidades *ent, sf::Vector2f intersec)
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
            vel.x = -vel.x;
        }
        break;
    }

    case TIPO::JOGADOR:
    {
        // Jogador::Jogador *jog = dynamic_cast<Jogador::Jogador*>(ent);
        // setpJogador(jog);

        //TODO tira vida do jogador
        break;
    }
    
    default:
        break;
    }
}