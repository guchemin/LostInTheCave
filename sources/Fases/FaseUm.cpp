#include "../../include/Fases/FaseUm.hpp"

namespace Estados
{
    namespace Fases
    {
        FaseUm::FaseUm():
        Fase(Estados::EstadoID::FaseUm, (int)(rand() % (MAX_ATIRADOR + 1)), (int)(rand() % (MAX_TEIA + 1))),
        numEspinho((int)(rand() % (MAX_ESPINHO + 1))),
        numVoador((int)(rand() % (MAX_VOADOR + 1)))
        {
            remover = false;
            background.setSize(pGraf->getTamanho());
            if(!texturaFundo.loadFromFile(BACKGROUND_FASE1))
            {
                throw std::runtime_error("Erro ao carregar a textura de fundo!");
            }
            background.setTexture(&texturaFundo);
            background.setScale(1.1f, 1.1f);
            background.setOrigin(20, 0);
        }

        FaseUm::~FaseUm()
        {
            Entidades::Personagem::Jogador::somaPontos(-(Entidades::Personagem::Jogador::getPontuacao()));
        }

        void FaseUm::criarMapa() 
        {
            try 
            {
                std::ifstream arquivo("../resources/Fases/FaseUm.txt");
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

        void FaseUm::criarAleatorios()
        {
            float mediaX = TAMANHO_MAPA_X / 2.0f;
            float desvioX = 3000.0f;
            float posX = -1.0f;

            float mediaY = pGraf->getTamanho().y / 2.0f;
            float desvioY = 20.0f;
            float posY = -1.0f;

            for(int i = 0; i < numEspinho; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_X - 50.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 50.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarEspinho(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }

            for(int i = 0; i < numTeia; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_X - 50.0f)
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
                while(posX < 500.0f || posX > TAMANHO_MAPA_X - 50.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 50.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarAtirador(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }

            for(int i = 0; i < numVoador; i++)
            {
                while(posX < 500.0f || posX > TAMANHO_MAPA_X - 50.0f)
                {
                    posX = dist_normal(mediaX, desvioX);
                }
                while(posY < 500.0f || posY > pGraf->getTamanho().y - 50.0f)
                {
                    posY = dist_normal(mediaY, desvioY);
                }
                criarVoador(sf::Vector2f(posX, posY));
                
                posX = -1.0f;
                posY = -1.0f;
            }
        }

        void FaseUm::criarEntidade(sf::Vector2f pos, char caracter)
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

            case 'v':
            {
                criarVoador(pos);
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

            case 'e':
            {
                criarEspinho(pos);
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

        void FaseUm::criarVoador(sf::Vector2f pos)
        {
            Entidades::Personagem::Voador* voador = new Entidades::Personagem::Voador(pos);
            Entidades::Entidade* entVoador = static_cast<Entidades::Entidade*>(voador);
            listaInimigos->adicionar(entVoador);
        }

        void FaseUm::criarEspinho(sf::Vector2f pos)
        {
            Entidades::Obstaculos::Espinho* espinho = new Entidades::Obstaculos::Espinho(pos);
            Entidades::Entidade* entEspinho = static_cast<Entidades::Entidade*>(espinho);
            listaObstaculos->adicionar(entEspinho);
        }

        void FaseUm::verificarFimDeJogo()
        {
            if(listaJogadores->getTam() == 0)
            {
                // salvar pontuacao
            }
            else
            {
                if(listaJogadores->getTam() == 1)
                {
                    if((*listaJogadores)[0]->getPosicao().x >= TAMANHO_MAPA_X) // substituir por TAMANHO_MAPA_X
                    {
                        pEstados->adicionar(Estados::EstadoID::MenuFim);
                        remover = true;
                    }
                }
                else if(listaJogadores->getTam() == 2)
                {
                    if((*listaJogadores)[0]->getCentro().x >= TAMANHO_MAPA_X && (*listaJogadores)[1]->getCentro().x >= TAMANHO_MAPA_X)
                    {
                        pEstados->adicionar(Estados::EstadoID::MenuFim);
                        remover = true;
                    }
                }
            }
        }

        void FaseUm::centralizarCamera() 
        {
            int tam = listaJogadores->getTam();
            float media;
            float diferenca;
            float soma = 0.0f;

            if(tam == 0)
            {
                // implementar GAME OVER
            }
            else if(tam == 1)
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
                    if((*listaJogadores)[0]->getPosicao().x >= TAMANHO_MAPA_X)
                        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[1]->getCentro().x, 450.0f));
                    else
                        pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
                }
                else if(diferenca < -750.0f)
                {
                    if((*listaJogadores)[1]->getPosicao().x >= TAMANHO_MAPA_X)
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
            else if(pGraf->getCentro().x + pGraf->getTamanho().x / 2.0f >= TAMANHO_MAPA_X)
            {
                pGraf->centralizarCamera(sf::Vector2f(TAMANHO_MAPA_X - pGraf->getTamanho().x / 2.0f, 450.0f));
            }
        }

        void FaseUm::executar(const float dt) 
        {
            atualizarBackground();
            listaInimigos->executar(dt);
            listaJogadores->executar(dt);
            listaObstaculos->executar(dt);
            listaProjeteis->executar(dt);
            listaPlataformas->executar(dt);
            pColisoes->verificarColisoes();

            centralizarCamera();
        }

        void FaseUm::desenhar()
        {
            pGraf->desenhar(background);
            listaPlataformas->desenhar();
            listaProjeteis->desenhar();
            listaInimigos->desenhar();
            listaJogadores->desenhar();
            listaObstaculos->desenhar();
        }

        void FaseUm::executar()
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
            }
        }
    }
}