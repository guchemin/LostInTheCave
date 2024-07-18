#include "../include/Principal.hpp"

using namespace Gerenciadores;

Principal::Principal():
pGraf(Graficos::getInstancia())
{
    inicializar();
    
    executar();
}

Principal::~Principal()
{
    pGraf = NULL;
    pColisoes = NULL;
    jogador1 = NULL;
    jogador2 = NULL;
    plataforma1 = NULL;
    listaPersonagens = NULL;
    listaPlataformas = NULL;
}

void Principal::inicializar()
{
    pGraf->getJanela()->setFramerateLimit(60);

    jogador1 = new Jogador::Jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), Jogador::ID::JOGADOR1);
    jogador2 = new Jogador::Jogador(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f), Jogador::ID::JOGADOR2);

    inimigo1 = new Inimigo::Inimigo(sf::Vector2f(300.0f, 300.0f), sf::Vector2f(25.0f, 50.0f), Inimigo::ID::INIM1);
    inimigo2 = new Inimigo::Inimigo(sf::Vector2f(400.0f, 400.0f), sf::Vector2f(30.0f, 100.0f), Inimigo::ID::INIM2);
    inimigo3 = new Inimigo::Inimigo(sf::Vector2f(200.0f, 500.0f), sf::Vector2f(50.0f, 50.0f), Inimigo::ID::INIM3);
    
    plataforma1 = new Plataforma::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(800.0f, 50.0f));
    plataforma2 = new Plataforma::Plataforma(sf::Vector2f(100.0f, 200.0f), sf::Vector2f(300.0f, 200.0f));
    
    listaPersonagens = new Listas::ListaEntidades();
    listaPlataformas = new Listas::ListaEntidades();

    listaPersonagens->adicionar(jogador1);
    listaPersonagens->adicionar(jogador2);

    listaPersonagens->adicionar(inimigo1);
    listaPersonagens->adicionar(inimigo2);
    listaPersonagens->adicionar(inimigo3);
    
    listaPlataformas->adicionar(plataforma1);
    listaPlataformas->adicionar(plataforma2);

    Entidades::Entidades* entJog1 = static_cast<Entidades::Entidades*>(jogador1);
    Entidades::Entidades* entJog2 = static_cast<Entidades::Entidades*>(jogador2);

    Entidades::Entidades* entInim1 = static_cast<Entidades::Entidades*>(inimigo1);
    Entidades::Entidades* entInim2 = static_cast<Entidades::Entidades*>(inimigo2);
    Entidades::Entidades* entInim3 = static_cast<Entidades::Entidades*>(inimigo3);

    Entidades::Entidades* entPlat1 = static_cast<Entidades::Entidades*>(plataforma1);
    Entidades::Entidades* entPlat2 = static_cast<Entidades::Entidades*>(plataforma2);

    pColisoes = new Gerenciadores::Colisoes(listaPersonagens, listaPlataformas);

}

void Principal::atualizar() 
{


    jogador1->mover(dt);
    jogador2->mover(dt); 

    inimigo1->mover(dt);
    inimigo2->mover(dt);
    inimigo3->mover(dt);

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