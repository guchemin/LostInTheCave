#include "../../../../../include/Entidades/Personagem/Inimigo/Esqueleto/Projetil.hpp"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Listas::ListaEntidades* listaJog):
Entidades(pos, tam, TIPO::PROJETIL),
listaJogadores(listaJog),
posInicial(pos)
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
    if(getPosicao().x < posInicial.x - 1000.0f || getPosicao().x > posInicial.x + 1000.0 || getPosicao().y < 0.0f || getPosicao().y > 600.0f)
    {
        return true;
    }
    return false;
}

void Projetil::atacar(Jogador::Jogador* pJog) 
{
    pJog->perderVida(DANO_ESQUELETO);
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