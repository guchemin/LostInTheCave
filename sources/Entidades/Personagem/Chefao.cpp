#include "../../../include/Entidades/Personagem/Chefao.hpp"

Chefao::Chefao(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Inimigo(pos, tam, listaJog)
{
    vel = sf::Vector2f(VEL_CHEFAO, 0.0f);
    corpo.setFillColor(sf::Color(200, 200, 200));
    tempoAtaque = COOLDOWN_CHEFAO;
    estaPerseguindo = false;
    vida = 150.0f;
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

        if(consegueAtacar())
        {
            atacar();
        }
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
        if(fabs(getPosicao().y - pJogador->getPosicao().y) < pJogador->getTamanho().y)
        {
            tempoAtaque = 0.0f;
            return true;
        }
    }
    return false;
}

bool Chefao::conseguePerseguir()
{
    return false;   
}

void Chefao::atacar()
{  
    pJogador->perderVida(DANO_CHEFAO);
}

void Chefao::parar()
{
}

void Chefao::atualizar(float dt)
{
    setJogador();
    
    float dy;
    sf::Vector2f posChefao = getPosicao();
    sf::Vector2f posJog = pJogador->getPosicao();

    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    dy = vel.y * dt;
    corpo.move(0.0f, dy);

    tempoAtaque += dt;
    
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