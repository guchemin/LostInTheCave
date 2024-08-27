#include "../../include/Menu/MenuSalvarPontuacao.hpp"

Menu::MenuSalvarPontuacao::MenuSalvarPontuacao(Fases::Fase *f):
Menu(sf::Vector2f(TAMANHO_BOTAO_X, TAMANHO_BOTAO_Y), Estados::EstadoID::MenuSalvarPontuacao, "SALVAR PONTUACAO"),
txt(),
pontuacao(),
fase(f),
gArquivo()
{  
    string pontos = to_string(Jogador::getPontuacao());

    while(pontos.size() < 6)
    {
        pontos = "0" + pontos;
    }

    pontuacao.setTamanhoFonte(24);
    pontuacao.setCor(sf::Color::White);
    pontuacao.setInfo("PONTUACAO: " + pontos);
    cout << "-------------" << pontuacao.getInfo() << endl;
    pontuacao.setPos(sf::Vector2f(pGraf->getCentro().x - pontuacao.getTamanho().x / 2.0f, pGraf->getCentro().y - pontuacao.getTamanho().y * 2.0f));
    txt.setTamanhoFonte(24);
    txt.setCor(sf::Color::White);
    txt.setInfo("DIGITE SEU NOME: ");
    cout << "-------------" << txt.getInfo() << endl;
    txt.setPos(sf::Vector2f(pGraf->getCentro().x - txt.getTamanho().x / 2.0f, pGraf->getCentro().y - txt.getTamanho().y));

    background.setSize(pGraf->getTamanho());
    background.setFillColor(sf::Color(0, 0, 0, 80));
    painel.setSize(sf::Vector2f(pGraf->getTamanho().x / 2.0f, pGraf->getTamanho().y));
    painel.setPosition(pGraf->getCentro().x - painel.getSize().x / 2.0f, 0.0f);
    painel.setFillColor(sf::Color(0, 0, 0, 200));

    criarBotoes();
    ativo = true;
}

Menu::MenuSalvarPontuacao::MenuSalvarPontuacao()
{
}

Menu::MenuSalvarPontuacao::~MenuSalvarPontuacao()
{
}

void Menu::MenuSalvarPontuacao::alinharTexto()
{
    txt.setPos(sf::Vector2f(pGraf->getCentro().x - txt.getTamanho().x / 2.0f, pGraf->getCentro().y - txt.getTamanho().y));
}

void Menu::MenuSalvarPontuacao::criarBotoes() 
{
    float posX = pGraf->getCentro().x - tamBotoes.x / 2.0f;
    float posY = pGraf->getCentro().y;

    adicionarBotao("SALVAR", sf::Vector2f(posX, posY), TipoBotao::CONFIRMAR);
    adicionarBotao("VOLTAR", sf::Vector2f(posX, posY + tamBotoes.y * 1.2f), TipoBotao::VOLTAR);
    inicializarBotoes();
}

void Menu::MenuSalvarPontuacao::adicionarCaracter(char c)
{
    string nome;
    nome = txt.getInfo();
    if(nome.length() < 10)
    {
        nome += c;
        cout << nome.size() << endl;
        txt.setInfo(nome);
        alinharTexto();
    }
}

void Menu::MenuSalvarPontuacao::removerCaracter()
{
    string nome = txt.getInfo();
    if(nome.size() > 0)
    {
        nome.pop_back();
        txt.setInfo(nome);
        alinharTexto();
    }
}

void Menu::MenuSalvarPontuacao::salvarColocacao()
{
    string nome = txt.getInfo();
    if(nome.size() == 0)
    {
        nome = "SEM NOME";
    }
    string pontos = pontuacao.getInfo().substr(11, pontuacao.getInfo().length());
    string linha = nome + " " + pontos;
    gArquivo.gravarCont("../resources/leaderboard.txt", linha);
}

void Menu::MenuSalvarPontuacao::selecionar(TipoBotao tipo)
{
    if(ativo)
    {
        switch(tipo)
        {
            case TipoBotao::CONFIRMAR:
            {
                salvarColocacao();
                setAtivo(false);
                remover = true;
                break;
            }

            case TipoBotao::VOLTAR:
            {
                setAtivo(false);
                remover = true;
                break;
            }
        }
    }
}

void Menu::MenuSalvarPontuacao::executar()
{
    fase->desenhar();
    pGraf->desenhar(background);
    setAtivo(true);
    pGraf->desenhar(painel);
    txt.desenhar();
    desenhar();
}
