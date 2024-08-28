#include "../../include/Menu/MenuSalvarPontuacao.hpp"
#include "../../include/Gerenciadores/GerenciadorArquivos.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

using namespace Menu;

MenuSalvarPontuacao::MenuSalvarPontuacao(Fases::Fase* f):
fase(f),
gArquivo(),
nomeTexto(),
nomeString(),
Menu(sf::Vector2f(800, 600), Estados::EstadoID::MenuSalvarPontuacao, "Salvar Pontuacao")
{
    nomeString = "";
    cout << "string vazia: " << nomeString.empty() << endl;
    alinharTexto();
    criarBotoes();
    fonte.loadFromFile("../assets/fonts/fonteJogo.ttf");
}

MenuSalvarPontuacao::MenuSalvarPontuacao():
fase(nullptr), gArquivo(), Menu(sf::Vector2f(800, 600), Estados::EstadoID::MenuSalvarPontuacao, "Salvar Pontuacao")
{
    alinharTexto();
    criarBotoes();
}

MenuSalvarPontuacao::~MenuSalvarPontuacao()
{
}

void MenuSalvarPontuacao::alinharTexto() 
{
    // Configura o texto para o nome do jogador
    nomeTexto.setTamanhoFonte(30);
    nomeTexto.setPos(sf::Vector2f(400.0f, 200.0f)); // Posição para entrada do nome
    nomeTexto.setCor(sf::Color::White);
}

void MenuSalvarPontuacao::criarBotoes()
{
    adicionarBotao("SALVAR", sf::Vector2f(400, 500), TipoBotao::CONFIRMAR);
    adicionarBotao("SAIR", sf::Vector2f(400, 550), TipoBotao::SAIR);
}

void MenuSalvarPontuacao::adicionarCaracter(std::string c)
{
    if (!this) {
        std::cerr << "Erro: o ponteiro 'this' é inválido!" << std::endl;
        return;
    }

    nomeString.append(c);
    cout << "Nome: " << nomeString << endl;
}

void MenuSalvarPontuacao::removerCaracter()
{
    // if (!textoNome.empty())
    // {
    //     textoNome.pop_back();
    //     nomeJogador.setString(textoNome); // Atualiza o texto exibido na tela
    // }
}

void MenuSalvarPontuacao::salvarColocacao()
{
    std::ofstream arquivo("leaderboard.txt", std::ios::app);
    if (arquivo.is_open())
    {
        arquivo << nomeString << " - " << Jogador::getPontuacao() << std::endl;
        arquivo.close();
    }
}

void MenuSalvarPontuacao::selecionar(TipoBotao tipo)
{
    switch (tipo)
    {
    case TipoBotao::CONFIRMAR:
        salvarColocacao();
        // Aqui você pode adicionar lógica para mudar o estado ou voltar ao menu principal
        break;
    case TipoBotao::SAIR:
        // Lógica para cancelar a operação e retornar ao menu anterior
        break;
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
        fase->desenhar();
        pGraf->desenhar(background);
        // pGraf->desenhar(painel);
        titulo.desenhar();
        desenhar();
    }
}


