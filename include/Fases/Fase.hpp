#pragma once

#include "../Entidades/Personagem/Jogador.hpp"
#include "../Entidades/Personagem/Voador.hpp"
#include "../Entidades/Personagem/Chefao.hpp"
#include "../Entidades/Personagem/Atirador.hpp"
#include "../Gerenciadores/GerenciadorColisoes.hpp"
#include "../Gerenciadores/GerenciadorEventos.hpp"
#include "../Entidades/Obstaculos/Teia.hpp"
#include "../Entidades/Obstaculos/Espinho.hpp"
#include "../Entidades/Obstaculos/Plataforma.hpp"
#include "../Ente.hpp"

namespace Fases
{
    class Fase : public Ente
    {
    protected:
        sf::Clock relogio;
        float dt;
        Gerenciadores::GerenciadorColisoes* pColisoes;
        Gerenciadores::GerenciadorEventos* pEventos;

        Listas::ListaEntidades* listaJogadores;
        Listas::ListaEntidades* listaInimigos;
        Listas::ListaEntidades* listaObstaculos;
        Listas::ListaEntidades* listaProjeteis;

    public:
        Fase();
        virtual ~Fase();

        void inicializar();

        virtual void criarMapa() = 0;
        void criarEntidade(sf::Vector2f pos, char caracter);
        void criarJogador(sf::Vector2f pos);
        void criarAtirador(sf::Vector2f pos);
        void criarVoador(sf::Vector2f pos);
        void criarChefao(sf::Vector2f pos);
        void criarPlataforma(sf::Vector2f pos);
        void criarTeia(sf::Vector2f pos);
        void criarEspinho(sf::Vector2f pos);

        void centralizarCamera();
        virtual void atualizar(float dt) = 0;
        virtual void desenhar() = 0;
        virtual void executar() = 0;
    };
};