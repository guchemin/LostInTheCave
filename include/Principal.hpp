#pragma once

#include "Entidades/Personagem/Jogador/Jogador.hpp"
#include "Entidades/Personagem/Inimigo/Inimigo.hpp"
#include "Gerenciadores/Colisoes.hpp"

class Principal
{
private:
    Gerenciadores::Graficos* pGraf;
    Gerenciadores::Colisoes* pColisoes; 

    Listas::ListaEntidades* listaPersonagens;
    Listas::ListaEntidades* listaPlataformas;

    Jogador::Jogador* jogador1;
    Jogador::Jogador* jogador2;

    Inimigo::Inimigo* inimigo1;
    Inimigo::Inimigo* inimigo2;
    Inimigo::Inimigo* inimigo3;
    
    Plataforma::Plataforma* plataforma1;
    Plataforma::Plataforma* plataforma2;

    sf::Clock relogio;
    float dt;
    
public:
    Principal();
    ~Principal();

    void inicializar();
    void atualizar();
    void executar();
};