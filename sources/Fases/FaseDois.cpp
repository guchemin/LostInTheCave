#include "../../include/Fases/FaseDois.hpp"

namespace Estados
{
    namespace Fases
    {
        FaseDois::FaseDois(bool carregar):
        Fase(Estados::EstadoID::FaseDois, carregar),
        numPedra(0),
        numChefao(0)
        {
            remover = false;
            background.setSize(pGraf->getTamanho());
            if(!texturaFundo.loadFromFile(BACKGROUND_FASE2))
            {
                throw std::runtime_error("Erro ao carregar a textura de fundo!");
            }
            background.setTexture(&texturaFundo);
            background.setFillColor(sf::Color(230, 140, 255));
            background.setScale(1.1f, 1.1f);
            background.setOrigin(20, 0);

            pontos = string("PONTOS TOTAIS: " + to_string((int)Entidades::Personagem::Jogador::getPontuacao()));
            pontos.setTamanhoFonte(32);
            pontos.setCor(sf::Color::White);
            pontos.setPos(sf::Vector2f(pGraf->getCentro().x + pGraf->getTamanho().x / 2.0f - (pontos.getTamanho().x + 20.0f), 50.0f));  
        }

        FaseDois::FaseDois():
        Fase(Estados::EstadoID::FaseDois, (int)(rand() % (MAX_ATIRADOR + 1)), (int)(rand() % (MAX_TEIA + 1))),
        numPedra((int)(rand() % (MAX_PEDRA + 1))),
        numChefao((int)(rand() % (MAX_CHEFAO + 1)))
        {
            remover = false;
            background.setSize(pGraf->getTamanho());
            if(!texturaFundo.loadFromFile(BACKGROUND_FASE2))
            {
                throw std::runtime_error("Erro ao carregar a textura de fundo!");
            }
            background.setTexture(&texturaFundo);
            background.setFillColor(sf::Color(230, 140, 255));
            background.setScale(1.1f, 1.1f);
            background.setOrigin(20, 0);

            pontos = string("PONTOS TOTAIS: " + to_string((int)Entidades::Personagem::Jogador::getPontuacao()));
            pontos.setTamanhoFonte(32);
            pontos.setCor(sf::Color::White);
            pontos.setPos(sf::Vector2f(pGraf->getCentro().x + pGraf->getTamanho().x / 2.0f - (pontos.getTamanho().x + 20.0f), 50.0f));  
        }


        FaseDois::~FaseDois()
        {
            Entidades::Personagem::Jogador::somaPontos(-(Entidades::Personagem::Jogador::getPontuacao()));
        }

        void FaseDois::criarMapa()
        {
            try 
            {
                std::ifstream arquivo("../resources/Fases/FaseDois.txt");
                if (!arquivo.is_open()) 
                {
                    throw std::runtime_error("Erro ao abrir o arquivo de mapa!");
                }

                std::string linha;
                int y = 0;

                while (getline(arquivo, linha)) 
                {
                    for (int x = 0; x < linha.size(); x++) 
                    {
                        sf::Vector2f pos(x * 50, y * 50);
                        criarEntidade(pos, linha[x]);
                    }
                    y++;
                }

                arquivo.close(); // Fechar o arquivo após o uso

            } 
            catch (const std::ifstream::failure& e) 
            {
                std::cerr << "Exceção ao operar no arquivo: " << e.what() << std::endl;
            } 
            catch (const std::runtime_error& e) 
            {
                std::cerr << e.what() << std::endl;
            } 
            catch (const std::exception& e) 
            {
                std::cerr << "Erro inesperado: " << e.what() << std::endl;
            }
            criarAleatorios();
        }

