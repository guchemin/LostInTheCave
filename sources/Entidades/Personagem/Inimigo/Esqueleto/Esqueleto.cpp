#include "../../../../../include/Entidades/Personagem/Inimigo/Esqueleto/Esqueleto.hpp"

Esqueleto::Esqueleto(sf::Vector2f pos, sf::Vector2f tam):
Inimigo(pos, tam)
{
    std::cout << "esqueleto" << std::endl;
    vel = sf::Vector2f(0.0f, 0.0f);
    corpo.setFillColor(sf::Color(255, 255, 255));
    corpo.setOutlineColor(sf::Color::Red);

    tempoAtaque = 0.0f;
}

Esqueleto::Esqueleto()
{
    listaProjetil = NULL;
}

Esqueleto::~Esqueleto()
{
    listaProjetil->limpar();
}

bool Esqueleto::consegueAtacar()
{
    // verifica distancia
    float dist = sqrt(pow(pJogador->getPosicao().x - this->getPosicao().x, 2) + pow(pJogador->getPosicao().y - this->getPosicao().y, 2));
    std::cout << "distancia" << std::endl;
    // verifica cooldown
    if(tempoAtaque >= COOLDOWN_ESQUELETO)
    {
        std::cout << "cooldown" << std::endl;
        tempoAtaque = 0.0f;
        return (dist < RAIO_ESQUELETO);
    }
    std::cout << "naoconsegueatacar" << std::endl;
    return false;
}

void Esqueleto::atacar()
{
    std::cout << "atacar" << std::endl;
    sf::Vector2f velProj = sf::Vector2f(-1.0f, 0.0f);
    Projetil* projetil;
    projetil = new Projetil(this->getPosicao(), sf::Vector2f(10.0f, 10.0f), velProj, pJogador, listaProjetil);
}

void Esqueleto::atualizar(float dt)
{
    //acao da gravidade
    vel.y += GRAVIDADE * dt;
    corpo.move(0.0f, vel.y);

    tempoAtaque += dt;

    std::cout << "consegueatakar" << std::endl;
    if(consegueAtacar())
    {
        atacar();
    }
    std::cout << "atualizar" << std::endl;
    if(listaProjetil != NULL)
        listaProjetil->atualizar(dt);
    std::cout << "atualizou" << std::endl;
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
