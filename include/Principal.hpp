#pragma once

#include "Entidades/Personagem/Jogador.hpp"
#include "Entidades/Personagem/Morcego.hpp"
#include "Entidades/Personagem/Golem.hpp"
#include "Entidades/Personagem/Esqueleto.hpp"
#include "Gerenciadores/GerenciadorColisoes.hpp"
#include "Gerenciadores/GerenciadorEventos.hpp"
#include "Entidades/Obstaculos/Teia.hpp"
#include "Entidades/Obstaculos/Espinho.hpp"
// #include "Fases/FaseUm.hpp"

class Principal
{
private:
    Gerenciadores::GerenciadorGrafico* pGraf;
    Gerenciadores::GerenciadorColisoes* pColisoes;
    Gerenciadores::GerenciadorEventos* pEventos;

    Listas::ListaEntidades* listaJogadores;
    Listas::ListaEntidades* listaInimigos;
    Listas::ListaEntidades* listaObstaculos;

    sf::Clock relogio;
    float dt;
    
public:
    Principal();
    ~Principal();

    void inicializar();
    void inicializarJogadores();
    void inicializarInimigos();
    void inicializarObstaculos();

    void centralizarCamera();

    void atualizar();
    void executar();
};