        void FaseDois::criarAleatorios()
        {
            float mediaX = TAMANHO_MAPA_2 / 2.0f;
            float desvioX = 3000.0f;
            float posX = -1.0f;

            float mediaY = pGraf->getTamanho().y / 2.0f;
            float desvioY = 20.0f;
            float posY = -1.0f;

            for(int i = 0; i < numPedra; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_2 - 50.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 50.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarPedra(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }

            for(int i = 0; i < numTeia; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_2 - 50.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 50.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarTeia(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }

            for(int i = 0; i < numAtirador; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_2 - 10.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 100.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarAtirador(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }

            for(int i = 0; i < numChefao; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_2 - 100.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 150.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarChefao(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }
        }

        void FaseDois::criarEntidade(sf::Vector2f pos, char caracter)
        {
            switch (caracter)
            {
            case 'j':
            {
                criarJogador(pos);
                break;
            }
            
            case 'a':
            {
                criarAtirador(pos);
                break;
            }

            case 'c':
            {
                criarChefao(pos);
                break;
            }

            case '#':
            {
                criarPlataforma(pos, sf::Vector2f(50.0f, 50.0f));
                break;
            }

            case '-':
            {
                criarPlataforma(pos, sf::Vector2f(100.0f, 50.0f));
                break;
            }

            case 't':
            {
                criarTeia(pos);
                break;
            }

            case 'r':
            {
                criarPedra(pos);
                break;
            }
            
            default:
                break;
            }
        }

        void FaseDois::criarPedra(sf::Vector2f pos)
        {
            Entidades::Obstaculos::Pedra* pedra = new Entidades::Obstaculos::Pedra(pos);
            Entidades::Entidade* entPedra = static_cast<Entidades::Entidade*>(pedra);
            listaObstaculos->adicionar(entPedra);
        }

        void FaseDois::criarChefao(sf::Vector2f pos)
        {
            Entidades::Personagem::Chefao* chefao = new Entidades::Personagem::Chefao(pos);
            Entidades::Entidade* entChefao = static_cast<Entidades::Entidade*>(chefao);
            listaInimigos->adicionar(entChefao);
        }

        void FaseDois::atualizarTextos()
        {
            if(listaJogadores->getTam() == 1)
            {
                Entidades::Personagem::Jogador* jogador = static_cast<Entidades::Personagem::Jogador*>((*listaJogadores)[0]);
                if(jogador->getId() == Entidades::Personagem::ID::JOGADOR1)
                {
                    vidaJog1 = string("VIDA JOGADOR 1: " + to_string((int)jogador->getVida()) + "/100");
                    vidaJog1.setPos(sf::Vector2f(pGraf->getCentro().x - pGraf->getTamanho().x / 2.0f + 20.0f, 50.0f));
                    vidaJog2 = string("");
                }
                else
                {
                    vidaJog2 = string("VIDA JOGADOR 2: " + to_string((int)jogador->getVida()) + "/100");
                    vidaJog2.setPos(sf::Vector2f(pGraf->getCentro().x - pGraf->getTamanho().x / 2.0f + 20.0f, 90.0f));
                    vidaJog1 = string("");
                }
                pontos = string("PONTOS TOTAIS: " + to_string((int)Entidades::Personagem::Jogador::getPontuacao()));
                pontos.setPos(sf::Vector2f(pGraf->getCentro().x + pGraf->getTamanho().x / 2.0f - (pontos.getTamanho().x + 20.0f), 50.0f));
            }
            else if(listaJogadores->getTam() == 2)
            {
                Entidades::Personagem::Jogador* jogador1 = static_cast<Entidades::Personagem::Jogador*>((*listaJogadores)[0]);
                Entidades::Personagem::Jogador* jogador2 = static_cast<Entidades::Personagem::Jogador*>((*listaJogadores)[1]);
                vidaJog1 = string("VIDA JOGADOR 1: " + to_string((int)jogador1->getVida()) + "/100");
                vidaJog1.setPos(sf::Vector2f(pGraf->getCentro().x - pGraf->getTamanho().x / 2.0f + 20.0f, 50.0f));
                vidaJog2 = string("VIDA JOGADOR 2: " + to_string((int)jogador2->getVida()) + "/100");
                vidaJog2.setPos(sf::Vector2f(pGraf->getCentro().x - pGraf->getTamanho().x / 2.0f + 20.0f, 90.0f));
                pontos = string("PONTOS TOTAIS: " + to_string((int)Entidades::Personagem::Jogador::getPontuacao()));
                pontos.setPos(sf::Vector2f(pGraf->getCentro().x + pGraf->getTamanho().x / 2.0f - (pontos.getTamanho().x + 20.0f), 50.0f));
            }
        }

        void FaseDois::verificarFimDeJogo()
        {
            if(listaJogadores->getTam() == 0)
            {
                pEstados->adicionar(Estados::EstadoID::MenuSalvarPontuacao);
                remover = true;
            }
            else
            {
                if(listaJogadores->getTam() == 1)
                {
                    if((*listaJogadores)[0]->getPosicao().y < 0.0f)
                    {
                        pEstados->adicionar(Estados::EstadoID::MenuSalvarPontuacao);
                        remover = true;
                    }
                }
                else if(listaJogadores->getTam() == 2)
                {
                    if((*listaJogadores)[0]->getCentro().y < 0.0f && (*listaJogadores)[1]->getCentro().y < 0.0f)
                    {
                        pEstados->adicionar(Estados::EstadoID::MenuSalvarPontuacao);
                        remover = true;
                    }
                }
            }
        }

        void FaseDois::centralizarCamera()
        {
            int tam = listaJogadores->getTam();
            float media;
            float diferenca;
            float soma = 0.0f;

            if(tam == 1)
            {
                pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
            }
            else if(tam == 2)
            {
                diferenca = (*listaJogadores)[0]->getCentro().x - (*listaJogadores)[1]->getCentro().x;
                soma = (*listaJogadores)[0]->getCentro().x + (*listaJogadores)[1]->getCentro().x;

                media = soma/tam;

                if(diferenca > 750.0f)
                {
                    if((*listaJogadores)[0]->getPosicao().x >= TAMANHO_MAPA_2)
                        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[1]->getCentro().x, 450.0f));
                    else
                        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
                }
                else if(diferenca < -750.0f)
                {
                    if((*listaJogadores)[1]->getPosicao().x >= TAMANHO_MAPA_2)
                        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
                    else
                        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[1]->getCentro().x, 450.0f));
                }
                else
                {
                    pGraf->centralizarCamera(sf::Vector2f(media, 450.0f));
                }
            }

            if(pGraf->getCentro().x - pGraf->getTamanho().x / 2.0f <= 0.0f)
            {
                pGraf->centralizarCamera(sf::Vector2f(pGraf->getTamanho().x / 2.0f, 450.0f));
            }
            else if(pGraf->getCentro().x + pGraf->getTamanho().x / 2.0f >= TAMANHO_MAPA_2)
            {
                pGraf->centralizarCamera(sf::Vector2f(TAMANHO_MAPA_2 - pGraf->getTamanho().x / 2.0f, 450.0f));
            }
        }

        void FaseDois::executar(const float dt)
        {
            atualizarBackground();
            atualizarTextos();
            listaInimigos->executar(dt);
            listaJogadores->executar(dt);
            listaObstaculos->executar(dt);
            listaProjeteis->executar(dt);
            listaPlataformas->executar(dt);
            pColisoes->verificarColisoes();

            centralizarCamera();
        }

        void FaseDois::desenhar()
        {
            pGraf->desenhar(background);
            listaPlataformas->desenhar();
            listaProjeteis->desenhar();
            listaInimigos->desenhar();
            listaJogadores->desenhar();
            listaObstaculos->desenhar();
        }

        void FaseDois::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                verificarFimDeJogo();
                dt = relogio.restart().asSeconds();
                if(dt > 1.0f / 60.0f)
                {
                    dt = 1.0f / 60.0f;
                }
                executar(dt);
                desenhar();
                pontos.desenhar();
                vidaJog1.desenhar();
                vidaJog2.desenhar();
            }
        }
    }
}
