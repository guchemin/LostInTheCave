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