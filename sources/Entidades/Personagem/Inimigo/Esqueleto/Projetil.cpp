#include "../../../../../include/Entidades/Personagem/Inimigo/Esqueleto/Projetil.hpp"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Jogador::Jogador* pJog):
Inimigo(pos, tam)
{
    vel = velocidade;
    pJogador = pJog;
    corpo.setFillColor(sf::Color::Cyan);
    existeProjetil = true;
}

Projetil::Projetil()
{
}

Projetil::~Projetil()
{
}

bool Projetil::saiuDaTela()
{
    if(this->getPosicao().x < 0.0f || this->getPosicao().x > 800.0f || this->getPosicao().y < 0.0f || this->getPosicao().y > 600.0f)
    {
        return true;
    }
    return false;
}

void Projetil::atacar() 
{
    //TODO tirar vida do jogador
}

bool Projetil::atingiuJogador()
{
    if(corpo.getGlobalBounds().intersects(pJogador->getCorpo().getGlobalBounds()))
    {
        return true;
    }
    return false;
}

void Projetil::atualizar(float dt)
{
    sf::Vector2f ds = vel * dt;
    corpo.move(ds);

    if(atingiuJogador())
    {
        existeProjetil = false;
        atacar();
    }
    
    else if(saiuDaTela())
    {
        existeProjetil = false;
    }
}

void Projetil::colide(Entidades* ent, sf::Vector2f intersec)
{

}

    // //acao da gravidade
    // vel.y += GRAVIDADE * dt / 17.0f;
    // corpo.move(sf::Vector2f(vel.x, vel.y));