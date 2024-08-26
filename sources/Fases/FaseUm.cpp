#include "../../include/Fases/FaseUm.hpp"

Fases::FaseUm::FaseUm():
Fase(Estados::EstadoID::FaseUm)
{
    background.setSize(pGraf->getTamanho());
    if(!texturaFundo.loadFromFile(BACKGROUNG_FASE1))
    {
        throw std::runtime_error("Erro ao carregar a textura de fundo!");
    }
    background.setTexture(&texturaFundo);
    background.setScale(1.1f, 1.1f);
    background.setOrigin(20, 0);
}

Fases::FaseUm::~FaseUm()
{
}

void Fases::FaseUm::criarMapa() 
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
}

void Fases::FaseUm::centralizarCamera()
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
            pGraf->centralizarCamera(sf::Vector2f((*listaJogadores)[0]->getCentro().x, 450.0f));
        }
        else if(diferenca < -750.0f)
        {
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

void Fases::FaseUm::atualizar(const float dt) 
{
    atualizarBackground();
    listaInimigos->atualizar(dt);
    listaJogadores->atualizar(dt);
    listaObstaculos->atualizar(dt);
    listaProjeteis->atualizar(dt);
    listaPlataformas->atualizar(dt);
    pColisoes->verificarColisoes();

    centralizarCamera();
}

void Fases::FaseUm::desenhar()
{
    pGraf->desenhar(background);
    listaPlataformas->desenhar();
    listaProjeteis->desenhar();
    listaInimigos->desenhar();
    listaJogadores->desenhar();
    listaObstaculos->desenhar();
}

void Fases::FaseUm::executar()
{

    dt = relogio.restart().asSeconds();
    if(dt > 1.0f / 60.0f)
    {
        dt = 1.0f / 60.0f;
    }
    
    atualizar(dt);
    desenhar();
}