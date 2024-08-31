#include "../../include/Menu/MenuJogar.hpp"
#include "../../include/Gerenciadores/GerenciadorEstados.hpp"

namespace Estados
{
    namespace Menu
    {
        MenuJogar::MenuJogar(Estados::EstadoID faseID):
            Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), faseID, "LOST IN THE CAVE"),
            jog1(sf::Vector2f(100.0f, 140.0f)),
            jog2(sf::Vector2f(100.0f, 140.0f)),
            textJog1(pGraf->carregarTextura(CAMINHO_TEXT_JOG1)),
            textJog2(pGraf->carregarTextura(CAMINHO_TEXT_JOG2))
        {
            criarBotoes();
            if(faseID == Estados::EstadoID::MenuJogarUm)
            {
                cenario = pGraf->carregarTextura(BACKGROUND_FASE1);
            }
            else if(faseID == Estados::EstadoID::MenuJogarDois)
            {
                cenario = pGraf->carregarTextura(BACKGROUND_FASE1);
                background.setFillColor(sf::Color(230, 140, 255));
            }
            background.setTexture(&cenario);
            ativo = true;
            jog1.setTexture(&textJog1);
            jog2.setTexture(&textJog2);
            jog1.setScale(1.2f, 1.0f);
            jog2.setScale(1.2f, 1.0f);
        }

        MenuJogar::MenuJogar()
        {
        }

        MenuJogar::~MenuJogar()
        {
        }

        void MenuJogar::desenharJogadores()
        {
            if(getBotaoSelecionado() == TipoBotao::UM_JOGADOR)
            {
                jog1.setPosition(sf::Vector2f(pGraf->getCentro().x - jog1.getSize().x / 2.0f, 200.0f));
                pGraf->desenhar(jog1);
            }
            else if(getBotaoSelecionado() == TipoBotao::DOIS_JOGADORES)
            {
                jog1.setPosition(sf::Vector2f(pGraf->getCentro().x - jog1.getSize().x , 200.0f));
                jog2.setPosition(sf::Vector2f(pGraf->getCentro().x, 200.0f));
                pGraf->desenhar(jog1);
                pGraf->desenhar(jog2);
            }
        }

        void MenuJogar::criarBotoes() 
        {
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            float posY = pGraf->getCentro().y - tamBotoes.y;

            adicionarBotao("1 JOGADOR", sf::Vector2f(posX, posY), TipoBotao::UM_JOGADOR);
            adicionarBotao("2 JOGADORES", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::DOIS_JOGADORES);
            adicionarBotao("VOLTAR", sf::Vector2f(posX, posY + tamBotoes.y * 2.4f), TipoBotao::VOLTAR);
            inicializarBotoes();
        }

        void MenuJogar::selecionar(TipoBotao tipo)
        {
            if(ativo)
            {
                switch (tipo)
                {
                case TipoBotao::UM_JOGADOR:
                {
                    if(getEstadoID() == Estados::EstadoID::MenuJogarUm)
                    {
                        adicionar(Estados::EstadoID::FaseUm);
                    }
                    else if(getEstadoID() == Estados::EstadoID::MenuJogarDois)
                    {
                        adicionar(Estados::EstadoID::FaseDois);
                    }
                    setAtivo(false);
                    Estados::Fases::Fase* f = static_cast<Estados::Fases::Fase*>(pEstados->getEstadoAtual());
                    if(f)
                    {
                        f->setDoisJogadores(false, false);
                    }
                    remover = true;
                    break;
                }

                case TipoBotao::DOIS_JOGADORES:
                {
                    if(getEstadoID() == Estados::EstadoID::MenuJogarUm)
                    {
                        adicionar(Estados::EstadoID::FaseUm);
                    }
                    else if (getEstadoID() == Estados::EstadoID::MenuJogarDois)
                    {
                        adicionar(Estados::EstadoID::FaseDois);
                    }
                    setAtivo(false);
                    Estado* est = pEstados->getEstadoAtual();
                    Estados::Fases::Fase* f = static_cast<Estados::Fases::Fase*>(est);
                    if(f)
                    {
                        f->setDoisJogadores(true, false);
                    }
                    est = NULL;
                    remover = true;
                    break;
                }

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

        void MenuJogar::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                centralizar();
                setAtivo(true);
                desenhar();
                desenharJogadores();
            }
        }
    }
}