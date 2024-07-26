#include "../../../../include/Entidades/Personagem/Inimigo/Morcego.hpp"

Morcego::Morcego(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidades* listaJog):
Inimigo(pos, tam, listaJog)
{
    vel = sf::Vector2f(VEL_MORCEGO, VEL_MORCEGO);
    corpo.setFillColor(sf::Color(80, 80, 80));
    tempoAtaque = 0.0f;
}

Morcego::Morcego()
{
}

Morcego::~Morcego()
{
}

bool Morcego::consegueAtacar()
{
    if(tempoAtaque >= COOLDOWN_MORCEGO)
    {
        setJogador();
        if(atingiuJogador())
        {
            tempoAtaque = 0.0f;
            return true;
        }
    }
    return false;
}

bool Morcego::atingiuJogador()
{
    return corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds());
}

void Morcego::atacar()
{ 
    pJogador->perderVida(1.0f);
}

void Morcego::atualizar(float dt) 
{
    sf::Vector2f ds;

    tempoAtaque += dt;

    if(corpo.getPosition().y < posInicial.y - 100.0f || corpo.getPosition().y > posInicial.y + 100.0f)
    {
        vel.y = -vel.y;
    }
    if(corpo.getPosition().x < posInicial.x - 300.0f || corpo.getPosition().x > posInicial.x + 300.0f)
    {
        vel.x = -vel.x;
    }
    
    ds = vel * dt;
    corpo.move(ds);

    if(consegueAtacar())
    {
        atacar();
    }
}

void Morcego::colide(Entidades *ent, sf::Vector2f intersec)
{
    std::cout << "colidiu" << std::endl;
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
            vel.y = -vel.y;
        }
        else
        {
            std::cout << "colidiu em x" << std::endl;
            if(corpo.getPosition().x > ent->getCorpo().getPosition().x)
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x + ent->getTamanho().x, corpo.getPosition().y));    
            }
            else
            {
                setPosicao(sf::Vector2f(ent->getPosicao().x - this->getTamanho().x, corpo.getPosition().y));
            }
            std::cout << "passou da colisao"<< std::endl;
            vel.x = -vel.x;
        }
        break;
    }

    case TIPO::JOGADOR:
    {
        //Jogador::Jogador *jog = dynamic_cast<Jogador::Jogador*>(ent);
        //setJogador();

        //TODO tira vida do jogador
        break;
    }
    
    default:
        break;
    }
}

