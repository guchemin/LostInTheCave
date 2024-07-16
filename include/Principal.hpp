#pragma once

#include "Entidades/Jogador/Jogador.hpp"
#include "Entidades/Plataforma/Plataforma.hpp"
#include "Gerenciadores/Colisoes.hpp"


class Principal
{
private:
    Gerenciadores::Graficos* pGraf;
    Gerenciadores::Colisoes* pColisoes; 

    Listas::ListaEntidades* listaJogadores;
    Listas::ListaEntidades* listaPlataformas;

    Jogador::Jogador* jogador1;
    Jogador::Jogador* jogador2;
    Plataforma::Plataforma* plataforma1;

    sf::Clock relogio;
    float dt;
    
public:
    Principal();
    ~Principal();

    void inicializar();
    void atualizar();
    void executar();
};