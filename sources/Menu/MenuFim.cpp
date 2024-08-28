#include "../../include/Menu/MenuFim.hpp"

namespace Estados
{
    namespace Menu
    {
        MenuFim::MenuFim(Fases::Fase *f):
        Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuFim, "FIM DE JOGO :)"),
        fase(f)
        {
            background.setSize(pGraf->getTamanho());
            background.setFillColor(sf::Color(0, 0, 0, 80));
            painel.setSize(sf::Vector2f(pGraf->getTamanho().x / 2.0f, pGraf->getTamanho().y));
            painel.setPosition(pGraf->getCentro().x - painel.getSize().x / 2.0f, 0.0f);
            painel.setFillColor(sf::Color(0, 0, 0, 200));

            criarBotoes();
            ativo = true;
        }

        MenuFim::MenuFim()
        {
        }

        MenuFim::~MenuFim()
        {
        }

        void MenuFim::criarBotoes()
        {
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            float posY = pGraf->getCentro().y - tamBotoes.y;

            adicionarBotao("JOGAR FASE 2", sf::Vector2f(posX, posY), TipoBotao::JOGAR_FASE2);
            adicionarBotao("SALVAR PONTUACAO", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::SALVAR_PONTUACAO);
            adicionarBotao("VOLTAR AO MENU", sf::Vector2f(posX, posY + tamBotoes.y * 2.4f), TipoBotao::VOLTAR_MENU);
            inicializarBotoes();
        }

        void MenuFim::setFase(Fases::Fase *f)
        {
            if(f)
            {
                fase = f;
            }
        }

        Fases::Fase *MenuFim::getFase()
        {
            if(fase)
            {
                return fase;
            }
            else
            {
                cout << "Fase nao encontrada" << endl;
                return NULL;
            }
        }

        void MenuFim::selecionar(TipoBotao tipo)
        {
            if(ativo)
            {
                switch(tipo)
                {
                    case TipoBotao::JOGAR_FASE2:
                    {    
                        pEstados->adicionar(Estados::EstadoID::FaseDois);
                        remover = true;
                        setAtivo(false);
                        Estado* est = pEstados->getEstadoAtual();
                        est->setDoisJogadores(true);
                        est = NULL;
                        break;
                    }

                    case TipoBotao::SALVAR_PONTUACAO:
                    {   
                        pEstados->adicionar(Estados::EstadoID::MenuSalvarPontuacao);
                        setAtivo(false);
                        remover = true;
                        break;
                    }

                    case TipoBotao::VOLTAR_MENU:
                    {
                        remover = true;
                        setAtivo(false);
                        break;
                    }
                    default:
                        break;
                }
            }
        }

        void MenuFim::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                if(fase)
                    fase->desenhar();
                centralizar();
                pGraf->desenhar(background);
                setAtivo(true);
                pGraf->desenhar(painel);
                titulo.desenhar();
                desenhar();
            }
        }
    }
}