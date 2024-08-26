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
    listaPlataformas = new Listas::ListaEntidades();
    listaObstaculos = new Listas::ListaEntidades();
    listaProjeteis = new Listas::ListaEntidades();
    pColisoes = new Gerenciadores::GerenciadorColisoes(listaJogadores, listaInimigos, listaPlataformas, listaObstaculos, listaProjeteis);
    
    criarMapa();
}

void Fases::Fase::setDoisJogadores(const bool doisJog)
{
    doisJogadores = doisJog;
    inicializar();
}

void Fases::Fase::atualizarBackground()
{
    background.setPosition(pGraf->getCentro().x - pGraf->getTamanho().x / 2, pGraf->getCentro().y - pGraf->getTamanho().y / 2);
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

    case '#':
    {
        criarPlataforma(pos, sf::Vector2f(50.0f, 50.0f));
        break;
    }

    case '-':
    {
        criarPlataforma(pos, sf::Vector2f(100.0f, 50.0f));
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

    case 'r':
    {
        criarPedra(pos);
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

void Fases::Fase::criarPlataforma(sf::Vector2f pos, sf::Vector2f tam)
{
    Plataforma* plataforma = new Plataforma(pos, tam);
    Entidades::Entidade* entPlataforma = static_cast<Entidades::Entidade*>(plataforma);
    listaPlataformas->adicionar(entPlataforma);
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

void Fases::Fase::criarPedra(sf::Vector2f pos)
{
    Obstaculos::Pedra* pedra = new Obstaculos::Pedra(pos);
    Entidades::Entidade* entPedra = static_cast<Entidades::Entidade*>(pedra);
    listaObstaculos->adicionar(entPedra);
}