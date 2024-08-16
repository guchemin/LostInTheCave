#pragma once

#include "Entidades/Personagem/Jogador/Jogador.hpp"
#include "Entidades/Personagem/Inimigo/Morcego.hpp"
#include "Entidades/Personagem/Inimigo/Golem.hpp"
#include "Entidades/Personagem/Inimigo/Esqueleto/Esqueleto.hpp"
#include "Gerenciadores/Colisoes.hpp"
#include "Gerenciadores/Eventos.hpp"
#include "Entidades/Obstaculos/Teia.hpp"

class Principal
{
private:
    Gerenciadores::Graficos* pGraf;
    Gerenciadores::Colisoes* pColisoes;
    Gerenciadores::Eventos* pEventos;

    Listas::ListaEntidades* listaJogadores;
    Listas::ListaEntidades* listaInimigos;
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