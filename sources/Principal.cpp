#include "../include/Principal.hpp"

using namespace Gerenciadores;

Principal::Principal():
pGraf(Graficos::getInstancia())
{
    pGraf->getJanela()->setFramerateLimit(60);
    inicializar();
    executar();
}

Principal::~Principal()
{
    pGraf = NULL;
    pColisoes = NULL;
    listaPersonagens->limpar();
    listaPlataformas->limpar();
}

void Principal::inicializar()
{
    listaPersonagens = new Listas::ListaEntidades();
    listaPlataformas = new Listas::ListaEntidades();
    pColisoes = new Gerenciadores::Colisoes(listaPersonagens, listaPlataformas);
    
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

    listaPersonagens->adicionar(jogador1);
    listaPersonagens->adicionar(jogador2);
}

void Principal::inicializarInimigos()
{
    Morcego* morcego1 = new Morcego(sf::Vector2f(300.0f, 100.0f), sf::Vector2f(25.0f, 50.0f));
    Golem* golem1 = new Golem(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(30.0f, 100.0f));
    // Inimigo::Inimigo* inimigo3 = new Inimigo::Inimigo(sf::Vector2f(200.0f, 500.0f), sf::Vector2f(50.0f, 50.0f), Inimigo::ID::INIM3);

    Entidades::Entidades* entInim1 = dynamic_cast<Entidades::Entidades*>(morcego1);
    Entidades::Entidades* entInim2 = dynamic_cast<Entidades::Entidades*>(golem1);
    // Entidades::Entidades* entInim3 = dynamic_cast<Entidades::Entidades*>(inimigo3);
    
    listaPersonagens->adicionar(morcego1);
    listaPersonagens->adicionar(golem1);
    // listaPersonagens->adicionar(inimigo3);

    golem1->setpJogador(dynamic_cast<Jogador::Jogador*>(listaPersonagens->getLista()[0]));
}

void Principal::inicializarPlataformas()
{
    Plataforma::Plataforma* plataforma1 = new Plataforma::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(800.0f, 50.0f));
    Plataforma::Plataforma* plataforma2 = new Plataforma::Plataforma(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(300.0f, 200.0f));
   
    Entidades::Entidades* entPlat1 = dynamic_cast<Entidades::Entidades*>(plataforma1);
    Entidades::Entidades* entPlat2 = dynamic_cast<Entidades::Entidades*>(plataforma2);

    listaPlataformas->adicionar(plataforma1);
    listaPlataformas->adicionar(plataforma2);
}

void Principal::atualizar()
{
    listaPersonagens->mover(dt);

    pColisoes->verificarColisoes();
    
    listaPersonagens->desenhar(pGraf->getJanela());
    listaPlataformas->desenhar(pGraf->getJanela());
}

void Principal::executar()
{
    while(pGraf->estaAberta())
    {
        dt = relogio.restart().asSeconds();

        //verifica e fecha se necessário
        pGraf->verificaSeFechou();
        
        pGraf->limpar();
        atualizar();
        pGraf->mostrar();
    }
}