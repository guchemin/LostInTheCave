#include "../../include/Fases/Fase.hpp"

Fases::Fase::Fase(Estados::EstadoID id):
Ente(),
Estado(id),
pEventos(GerenciadorEventos::getInstancia())
{
}

Fases::Fase::Fase()
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

void Fases::Fase::setDoisJogadores(const bool doisJog)
{
    doisJogadores = doisJog;
    cout << doisJogadores << endl;
    inicializar();
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

Listas::ListaEntidades *Fases::Fase::getListaJogadores()
{
    return listaJogadores;
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
        Entidades::Entidade* entJog = static_cast<Entidades::Entidade*>(jogador);
        listaJogadores->adicionar(entJog);
    }
    else if(listaJogadores->getTam() && doisJogadores)
    {
        Jogador* jogador = new Jogador(pos, ID::JOGADOR2);
        Entidades::Entidade* entJog = static_cast<Entidades::Entidade*>(jogador);
        listaJogadores->adicionar(entJog);
    }
}

void Fases::Fase::criarAtirador(sf::Vector2f pos)
{
    Atirador* atirador = new Atirador(pos);
    Projetil* projetil = new Projetil(sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(0.0f, 0.0f));
    atirador->setProjetil(projetil);

    Entidades::Entidade* entAtirador = static_cast<Entidades::Entidade*>(atirador);
    Entidades::Entidade* entProjetil = static_cast<Entidades::Entidade*>(projetil);

    listaInimigos->adicionar(entAtirador);
    listaProjeteis->adicionar(entProjetil);
}

void Fases::Fase::criarVoador(sf::Vector2f pos)
{
    Voador* voador = new Voador(pos);
    Entidades::Entidade* entVoador = static_cast<Entidades::Entidade*>(voador);
    listaInimigos->adicionar(entVoador);
}

void Fases::Fase::criarChefao(sf::Vector2f pos)
{
    Chefao* chefao = new Chefao(pos);
    Entidades::Entidade* entChefao = static_cast<Entidades::Entidade*>(chefao);
    listaInimigos->adicionar(entChefao);
}

void Fases::Fase::criarPlataforma(sf::Vector2f pos)
{
    Obstaculos::Plataforma* plataforma = new Obstaculos::Plataforma(pos);
    Entidades::Entidade* entPlataforma = static_cast<Entidades::Entidade*>(plataforma);
    listaObstaculos->adicionar(entPlataforma);
}

void Fases::Fase::criarTeia(sf::Vector2f pos)
{
    Obstaculos::Teia* teia = new Obstaculos::Teia(pos);
    Entidades::Entidade* entTeia = static_cast<Entidades::Entidade*>(teia);
    listaObstaculos->adicionar(entTeia);
}

void Fases::Fase::criarEspinho(sf::Vector2f pos)
{
    Obstaculos::Espinho* espinho = new Obstaculos::Espinho(pos);
    Entidades::Entidade* entEspinho = static_cast<Entidades::Entidade*>(espinho);
    listaObstaculos->adicionar(entEspinho);
}
