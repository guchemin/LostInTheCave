#pragma once

#include "../Entidades/Personagem/Jogador.hpp"
#include "../Entidades/Personagem/Voador.hpp"
#include "../Entidades/Personagem/Chefao.hpp"
#include "../Entidades/Personagem/Atirador.hpp"
#include "../Gerenciadores/GerenciadorColisoes.hpp"
#include "../Gerenciadores/GerenciadorEventos.hpp"
#include "../Entidades/Obstaculos/Teia.hpp"
#include "../Entidades/Obstaculos/Espinho.hpp"
#include "../Ente.hpp"

namespace Fases
{
    class Fase : public Ente
    {
    private:
        sf::Clock relogio;

    protected:
        float dt;
        Gerenciadores::GerenciadorColisoes* pColisoes;
        Gerenciadores::GerenciadorEventos* pEventos;

        Listas::ListaEntidades* listaJogadores;
        Listas::ListaEntidades* listaInimigos;
        Listas::ListaEntidades* listaObstaculos;

    public:
        Fase();
        virtual ~Fase();

        virtual void inicializar() = 0;
        virtual void inicializarJogadores() = 0;
        virtual void inicializarInimigos() = 0;
        virtual void inicializarObstaculos() = 0;

        virtual void atualizar(float dt) = 0;
        virtual void desenhar() = 0;
        virtual void executar() = 0;
    };
};