#pragma once

#include "Entidades/Personagem/Jogador/Jogador.hpp"
#include "Entidades/Personagem/Inimigo/Morcego.hpp"
#include "Entidades/Personagem/Inimigo/Golem.hpp"
#include "Gerenciadores/Colisoes.hpp"

class Principal
{
private:
    Gerenciadores::Graficos* pGraf;
    Gerenciadores::Colisoes* pColisoes; 

    Listas::ListaEntidades* listaPersonagens;
    Listas::ListaEntidades* listaPlataformas;

    sf::Clock relogio;
    float dt;
    
public:
    Principal();
    ~Principal();

    void inicializar();
    void inicializarJogadores();
    void inicializarInimigos();
    void inicializarPlataformas();

    void atualizar();
    void executar();
};