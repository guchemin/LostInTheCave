#include "../../../../../include/Entidades/Personagem/Inimigo/Esqueleto/Projetil.hpp"

using namespace Gerenciadores;

Projetil::Projetil(sf::Vector2f pos, sf::Vector2f tam, sf::Vector2f velocidade, Jogador::Jogador* pJog, Listas::ListaEntidades* lista):
pGraf(Graficos::getInstancia()),
Inimigo(pos, tam)
{
    listaProjetil = lista;
    vel = velocidade;
    pJogador = pJog;
    corpo.setFillColor(sf::Color::Cyan);
    lista->adicionar(this);
}

Projetil::Projetil()
{
    listaProjetil = NULL;
}

Projetil::~Projetil()
{
    listaProjetil->limpar();
}

bool Projetil::saiuDaTela()
{
    if(corpo.getPosition().x < 0.0f || corpo.getPosition().x > 800.0f || corpo.getPosition().y < 0.0f || corpo.getPosition().y > 600.0f)
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
    //acao da gravidade
    //vel.y += GRAVIDADE * dt / 2.0f;
    corpo.move(vel);

    if(atingiuJogador())
    {
        atacar();
    }

    if(saiuDaTela())
    {
        listaProjetil->remover(this);
    }

    listaProjetil->desenhar(pGraf->getJanela());
}

void Projetil::colide(Entidades* ent, sf::Vector2f intersec)
{
}