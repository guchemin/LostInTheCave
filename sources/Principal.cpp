#include "../include/Principal.hpp"

using namespace Gerenciadores;

Principal::Principal():
pGraf(Graficos::getInstancia()),
pEventos(Eventos::getInstancia())
{
    pGraf->getJanela()->setFramerateLimit(60);
    inicializar();
    executar();
}

Principal::~Principal()
{
    pGraf = NULL;
    pColisoes = NULL;
    pEventos = NULL;
    listaInimigos->limpar();
    listaJogadores->limpar();
    listaPlataformas->limpar();
}

void Principal::inicializar()
{
    listaJogadores = new Listas::ListaEntidades();
    listaInimigos = new Listas::ListaEntidades();
    listaPlataformas = new Listas::ListaEntidades();
    pColisoes = new Gerenciadores::Colisoes(listaJogadores, listaInimigos, listaPlataformas);
    
    inicializarJogadores();
    inicializarInimigos();
    inicializarPlataformas();   
}

void Principal::inicializarJogadores()
{
    Jogador::Jogador* jogador1 = new Jogador::Jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), Jogador::ID::JOGADOR1);
    Jogador::Jogador* jogador2 = new Jogador::Jogador(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f), Jogador::ID::JOGADOR2);

    Entidades::Entidades* entJog1 = dynamic_cast<Entidades::Entidades*>(jogador1);
    Entidades::Entidades* entJog2 = dynamic_cast<Entidades::Entidades*>(jogador2);

    pEventos->setJogador(jogador1);
    pEventos->setJogador(jogador2);

    listaJogadores->adicionar(entJog1);
    listaJogadores->adicionar(entJog2);
}

void Principal::inicializarInimigos()
{
    Morcego* morcego1 = new Morcego(sf::Vector2f(300.0f, 100.0f), sf::Vector2f(25.0f, 50.0f), listaJogadores);
    Golem* golem1 = new Golem(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(80.0f, 100.0f), listaJogadores);
    Esqueleto* esqueleto1 = new Esqueleto(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f), listaJogadores);

    Entidades::Entidades* entMorcego1 = dynamic_cast<Entidades::Entidades*>(morcego1);
    Entidades::Entidades* entGolem1 = dynamic_cast<Entidades::Entidades*>(golem1);
    Entidades::Entidades* entEsqueleto1 = dynamic_cast<Entidades::Entidades*>(esqueleto1);
    
    listaInimigos->adicionar(entMorcego1);
    listaInimigos->adicionar(entGolem1);
    listaInimigos->adicionar(entEsqueleto1);
}

void Principal::inicializarPlataformas()
{
    Obstaculos::Plataforma* plataforma1 = new Obstaculos::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(800.0f, 50.0f));
    Obstaculos::Plataforma* plataforma2 = new Obstaculos::Plataforma(sf::Vector2f(500.0f, 400.0f), sf::Vector2f(150.0f, 50.0f));
    Obstaculos::Plataforma* plataforma3 = new Obstaculos::Plataforma(sf::Vector2f(0.0f, 300.0f), sf::Vector2f(400.0f, 50.0f));
    Obstaculos::Plataforma* plataforma4 = new Obstaculos::Plataforma(sf::Vector2f(500.0f, 100.0f), sf::Vector2f(500.0f, 50.0f));

    Obstaculos::Teia* teia1 = new Obstaculos::Teia(sf::Vector2f(200.0f, 500.0f), sf::Vector2f(50.0f, 50.0f));
    Obstaculos::Teia* teia2 = new Obstaculos::Teia(sf::Vector2f(400.0f, 500.0f), sf::Vector2f(50.0f, 50.0f));

    Obstaculos::Espinho* espinho1 = new Obstaculos::Espinho(sf::Vector2f(300.0f, 500.0f), sf::Vector2f(50.0f, 50.0f));
    Obstaculos::Espinho* espinho2 = new Obstaculos::Espinho(sf::Vector2f(500.0f, 500.0f), sf::Vector2f(50.0f, 50.0f));
   
    Entidades::Entidades* entPlat1 = dynamic_cast<Entidades::Entidades*>(plataforma1);
    Entidades::Entidades* entPlat2 = dynamic_cast<Entidades::Entidades*>(plataforma2);
    Entidades::Entidades* entPlat3 = dynamic_cast<Entidades::Entidades*>(plataforma3);
    Entidades::Entidades* entPlat4 = dynamic_cast<Entidades::Entidades*>(plataforma4);

    Entidades::Entidades* entTeia1 = dynamic_cast<Entidades::Entidades*>(teia1);
    Entidades::Entidades* entTeia2 = dynamic_cast<Entidades::Entidades*>(teia2);

    Entidades::Entidades* entEspinho1 = dynamic_cast<Entidades::Entidades*>(espinho1);
    Entidades::Entidades* entEspinho2 = dynamic_cast<Entidades::Entidades*>(espinho2);

    listaPlataformas->adicionar(entPlat1);
    //listaPlataformas->adicionar(entPlat2);
    listaPlataformas->adicionar(entPlat3);
    listaPlataformas->adicionar(entPlat4);

    listaPlataformas->adicionar(entTeia1);
    listaPlataformas->adicionar(entTeia2);
    
    listaPlataformas->adicionar(entEspinho1);
    listaPlataformas->adicionar(entEspinho2);
}

void Principal::atualizar()
{
    listaInimigos->atualizar(dt);
    listaJogadores->atualizar(dt);
    pColisoes->verificarColisoes();
    
    listaPlataformas->desenhar(pGraf->getJanela()); 
    listaInimigos->desenhar(pGraf->getJanela());
    listaJogadores->desenhar(pGraf->getJanela());  
}

void Principal::executar()
{
    while(pGraf->estaAberta())
    {
        dt = relogio.restart().asSeconds();

        pGraf->limpar();

        pEventos->verificarEventos();
        atualizar();
        
        pGraf->mostrar();
    }
}