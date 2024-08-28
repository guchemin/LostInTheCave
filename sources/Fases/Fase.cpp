#include "../../include/Fases/Fase.hpp"

namespace Estados
{
    namespace Fases
    {
        Fase::Fase(Estados::EstadoID id, const int nAtira, const int nTeia):
        numTeia(nTeia),
        numAtirador(nAtira),
        Ente(),
        Estado(id),
        pEventos(Gerenciadores::GerenciadorEventos::getInstancia())
        {
        }

        Fase::Fase():
        numTeia(0),
        numAtirador(0)
        {
        }

        Fase::~Fase()
        {
        }

        void Fase::inicializar()
        {
            listaJogadores = new Listas::ListaEntidades();
            listaInimigos = new Listas::ListaEntidades();
            listaPlataformas = new Listas::ListaEntidades();
            listaObstaculos = new Listas::ListaEntidades();
            listaProjeteis = new Listas::ListaEntidades();
            pColisoes = new Gerenciadores::GerenciadorColisoes(listaJogadores, listaInimigos, listaPlataformas, listaObstaculos, listaProjeteis);
            
            criarMapa();
        }

        void Fase::setDoisJogadores(const bool doisJog)
        {
            doisJogadores = doisJog;
            inicializar();
        }

        void Fase::atualizarBackground()
        {
            background.setPosition(pGraf->getCentro().x - pGraf->getTamanho().x / 2, pGraf->getCentro().y - pGraf->getTamanho().y / 2);
        }

        void Fase::criarJogador(sf::Vector2f pos)
        {
            if(listaJogadores->getTam() == 0)
            {
                Entidades::Personagem::Jogador* jogador = new Entidades::Personagem::Jogador(pos, Entidades::Personagem::ID::JOGADOR1);
                Entidades::Entidade* entJog = static_cast<Entidades::Entidade*>(jogador);
                listaJogadores->adicionar(entJog);
            }
            else if(listaJogadores->getTam() && doisJogadores)
            {
                Entidades::Personagem::Jogador* jogador = new Entidades::Personagem::Jogador(pos, Entidades::Personagem::ID::JOGADOR2);
                Entidades::Entidade* entJog = static_cast<Entidades::Entidade*>(jogador);
                listaJogadores->adicionar(entJog);
            }
        }

        void Fase::criarAtirador(sf::Vector2f pos)
        {
            Entidades::Personagem::Atirador* atirador = new Entidades::Personagem::Atirador(pos);
            Entidades::Projetil* projetil = new Entidades::Projetil(sf::Vector2f(-1000.0f, -1000.0f), sf::Vector2f(0.0f, 0.0f));
            atirador->setProjetil(projetil);

            Entidades::Entidade* entAtirador = static_cast<Entidades::Entidade*>(atirador);
            Entidades::Entidade* entProjetil = static_cast<Entidades::Entidade*>(projetil);

            listaInimigos->adicionar(entAtirador);
            listaProjeteis->adicionar(entProjetil);
        }

        void Fase::criarChefao(sf::Vector2f pos)
        {
            Entidades::Personagem::Chefao* chefao = new Entidades::Personagem::Chefao(pos);
            Entidades::Entidade* entChefao = static_cast<Entidades::Entidade*>(chefao);
            listaInimigos->adicionar(entChefao);
        }

        void Fase::criarPlataforma(sf::Vector2f pos, sf::Vector2f tam)
        {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(pos, tam);
            Entidades::Entidade* entPlataforma = static_cast<Entidades::Entidade*>(plataforma);
            listaPlataformas->adicionar(entPlataforma);
        }

        void Fase::criarTeia(sf::Vector2f pos)
        {
            Entidades::Obstaculos::Teia* teia = new Entidades::Obstaculos::Teia(pos);
            Entidades::Entidade* entTeia = static_cast<Entidades::Entidade*>(teia);
            listaObstaculos->adicionar(entTeia);
        }

        void Fase::criarPedra(sf::Vector2f pos)
        {
            Entidades::Obstaculos::Pedra* pedra = new Entidades::Obstaculos::Pedra(pos);
            Entidades::Entidade* entPedra = static_cast<Entidades::Entidade*>(pedra);
            listaObstaculos->adicionar(entPedra);
        }

        // metodo Box-Muller para transformar numeros aleatorios em uma distribuição normal
        float Fase::dist_normal(float media, float desvio) // feito com ajuda do ChatGPT para a parte de gerar números aleatórios
        {
            static random_device rd;
            static mt19937 gen(rd());
            uniform_real_distribution<> dist(0.0, 1.0);

            float u1 = dist(gen);
            float u2 = dist(gen);
            float z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
            float z1 = sqrt(-2.0 * log(u1)) * sin(2.0 * M_PI * u2);
            
            return z0 * desvio + media;
        }
    }
}