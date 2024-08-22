#include "../../include/Fases/Fase.hpp"

Fases::Fase::Fase():
Ente(),
pEventos(GerenciadorEventos::getInstancia())
{
}

Fases::Fase::~Fase()
{
}

void Fases::Fase::inicializar()
{
    listaJogadores = new Listas::ListaEntidades();
    listaInimigos = new Listas::ListaEntidades();
    listaObstaculos = new Listas::ListaEntidades();
    listaProjeteis = new Listas::ListaEntidades();
    pColisoes = new Gerenciadores::GerenciadorColisoes(listaJogadores, listaInimigos, listaObstaculos, listaProjeteis);  
    
    criarMapa();
}

void Fases::Fase::centralizarCamera()
{
    int tam = listaJogadores->getTam();
    float media;
    float diferenca;
    float soma = 0.0f;

    if(tam == 0)
    {
        // implementar GAME OVER
    }
    else if(tam == 1)
    {
        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
    }
    else if(tam == 2)
    {
        diferenca = (*listaJogadores)[0]->getCentro().x - (*listaJogadores)[1]->getCentro().x;
        soma = (*listaJogadores)[0]->getCentro().x + (*listaJogadores)[1]->getCentro().x;

        media = soma/tam;

        if(diferenca > 750.0f)
        {
            pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
        }
        else if(diferenca < -750.0f)
        {
            pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[1]->getCentro().x, 450.0f));
        }
        else
        {
            pGraf->centralizarCamera(sf::Vector2f(media, 450.0f));
        }
    }
}

void Fases::Fase::criarEntidade(sf::Vector2f pos, char caracter)
{
    switch (caracter)
    {
    case 'j':
    {
        criarJogador(pos);
        break;
    }
    
    case 'a':
    {
        criarAtirador(pos);
        break;
    }

    case 'v':
    {
        criarVoador(pos);
        break;
    }

    case 'c':
    {
        criarChefao(pos);
        break;
    }

    case 'p':
    {
        criarPlataforma(pos);
        break;
    }

    case 't':
    {
        criarTeia(pos);
        break;
    }

    case 'e':
    {
        criarEspinho(pos);
        break;
    }
    
    default:
        break;
    }
}

void Fases::Fase::criarJogador(sf::Vector2f pos)
{
    if(listaJogadores->getTam() == 0)
    {
        Jogador* jogador = new Jogador(pos, ID::JOGADOR1);
        Entidades::Entidades* entJog = static_cast<Entidades::Entidades*>(jogador);
        listaJogadores->adicionar(entJog);
        pEventos->setJogador(jogador);
    }
    else if(listaJogadores->getTam())
    {
        Jogador* jogador = new Jogador(pos, ID::JOGADOR2);
        Entidades::Entidades* entJog = static_cast<Entidades::Entidades*>(jogador);
        listaJogadores->adicionar(entJog);
        pEventos->setJogador(jogador);
    }
}

void Fases::Fase::criarAtirador(sf::Vector2f pos)
{
    Atirador* atirador = new Atirador(pos);
    Projetil* projetil = new Projetil(sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(0.0f, 0.0f));
    atirador->setProjetil(projetil);

    Entidades::Entidades* entAtirador = static_cast<Entidades::Entidades*>(atirador);
    Entidades::Entidades* entProjetil = static_cast<Entidades::Entidades*>(projetil);

    listaInimigos->adicionar(entAtirador);
    listaProjeteis->adicionar(entProjetil);
}

void Fases::Fase::criarVoador(sf::Vector2f pos)
{
    Voador* voador = new Voador(pos);
    Entidades::Entidades* entVoador = static_cast<Entidades::Entidades*>(voador);
    listaInimigos->adicionar(entVoador);
}

void Fases::Fase::criarChefao(sf::Vector2f pos)
{
    Chefao* chefao = new Chefao(pos);
    Entidades::Entidades* entChefao = static_cast<Entidades::Entidades*>(chefao);
    listaInimigos->adicionar(entChefao);
}

void Fases::Fase::criarPlataforma(sf::Vector2f pos)
{
    Obstaculos::Plataforma* plataforma = new Obstaculos::Plataforma(pos);
    Entidades::Entidades* entPlataforma = static_cast<Entidades::Entidades*>(plataforma);
    listaObstaculos->adicionar(entPlataforma);
}

void Fases::Fase::criarTeia(sf::Vector2f pos)
{
    Obstaculos::Teia* teia = new Obstaculos::Teia(pos);
    Entidades::Entidades* entTeia = static_cast<Entidades::Entidades*>(teia);
    listaObstaculos->adicionar(entTeia);
}

void Fases::Fase::criarEspinho(sf::Vector2f pos)
{
    Obstaculos::Espinho* espinho = new Obstaculos::Espinho(pos);
    Entidades::Entidades* entEspinho = static_cast<Entidades::Entidades*>(espinho);
    listaObstaculos->adicionar(entEspinho);
}
