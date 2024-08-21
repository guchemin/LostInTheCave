#include "../../../include/Entidades/Personagem/Projetil.hpp"

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Listas::ListaEntidades* listaJog):
Entidades(pos, tam, TIPO::PROJETIL),
listaJogadores(listaJog)
{
    vel = velocidade;
    corpo.setFillColor(sf::Color::Cyan);
}

Projetil::Projetil()
{
}

Projetil::~Projetil()
{
}

void Projetil::setVelocidade(sf::Vector2f v)
{
    vel = v;
}

void Projetil::setPosicao(sf::Vector2f p)
{
    Entidades::setPosicao(p);
}

bool Projetil::saiuDaTela()
{
    if(fabs(getPosicao().x - pGraf->getCentro().x) > 400.0 || fabs(getPosicao().y - pGraf->getCentro().y) > 300.0)
    {
        return true;
    }
    return false;
}

void Projetil::atacar(Jogador* pJog) 
{
    pJog->tiraVida(DANO_ATIRADOR);
}

bool Projetil::atingiuJogador()
{
    Jogador* pJog;
    int tamJog = listaJogadores->getTam();

    for(int i = 0; i < tamJog; i++)
    {
        pJog = static_cast<Jogador*>((*listaJogadores)[i]);

        if(corpo.getGlobalBounds().intersects((pJog)->getCorpo().getGlobalBounds()))
        {
            atacar(pJog);
            
            return true;
        }
    }
    return false;
}

void Projetil::atualizar(float dt)
{
    sf::Vector2f ds = vel * dt;

    //acao da gravidade
    vel.y += 98 * dt;
    ds.y = vel.y * dt;
    
    corpo.move(ds);
}

void Projetil::colide(Entidades* ent, sf::Vector2f intersec)
{

}