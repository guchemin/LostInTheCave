#include "../../include/Menu/MenuSalvarPontuacao.hpp"
#include "../../include/Gerenciadores/GerenciadorArquivos.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

namespace Estados
{
    namespace Menu
    {
        MenuSalvarPontuacao::MenuSalvarPontuacao(Fases::Fase* f):
            Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuSalvarPontuacao, "Salvar Pontuacao"),
            fase(f),
            gArquivo(),
            nomeTexto(),
            nomeString(),
            pontuacaoTexto()
        {
            background.setSize(pGraf->getTamanho());
            background.setFillColor(sf::Color(0, 0, 0, 80));
            painel.setSize(sf::Vector2f(pGraf->getTamanho().x / 1.4f, pGraf->getTamanho().y));
            painel.setPosition(pGraf->getCentro().x - painel.getSize().x / 2.0f, 0.0f);
            painel.setFillColor(sf::Color(0, 0, 0, 200));

            nomeString = "";

            pontuacaoTexto = string("PONTUACAO: " + std::to_string((int)(Entidades::Personagem::Jogador::getPontuacao())));
            pontuacaoTexto.setTamanhoFonte(64);
            pontuacaoTexto.setCor(sf::Color::White);
            pontuacaoTexto.setPos(sf::Vector2f(pGraf->getCentro().x - pontuacaoTexto.getTamanho().x / 2.0f, 250));
            
            nomeTexto = string("DIGITE SEU NOME: ");
            nomeTexto.setTamanhoFonte(48);
            nomeTexto.setCor(sf::Color::White);
            nomeTexto.setPos(sf::Vector2f(pGraf->getCentro().x - nomeTexto.getTamanho().x / 2.0f, pGraf->getCentro().y - nomeTexto.getTamanho().y));

            alinharTexto();
            criarBotoes();
            ativo = true;
        }

        MenuSalvarPontuacao::MenuSalvarPontuacao()
        {
        }

        MenuSalvarPontuacao::~MenuSalvarPontuacao()
        {
        }

        void MenuSalvarPontuacao::alinharTexto() 
        {
            nomeTexto.setPos(sf::Vector2f(pGraf->getCentro().x - nomeTexto.getTamanho().x / 2.0f, pGraf->getCentro().y - nomeTexto.getTamanho().y)); 
        }

        void MenuSalvarPontuacao::criarBotoes()
        {
            float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
            float posY = pGraf->getCentro().y + tamBotoes.y / 2.0f;

            adicionarBotao("SALVAR", sf::Vector2f(posX, posY), TipoBotao::CONFIRMAR);
            adicionarBotao("SAIR", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::SAIR);
            
            inicializarBotoes();
        }

        void MenuSalvarPontuacao::adicionarCaracter(std::string c)
        {
            if(nomeString.size() >= 10)
            {
                return;
            }

            if (!this) 
            {
                std::cerr << "Erro: o ponteiro 'this' é inválido!" << std::endl;
                return;
            }

            nomeString.append(c);

            std::string aux = nomeTexto.getInfo();
            nomeTexto = string(aux + c);
            alinharTexto();
        }

        void MenuSalvarPontuacao::removerCaracter()
        {
            if (!nomeString.empty())
            {
                nomeString.pop_back();

                std::string aux = nomeTexto.getInfo();
                aux.pop_back();
                nomeTexto = string(aux);
                alinharTexto();
            }
        }

        void MenuSalvarPontuacao::salvarColocacao()
        {
            std::string conteudo = nomeString + " " + std::to_string((int)Entidades::Personagem::Jogador::getPontuacao());
            gArquivo.gravarCont("../resources/leaderboard.txt", conteudo);
        }

        void MenuSalvarPontuacao::selecionar(TipoBotao tipo)
        {
            switch (tipo)
            {
            case TipoBotao::CONFIRMAR:
            {    
                salvarColocacao();
                remover = true;
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

        void MenuSalvarPontuacao::executar()
        {
            if(remover)
            {
                pEstados->remover();
            }
            else
            {
                centralizar();
                setAtivo(true);
                fase->desenhar();
                pGraf->desenhar(background);
                pGraf->desenhar(painel);
                desenhar();
                nomeTexto.desenhar();
                pontuacaoTexto.desenhar();
            }
        }
    }
}