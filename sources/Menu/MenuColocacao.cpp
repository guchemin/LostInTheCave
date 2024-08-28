#include "../../include/Menu/MenuColocacao.hpp"

namespace Estados
{
    namespace Menu
    {
        MenuColocacao::MenuColocacao():
        Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuColocacao, "LEADERBOARD"),
        colocacoes(),
        gArquivo(),
        leaderboard()
        {
            texturaFundo = pGraf->carregarTextura("../assets/sprites/Backgrounds/Background1.png");
            background.setTexture(&texturaFundo);
            ativo = true;
            criarBotoes();
            criarColocacao();
        }

        MenuColocacao::~MenuColocacao()
        {
            for(std::vector<Texto*>::iterator it = colocacoes.begin(); it != colocacoes.end(); ++it)
            {
                if (*it != NULL)
                {
                    delete *it; 
                    *it = NULL;
                }
            }
        }

        void MenuColocacao::centralizarTexto()
        {
            for (std::vector<Texto*>::iterator it = colocacoes.begin(); it != colocacoes.end(); ++it)
            {
                (*it)->setPos(sf::Vector2f(pGraf->getCentro().x - (*it)->getTamanho().x / 2.0f, (*it)->getPos().y));
            }
        }

        void MenuColocacao::criarBotoes() 
        {
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            float posY = pGraf->getCentro().y - tamBotoes.y;

            adicionarBotao("VOLTAR", sf::Vector2f(posX, posY + tamBotoes.y * 4.0f), TipoBotao::VOLTAR);
            inicializarBotoes();
        }

        void MenuColocacao::criarTexto(const std::string& nome, int pontos)
        {
            const int larguraMaxima = 50;
            std::string pontosStr = std::to_string(pontos);

            while(pontosStr.length() < 5)
            {
                pontosStr = "0" + pontosStr;
            }

            std::string novaLinha = nome;

            int espacosRestantes = larguraMaxima - (nome.length() + pontosStr.length());

            if(espacosRestantes > 0)
            {
                novaLinha += std::string(espacosRestantes, '.');
            }

            novaLinha += pontosStr;
            
            Texto* texto = new Texto();
            texto->setInfo(novaLinha);
            const int qtdVector = colocacoes.size();
            const float tam = texto->getTamanho().x;
            texto->setPos(sf::Vector2f(pGraf->getTamanho().x / 2.0f - tam / 2.0f, 225.0f + 50.0f * qtdVector));
            colocacoes.push_back(texto);
        }

        void MenuColocacao::criarColocacao()
        {
            std::vector<std::string> linhas = gArquivo.lerArquivo(CAMINHO_ARQUIVO_COLOCACAO);

            for (std::vector<std::string>::iterator it = linhas.begin(); it != linhas.end(); ++it)
            {
                std::string nome;
                int pontos = 0;
                std::istringstream iss(*it);
                iss >> nome >> pontos;
                leaderboard.push_back({nome, pontos});
            }

            std::sort(leaderboard.begin(), leaderboard.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) //esse sort foi feito com a ajuda do chatGPT
            {
                return a.second > b.second;
            }); 

            for (std::size_t i = 0; i < leaderboard.size() && i < 10; ++i)
            {
                criarTexto(leaderboard[i].first, leaderboard[i].second);
            }
        }


        void MenuColocacao::desenharColocacao()
        {
            for (std::vector<Texto*>::iterator it = colocacoes.begin(); it != colocacoes.end(); ++it)
            {
                (*it)->desenhar();
            }
        }

        void MenuColocacao::selecionar(TipoBotao tipo)
        {
            if(ativo)
            {
                switch (tipo)
                {
                case TipoBotao::VOLTAR:
                {
                    remover = true;
                    break;
                }

                default:
                    break;
                }
            }
        }

        void MenuColocacao::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                centralizar();
                centralizarTexto();
                setAtivo(true);
                desenhar();
                desenharColocacao();
            }
        }
    }
}