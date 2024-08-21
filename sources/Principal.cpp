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
    listaProjeteis->limpar();
}

void Principal::inicializar()
{
    listaJogadores = new Listas::ListaEntidades();
    listaInimigos = new Listas::ListaEntidades();
    listaObstaculos = new Listas::ListaEntidades();
    listaProjeteis = new Listas::ListaEntidades();
    pColisoes = new Gerenciadores::GerenciadorColisoes(listaJogadores, listaInimigos, listaObstaculos, listaProjeteis);
    
    inicializarJogadores();
    inicializarInimigos();
    inicializarObstaculos();   
}

void Principal::inicializarJogadores()
{
    Jogador* jogador1 = new Jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), ID::JOGADOR1);
    Jogador* jogador2 = new Jogador(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f), ID::JOGADOR2);

    Entidades::Entidades* entJog1 = static_cast<Entidades::Entidades*>(jogador1);
    Entidades::Entidades* entJog2 = static_cast<Entidades::Entidades*>(jogador2);

    pEventos->setJogador(jogador1);
    pEventos->setJogador(jogador2);

    listaJogadores->adicionar(entJog1);
    listaJogadores->adicionar(entJog2);
}

void Principal::inicializarInimigos()
{
    Voador* Voador1 = new Voador(sf::Vector2f(300.0f, 100.0f), sf::Vector2f(25.0f, 50.0f));
    Voador1->setJogador(static_cast<Jogador*>((*listaJogadores)[0]));

    Chefao* Chefao1 = new Chefao(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(50.0f, 70.0f));
    Chefao1->setJogador(static_cast<Jogador*>((*listaJogadores)[0]));

    Atirador* Atirador1 = new Atirador(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 80.0f));
    Projetil* projetil1 = new Projetil(sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(10.0f, 10.0f), sf::Vector2f(0.0f, 0.0f)); 
    Atirador1->setJogador(static_cast<Jogador*>((*listaJogadores)[0]));
    Atirador1->setProjetil(projetil1);

    Entidades::Entidades* entVoador1 = static_cast<Entidades::Entidades*>(Voador1);
    Entidades::Entidades* entChefao1 = static_cast<Entidades::Entidades*>(Chefao1);
    Entidades::Entidades* entAtirador1 = static_cast<Entidades::Entidades*>(Atirador1);
    Entidades::Entidades* entProjetil1 = static_cast<Entidades::Entidades*>(projetil1);

    listaInimigos->adicionar(entVoador1);
    listaInimigos->adicionar(entChefao1);
    listaInimigos->adicionar(entAtirador1);

    listaProjeteis->adicionar(entProjetil1);
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
   
    Entidades::Entidades* entPlat1 = static_cast<Entidades::Entidades*>(plataforma1);
    Entidades::Entidades* entPlat2 = static_cast<Entidades::Entidades*>(plataforma2);
    Entidades::Entidades* entPlat3 = static_cast<Entidades::Entidades*>(plataforma3);
    Entidades::Entidades* entPlat4 = static_cast<Entidades::Entidades*>(plataforma4);

    Entidades::Entidades* entTeia1 = static_cast<Entidades::Entidades*>(teia1);
    Entidades::Entidades* entTeia2 = static_cast<Entidades::Entidades*>(teia2);

    Entidades::Entidades* entEspinho1 = static_cast<Entidades::Entidades*>(espinho1);
    Entidades::Entidades* entEspinho2 = static_cast<Entidades::Entidades*>(espinho2);

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
    float diferenca;
    float soma = 0.0f;

    if(tam == 0)
    {
        // implementar GAME OVER
    }
    else if(tam == 1)
    {
        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 300.0f));
    }
    else if(tam == 2)
    {
        diferenca = (*listaJogadores)[0]->getCentro().x - (*listaJogadores)[1]->getCentro().x;
        soma = (*listaJogadores)[0]->getCentro().x + (*listaJogadores)[1]->getCentro().x;

        media = soma/tam;

        if(diferenca > 750.0f)
        {
            pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 300.0f));
        }
        else if(diferenca < -750.0f)
        {
            pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[1]->getCentro().x, 300.0f));
        }
        else
        {
            pGraf->centralizarCamera(sf::Vector2f(media, 300.0f));
        }
    }
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