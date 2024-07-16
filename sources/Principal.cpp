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
    listaJogadores = NULL;
    listaPlataformas = NULL;
}

void Principal::inicializar()
{
    pGraf->getJanela()->setFramerateLimit(60);

    jogador1 = new Jogador::Jogador(sf::Vector2f(50.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), Jogador::ID::JOGADOR1);
    jogador2 = new Jogador::Jogador(sf::Vector2f(150.0f, 150.0f), sf::Vector2f(50.0f, 50.0f), Jogador::ID::JOGADOR2);
    plataforma1 = new Plataforma::Plataforma(sf::Vector2f(0.0f, 550.0f), sf::Vector2f(800.0f, 50.0f));
    listaJogadores = new Listas::ListaEntidades();
    listaPlataformas = new Listas::ListaEntidades();

    listaJogadores->adicionar(jogador1);
    listaJogadores->adicionar(jogador2);
    listaPlataformas->adicionar(plataforma1);

 

    Entidades::Entidades* entJog1 = static_cast<Entidades::Entidades*>(jogador1);
    Entidades::Entidades* entJog2 = static_cast<Entidades::Entidades*>(jogador2);
    Entidades::Entidades* entPlat1 = static_cast<Entidades::Entidades*>(plataforma1);

    pColisoes = new Gerenciadores::Colisoes(listaJogadores, listaPlataformas);

}

void Principal::atualizar() 
{
    jogador1->mover(dt);
    jogador2->mover(dt); 

    pColisoes->verificarColisoes();
    
    listaJogadores->desenhar(pGraf->getJanela());
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