#include "../../include/Menu/MenuPausa.hpp"

namespace Estados
{
    namespace Menu
    {
        MenuPausa::MenuPausa(Fases::Fase *f):
        Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuPausa, "PAUSA"),
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

        MenuPausa::MenuPausa()
        {
        }

        MenuPausa::~MenuPausa()
        {
        }

        void MenuPausa::criarBotoes() 
        {
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            float posY = pGraf->getCentro().y - tamBotoes.y;

            adicionarBotao("CONTINUAR", sf::Vector2f(posX, posY), TipoBotao::CONTINUAR);
            adicionarBotao("SALVAR", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::SALVAR);
            adicionarBotao("VOLTAR AO MENU", sf::Vector2f(posX, posY + tamBotoes.y * 2.4f), TipoBotao::VOLTAR_MENU);
            inicializarBotoes();
        }

        void MenuPausa::setFase(Fases::Fase *f)
        {
            if(f)
            {
                fase = f;
            }
        }

        void MenuPausa::selecionar(TipoBotao tipo)
        {
            if(ativo)
            {
                switch (tipo)
                {
                case TipoBotao::CONTINUAR:
                {   
                    remover = true;
                    break;
                }

                case TipoBotao::SALVAR:
                {
                    fase->salvarJogo();
                    fase->setRemover(true);
                    remover = true;
                    break;
                }

                case TipoBotao::VOLTAR_MENU:
                {
                    remover = true;
                    fase->setRemover(true);
                    break;
                }
                
                default:
                    break;
                }
            }
        }

        void MenuPausa::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                centralizar();
                fase->desenhar();
                pGraf->desenhar(background);
                pGraf->desenhar(painel);
                desenhar();
            }
        }
    }
}