#include "../../../../../include/Entidades/Personagem/Inimigo/Esqueleto/Projetil.hpp"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Listas::ListaEntidades* listaJog):
Entidades(pos, tam, TIPO::PROJETIL),
listaJogadores(listaJog)
{
    vel = velocidade;
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

void Projetil::atacar(Jogador::Jogador* pJog) 
{
    pJog->perderVida(1.0f);
    //TODO tirar vida do jogador
}

bool Projetil::atingiuJogador()
{
    std::vector<Entidades*>::iterator it;

    for(it = listaJogadores->getInicio(); it != listaJogadores->getFim(); ++it)
    {
        if(corpo.getGlobalBounds().intersects((*it)->getCorpo().getGlobalBounds()))
        {
            atacar(dynamic_cast<Jogador::Jogador*>(*it));
            return true;
        }
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
    }
    
    else if(saiuDaTela())
    {
        existeProjetil = false;
    }
}

void Projetil::colide(Entidades* ent, sf::Vector2f intersec)
{

}