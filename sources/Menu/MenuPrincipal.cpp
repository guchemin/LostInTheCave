#include "../../include/Menu/MenuPrincipal.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

namespace Estados
{
    namespace Menu
    {
        MenuPrincipal::MenuPrincipal():
        Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuPrincipal, "LOST IN THE CAVE")
        {
            criarBotoes();
            texturaFundoFaseUm = pGraf->carregarTextura(BACKGROUND_FASE1);
            // texturaFundoFaseDois = pGraf->carregarTextura(BACKGROUND_FASE2);
        }

        MenuPrincipal::~MenuPrincipal()
        {
        }

        void MenuPrincipal::mudarBackground(TipoBotao tipo)
        {
            switch (tipo)
            {
            case TipoBotao::FASE_1:
            {
                background.setTexture(&texturaFundoFaseUm);
                background.setFillColor(sf::Color(255, 255, 255, 255));
                break;
            }

            case TipoBotao::FASE_2:
            {
                // background.setTexture(&texturaFundoFaseDois);
                background.setFillColor(sf::Color(230, 140, 255));
                break;
            }
            
            default:
                break;
            }
        }

        Fases::Fase* MenuPrincipal::carregarFase()
        {
            std::ifstream arquivo("../resources/save.json");
            nlohmann::json save;
            arquivo >> save;

            EstadoID id = save["fase"];
            if(id == EstadoID::FaseUm)
            {
                Fases::FaseUm* fase = new Fases::FaseUm(true);
                fase->setDoisJogadores(save["doisJog"], true);
                return fase;
            }
            else if(id == Estados::EstadoID::FaseDois)
            {
                Fases::FaseDois* fase= new Fases::FaseDois(true);
                fase->setDoisJogadores(save["doisJog"], true);
                return fase;
            }
            else
            {
                return NULL;
            }
        }

        void MenuPrincipal::criarBotoes()
        {
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            float posY = pGraf->getCentro().y - 2 * tamBotoes.y;

            adicionarBotao("JOGAR FASE 1", sf::Vector2f(posX, posY), TipoBotao::FASE_1);
            adicionarBotao("JOGAR FASE 2", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::FASE_2);
            adicionarBotao("CARREGAR", sf::Vector2f(posX, posY + tamBotoes.y * 2.4f), TipoBotao::CARREGAR);
            adicionarBotao("LEADERBOARD", sf::Vector2f(posX, posY + tamBotoes.y * 3.6f), TipoBotao::LEADERBOARD);
            adicionarBotao("SAIR", sf::Vector2f(posX, posY + tamBotoes.y * 4.8f), TipoBotao::SAIR);
            inicializarBotoes();
        }

        void MenuPrincipal::selecionar(TipoBotao tipo)
        {
            switch (tipo)
            {
            case TipoBotao::FASE_1:
            {
                pEstados->adicionar(Estados::EstadoID::MenuJogarUm);
                setAtivo(false);
                break;
            }

            case TipoBotao::FASE_2:
            {
                pEstados->adicionar(Estados::EstadoID::MenuJogarDois);
                setAtivo(false);
                break;
            }

            case TipoBotao::CARREGAR:
            {
                Estados::Estado* estado = static_cast<Estados::Estado*>(carregarFase());
                pEstados->adicionar(estado);
                setAtivo(false);
                break;
            }

            case TipoBotao::LEADERBOARD:
            {
                pEstados->adicionar(Estados::EstadoID::MenuColocacao);
                setAtivo(false);
                break;
            }

            case TipoBotao::SAIR:
            {
                remover = true;
                break;
            }
            
            default:
                break;
            }
        }

        void MenuPrincipal::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                centralizar();
                mudarBackground(getBotaoSelecionado());
                setAtivo(true);
                desenhar();
            }
        }
    }
}