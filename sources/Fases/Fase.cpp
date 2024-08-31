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
            pEventos(Gerenciadores::GerenciadorEventos::getInstancia()),
            pontos(),
            vidaJog1(),
            vidaJog2()
        {
        }

        Fase::Fase(Estados::EstadoID id, bool carregar):
            numTeia(0),
            numAtirador(0),
            Ente(),
            Estado(id),
            pEventos(Gerenciadores::GerenciadorEventos::getInstancia()),
            pontos(),
            vidaJog1(),
            vidaJog2()
        {
            listaJogadores = new Listas::ListaEntidades();
            listaInimigos = new Listas::ListaEntidades();
            listaPlataformas = new Listas::ListaEntidades();
            listaObstaculos = new Listas::ListaEntidades();
            listaProjeteis = new Listas::ListaEntidades();
            pColisoes = new Gerenciadores::GerenciadorColisoes(listaJogadores, listaInimigos, listaPlataformas, listaObstaculos, listaProjeteis);

            carregarMapa();
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

        void Fase::salvarJogo() // salva as condições da fase e chama a salvarJogo de cada entidade
        {
            nlohmann::json j;
            j["fase"] = Estados::Estado::getEstadoID();
            j["doisJog"] = doisJogadores;
            Listas::ListaEntidades::IteradorEntidades itInim = listaInimigos->inicio();
            Listas::ListaEntidades::IteradorEntidades itJog = listaJogadores->inicio();
            Listas::ListaEntidades::IteradorEntidades itPlat = listaPlataformas->inicio();
            Listas::ListaEntidades::IteradorEntidades itObst = listaObstaculos->inicio();
            Listas::ListaEntidades::IteradorEntidades itProj = listaProjeteis->inicio();

            for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
            {
                if(*itInim)
                    j["inimigos"].push_back((*itInim)->salvarJogo());
            }

            for(itJog = listaJogadores->inicio(); itJog != listaJogadores->fim(); ++itJog)
            {
                if(*itJog)
                    j["jogadores"].push_back((*itJog)->salvarJogo());
            }

            for(itPlat = listaPlataformas->inicio(); itPlat != listaPlataformas->fim(); ++itPlat)
            {
                if(*itPlat)
                    j["plataformas"].push_back((*itPlat)->salvarJogo());
            }

            for(itObst = listaObstaculos->inicio(); itObst != listaObstaculos->fim(); ++itObst)
            {
                if(*itObst)
                    j["obstaculos"].push_back((*itObst)->salvarJogo());
            }

            for(itProj = listaProjeteis->inicio(); itProj != listaProjeteis->fim(); ++itProj)
            {
                if(*itProj)
                    j["projeteis"].push_back((*itProj)->salvarJogo());
            }

            std::ofstream file("../resources/save.json");
            file << j.dump(4);
            file.close();
        }

        void Fase::carregarMapa() // carrega as entidades do arquivo de save e seta as entidades que precisam de outras
        {
            std::ifstream arquivo("../resources/save.json");
            nlohmann::json save;
            arquivo >> save;

            for(auto& inimigo : save["inimigos"])
            {
                Entidades::Entidade* ent = carregarInimigo(inimigo);
                listaInimigos->adicionar(ent);
            }
            for(auto& jogador : save["jogadores"])
            {
                Entidades::Entidade* ent = carregarJogador(jogador);
                listaJogadores->adicionar(ent);
            }
            for(auto& obstaculo : save["obstaculos"])
            {
                Entidades::Entidade* ent = carregarObstaculo(obstaculo);
                listaObstaculos->adicionar(ent);
            }
            for(auto& plataforma : save["plataformas"])
            {
                Entidades::Entidade* ent = carregarPlataforma(plataforma);
                listaPlataformas->adicionar(ent);
            }
            for(auto& projetil : save["projeteis"])
            {
                Entidades::Entidade* ent = carregarProjetil(projetil);
                listaProjeteis->adicionar(ent);
            }

            Listas::ListaEntidades::IteradorEntidades itInim = listaInimigos->inicio();
            Listas::ListaEntidades::IteradorEntidades itProj = listaProjeteis->inicio();

            for(itInim = listaInimigos->inicio(); itInim != listaInimigos->fim(); ++itInim)
            {
                if(*itInim)
                {
                    if((*itInim)->getTipo() == Entidades::TIPO::ATIRADOR && (*itProj))
                    {
                        Entidades::Personagem::Atirador* atirador = static_cast<Entidades::Personagem::Atirador*>(*itInim);
                        Entidades::Projetil* projetil = static_cast<Entidades::Projetil*>(*itProj);
                        atirador->setProjetil(projetil);
                        ++itProj;
                    }
                }
            }
        }
        
        void Fase::setDoisJogadores(const bool doisJog, const bool carregando)
        {
            doisJogadores = doisJog;
            if(!carregando) //se estiver carregando, a construtora inicializa e o salvamento cria as entidades
                inicializar(); //so inicializa quando sabemos o numero de jogadores
        }

        const bool Fase::getDoisJogadores() const 
        {
            return doisJogadores;
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

        Entidades::Entidade* Fase::carregarInimigo(nlohmann::json &j)
        {
            if(j["tipo"] == Entidades::TIPO::ATIRADOR)
            {
                return carregarAtirador(j);
            }
            else if(j["tipo"] == Entidades::TIPO::CHEFAO)
            {
                return carregarChefao(j);
            }
            else if(j["tipo"] == Entidades::TIPO::VOADOR)
            {
                return carregarVoador(j);
            }
            return NULL;
        }

        Entidades::Entidade* Fase::carregarJogador(nlohmann::json & j)
        {
            Entidades::Personagem::Jogador* jogador = new Entidades::Personagem::Jogador(sf::Vector2f(j["pos"][0], j["pos"][1]), j["id"]);
            jogador->setDirecao(j["direcao"]);
            jogador->setNaTeia(j["estaNaTeia"]);
            jogador->setEspinhado(j["foiEspinhado"]);
            Entidades::Personagem::Jogador::setPontuacao(j["pontuacao"]);
            jogador->setPulou(j["pulou"]);
            jogador->setVelocidade(sf::Vector2f(j["vel"][0], j["vel"][1]));
            jogador->setVida(j["vida"]);

            Entidades::Entidade* entJog = static_cast<Entidades::Entidade*>(jogador);

            return entJog;
        }

        Entidades::Entidade* Fase::carregarObstaculo(nlohmann::json &j)
        {
            if(j["tipo"] == Entidades::TIPO::PEDRA)
            {
                return carregarPedra(j);
            }
            else if(j["tipo"] == Entidades::TIPO::ESPINHO)
            {
                return carregarEspinho(j);
            }
            else if(j["tipo"] == Entidades::TIPO::TEIA)
            {
                return carregarTeia(j);
            }
            return NULL;
        }

        Entidades::Entidade *Fase::carregarPlataforma(nlohmann::json &j)
        {
            Entidades::Obstaculos::Plataforma* plataforma = new Entidades::Obstaculos::Plataforma(sf::Vector2f(j["pos"][0], j["pos"][1]), sf::Vector2f(j["tamanho"][0], j["tamanho"][1]));
            plataforma->setDanoso(j["danoso"]);
            plataforma->setFalsa(j["ehFalsa"]);
            plataforma->setVelY(j["velY"]);

            Entidades::Entidade* entPlataforma = static_cast<Entidades::Entidade*>(plataforma);
            
            return entPlataforma;
        }

        Entidades::Entidade *Fase::carregarProjetil(nlohmann::json &j)
        {
            Entidades::Projetil* projetil = new Entidades::Projetil(sf::Vector2f(j["pos"][0], j["pos"][1]), sf::Vector2f(j["vel"][0], j["vel"][1]));

            Entidades::Entidade* entProjetil = static_cast<Entidades::Entidade*>(projetil);
            
            return entProjetil;
        }

        Entidades::Entidade *Fase::carregarPedra(nlohmann::json &j)
        {
            Entidades::Obstaculos::Pedra* pedra = new Entidades::Obstaculos::Pedra(sf::Vector2f(j["pos"][0], j["pos"][1]));
            pedra->setDanoso(j["danoso"]);
            pedra->setVelY(j["velY"]);
            pedra->setDx(j["dx"]);
            pedra->setPeso(j["peso"]);

            Entidades::Entidade* entPedra = static_cast<Entidades::Entidade*>(pedra);

            return entPedra;
        }

        Entidades::Entidade *Fase::carregarEspinho(nlohmann::json &j)
        {
            Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(sf::Vector2f(j["pos"][0], j["pos"][1]));
            espinho->setDanoso(j["danoso"]);
            espinho->setVelY(j["velY"]);
            espinho->setAfiado(j["afiado"]);

            Entidades::Entidade* entEspinho = static_cast<Entidades::Entidade*>(espinho);

            return entEspinho;
        }

        Entidades::Entidade * Fase::carregarTeia(nlohmann::json & j)
        {
            Entidades::Obstaculos::Teia* teia = new Entidades::Obstaculos::Teia(sf::Vector2f(j["pos"][0], j["pos"][1]));
            teia->setVelY(j["velY"]);
            teia->setDanoso(j["danoso"]);
            teia->setDensidade(j["densidade"]);

            Entidades::Entidade* entTeia = static_cast<Entidades::Entidade*>(teia);

            return entTeia;
        }

        Entidades::Entidade *Fase::carregarAtirador(nlohmann::json &j)
        {
            Entidades::Personagem::Atirador* atirador = new Entidades::Personagem::Atirador(sf::Vector2f(j["pos"][0], j["pos"][1]));
            atirador->setDirecao(j["direcao"]);
            atirador->setPosInicial(sf::Vector2f(j["posInicial"][0], j["posInicial"][1]));
            atirador->setVelocidade(sf::Vector2f(j["vel"][0], j["vel"][1]));
            atirador->setVida(j["vida"]);

            Entidades::Entidade* entAtirador = static_cast<Entidades::Entidade*>(atirador);

            return entAtirador;
        }

        Entidades::Entidade *Fase::carregarChefao(nlohmann::json &j)
        {
            Entidades::Personagem::Chefao* chefao = new Entidades::Personagem::Chefao(sf::Vector2f(j["pos"][0], j["pos"][1]));
            chefao->setDirecao(j["direcao"]);
            chefao->setPosInicial(sf::Vector2f(j["posInicial"][0], j["posInicial"][1]));
            chefao->setVelocidade(sf::Vector2f(j["vel"][0], j["vel"][1]));
            chefao->setVida(j["vida"]);
            chefao->setPerseguindo(j["estaPerseguindo"]);

            Entidades::Entidade* entChefao = static_cast<Entidades::Entidade*>(chefao);

            return entChefao;
        }

        Entidades::Entidade *Fase::carregarVoador(nlohmann::json &j)
        {
            
            Entidades::Personagem::Voador* voador = new Entidades::Personagem::Voador(sf::Vector2f(j["pos"][0], j["pos"][1]));
            voador->setDirecao(j["direcao"]);
            voador->setPosInicial(sf::Vector2f(j["posInicial"][0], j["posInicial"][1]));
            voador->setVelocidade(sf::Vector2f(j["vel"][0], j["vel"][1]));
            voador->setVida(j["vida"]);
            voador->setEndiabrado(j["endiabrado"]);

            Entidades::Entidade* entVoador = static_cast<Entidades::Entidade*>(voador);

            return entVoador;
        }

        void Fase::atualizarBackground()
        {
            background.setPosition(pGraf->getCentro().x - pGraf->getTamanho().x / 2, pGraf->getCentro().y - pGraf->getTamanho().y / 2);
        }
        
        // metodo Box-Muller para transformar numeros aleatorios em uma distribuição normal
        const float Fase::dist_normal(float media, float desvio) // feito com ajuda do ChatGPT para a parte de gerar números aleatórios
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