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
#include "../Menu/Botao/Texto.hpp"
#include "../Gerenciadores/GerenciadorEstados.hpp"
#include <cmath>
#include <random>

namespace Estados
{
    namespace Fases
    {
        class Fase : public Ente, public Estados::Estado
        {
        protected:
            sf::RectangleShape background;
            sf::Texture texturaFundo;
            sf::Clock relogio;
            float dt;
            bool doisJogadores;
            Gerenciadores::GerenciadorColisoes* pColisoes;
            Gerenciadores::GerenciadorEventos* pEventos;

            Texto pontos;
            Texto vidaJog1;
            Texto vidaJog2;

            const int numAtirador;
            const int numTeia;

            Listas::ListaEntidades* listaJogadores;
            Listas::ListaEntidades* listaInimigos;
            Listas::ListaEntidades* listaObstaculos;
            Listas::ListaEntidades* listaProjeteis;
            Listas::ListaEntidades* listaPlataformas;

        public:
            Fase(Estados::EstadoID id, const int nAtira, const int nTeia);
            Fase();
            virtual ~Fase();

            void inicializar();

            virtual void atualizarTextos() = 0;
            void salvarJogo();
            virtual void criarMapa() = 0;
            virtual void criarAleatorios() = 0;
            void setDoisJogadores(const bool doisJog);
            const bool getDoisJogadores() const;
            virtual void criarEntidade(sf::Vector2f pos, char caracter) = 0;
            void criarJogador(sf::Vector2f pos);
            void criarAtirador(sf::Vector2f pos);
            void criarPlataforma(sf::Vector2f pos, sf::Vector2f tam);
            void criarTeia(sf::Vector2f pos);

            virtual void verificarFimDeJogo() = 0;
            virtual void centralizarCamera() = 0;
            void atualizarBackground();
            virtual void executar(const float dt) = 0;
            virtual void desenhar() = 0;
            virtual void executar() = 0;

            float dist_normal(float media, float desvio);
        };
    }
}