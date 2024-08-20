#include "../include/Principal.hpp"

using namespace Gerenciadores;

Principal::Principal():
pGraf(GerenciadorGrafico::getInstancia()),
pEventos(GerenciadorEventos::getInstancia())
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
    listaObstaculos->limpar();
}

void Principal::inicializar()
{
    listaJogadores = new Listas::ListaEntidades();
    listaInimigos = new Listas::ListaEntidades();
    listaObstaculos = new Listas::ListaEntidades();
    pColisoes = new Gerenciadores::GerenciadorColisoes(listaJogadores, listaInimigos, listaObstaculos);
    
    inicializarJogadores();
    inicializarInimigos();
    inicializarObstaculos();   
}

void Principal::inicializarJogadores()
{
    Jogador* jogador1 = new Jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), ID::JOGADOR1);
    Jogador* jogador2 = new Jogador(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f), ID::JOGADOR2);

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
    Golem* golem1 = new Golem(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(50.0f, 70.0f), listaJogadores);
    Esqueleto* esqueleto1 = new Esqueleto(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 80.0f), listaJogadores);

    Entidades::Entidades* entMorcego1 = dynamic_cast<Entidades::Entidades*>(morcego1);
    Entidades::Entidades* entGolem1 = dynamic_cast<Entidades::Entidades*>(golem1);
    Entidades::Entidades* entEsqueleto1 = dynamic_cast<Entidades::Entidades*>(esqueleto1);
    
    listaInimigos->adicionar(entMorcego1);
    listaInimigos->adicionar(entGolem1);
    listaInimigos->adicionar(entEsqueleto1);
}

void Principal::inicializarObstaculos()
{
    Obstaculos::Plataforma* plataforma1 = new Obstaculos::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(800.0f, 50.0f));
    Obstaculos::Plataforma* plataforma2 = new Obstaculos::Plataforma(sf::Vector2f(500.0f, 400.0f), sf::Vector2f(150.0f, 50.0f));
    Obstaculos::Plataforma* plataforma3 = new Obstaculos::Plataforma(sf::Vector2f(0.0f, 300.0f), sf::Vector2f(2000.0f, 50.0f));
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

    listaObstaculos->adicionar(entPlat1);
    listaObstaculos->adicionar(entPlat2);
    listaObstaculos->adicionar(entPlat3);
    listaObstaculos->adicionar(entPlat4);

    listaObstaculos->adicionar(entTeia1);
    listaObstaculos->adicionar(entTeia2);
    
    listaObstaculos->adicionar(entEspinho1);
    listaObstaculos->adicionar(entEspinho2);
}

void Principal::centralizarCamera()
{
    int tam = listaJogadores->getTam();
    float media;
    float soma = 0.0f;
    for(int i = 0; i < tam; i++)
    {
        soma += (*listaJogadores)[i]->getCentro().x;
    }
    media = soma/tam;
    pGraf->centralizarCamera(sf::Vector2f(media, 300.0f));
}

void Principal::atualizar()
{
    listaInimigos->atualizar(dt);
    listaJogadores->atualizar(dt);
    pColisoes->verificarColisoes();
    
    centralizarCamera();
    
    listaObstaculos->desenhar(); 
    listaInimigos->desenhar();
    listaJogadores->desenhar();
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
    //Fases::FaseUm fase;
}